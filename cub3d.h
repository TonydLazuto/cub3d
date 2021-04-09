#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "./gnl/get_next_line.h"
# include "./mlx/mlx.h"
# include "./libft/libft.h"
# define PI 3.1415926535

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_data
{
    double      posX;
    double      posY;
	double		rayDirX;
	double		rayDirY;
	double		planeX;
	double		planeY;
    double      time;
    double      old_time;
    //length of ray from current position to next x or y-side
    double      sideDistX;
    double      sideDistY;
    //length of ray from one x or y-side to next x or y-side
    double      deltaDistX;
    double      deltaDistY;
    double      perpWallDist;
    //what direction to step in x or y-direction (either +1 or -1)
    int         stepX;
    int         stepY;
    int         hit; //was there a wall hit?
    int         side; //was a NS or a EW wall hit?
    //try out
    double      pdx;
    double      pdy;
    double      pa;
}				t_data;

typedef struct s_point
{
	int				x;
	int				y;
	char			val;
	struct s_point	*next;
}					t_point;

typedef struct s_cub
{
	int			width;
	int			height;
    char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*sprite;
	int			floor;
	int			ceiling;
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	t_img		img;
    t_data      data;
    t_point     *map_point;
}				t_cub;

void	ft_free(char **s);
char	*strjoinfree(char *s1, char *s2);
int		skip_space(char *line, unsigned int i);
char	*trim_line(char *line);
int		is_in_charset(char c, char const *set);

int		is_empty_lst(t_point *point);
t_point	*new_point(int x, int y, char val);
void	push_back_point(t_point **list, t_point *elet);
t_point	*last_point(t_point *point);
void	pop_front_point(t_point **lst);
void	clear_points(t_point **point);
int		is_point_in_list(t_point *lstpoint, t_point *point);

void	print_points(t_point *point);

int		check_valid_cub(int ac, const char **av, t_cub *cub);
int		split_file(char *file, t_cub *cub);
int		parse_param(char *line, t_cub *cub);
char	*get_resolution(char *line, size_t *j, t_cub *cub);
char	*get_rgb(char *line, size_t *j, int nb);
char	*get_path(char *line, size_t *j);
int		parse_map(char **map);
t_point	*spread_map(char **map, t_point *stack, t_point *visited);
t_point	*find_player(char **map, t_point *player);

int		create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

void    draw_map(t_cub *cub);

#endif