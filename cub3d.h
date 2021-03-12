#ifndef FT_CUB3D_H
# define FT_CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include "./gnl/get_next_line.h"
# include "./mlx/mlx.h"
# include "./libft/libft.h"

typedef struct      s_cub
{
    int             width;
    int             height;
    char            *north_path;
    char            *south_path;
    char            *west_path;
    char            *east_path;
    char            *sprite_path;
    int             floor;
    int             ceiling;
    char            **map;
}                   t_cub;

typedef struct		s_point
{
	int             x;
    int             y;
    char            val;
    struct s_point   *next;         
}                   t_point;

typedef struct		s_ptr
{
	void			*mlx;
    void			*win;
}                   t_ptr;

typedef struct		s_dir_plane
{
	double          dirX;
    double          dirY;
    double          planeX;
    double          planeY;
}                   t_dir_plane;

typedef struct      s_data
{
    void            *img;
    char            *addr;
    int             bits_per_pixel;
    int             line_length;
    int             endian;
}                   t_data;

void	ft_free(char **s);
char	*strjoinfree(char *s1, char *s2);
int		skip_space(char *line, unsigned int i);
char	*trim_line(char *line);
int     is_in_charset(char c, char const *set);

int     is_empty_lst(t_point *point);
t_point *new_point(int x, int y, char val);
void    push_back_point(t_point **list, t_point *elet);
t_point *last_point(t_point *point);
void    pop_front_point(t_point **lst);
void    clear_points(t_point **point);
int     is_point_in_list(t_point *lstpoint, t_point *point);

void        print_points(t_point *point);

int     check_valid_cub(int ac, const char **av, t_cub *cub, t_ptr ptr);
int		split_file(char *file, t_cub *cub, t_ptr ptr);
int     parse_param(char *line, t_cub *cub);
char    *get_resolution(char *line, size_t *j, t_cub *cub);
char    *get_rgb(char *line, size_t *j, int nb);
char    *get_path(char *line, size_t *j);
int     parse_map(char **map);
t_point *spread_map(char **map, t_point *stack, t_point *visited);
t_point *find_player(char **map, t_point *player);

int     create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

t_data  draw_square(int x, int y, t_data img, int color);
void	draw(t_ptr ptr, t_cub cub, t_point *map_points);
/*
void	draw_sprite(t_data *img, int color);
void	draw_wall(t_data *img, int color);
void	draw_pers(t_data *img, int color);
*/
#endif