#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "get_next_line.h"
# include "./mlx/mlx.h"
# include "./libft/libft.h"

# define ROTATE_LEFT	123
# define ROTATE_RIGHT	124
# define FORWARD_W_Z	13
# define BACK_S_S		1
# define RIGHT_D_D		2
# define LEFT_A_Q		0
# define ESCAPE_E       53

typedef struct s_img
{
	void		*img;
	int		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
    int         width;
	int         height;
    void        *img2;
    int		*addr2;
}				t_img;

typedef struct		s_sprxy
{
	double			x;
	double			y;
}					t_sprxy;

typedef struct		s_sprite
{
	int				numSprites;
	int				*order;
	double			*dist;
	double			spriteX;
	double			spriteY;
	double			invDet;
	double			transformX;
	double			transformY;
	int				spritescreenX;
	int				spriteHeight;
	int				drawStartX;
	int				drawStartY;
	int				drawEndY;
	int				drawEndX;
	int				spriteWidth;
	double			*zBuffer;
}					t_sprite;

typedef struct		s_texture
{
	int				texDir;
	double			wallX;
	int				texX;
	int				texY;
	double			step;
	double			texPos;
}					t_texture;

typedef struct s_ray
{
    double      posX;
    double      posY;
    double      cameraX;
    int         x;
    double      dirX;
    double      dirY;
	double		rayDirX;
	double		rayDirY;
	double		planeX;
	double		planeY;
    double      time;
    double      oldTime;
    int         drawstart;
	int         drawend;
    //which box of the map we're in
    int         mapX;
    int         mapY;
    //length of ray from current position to next x or y-side
    double      sideDistX;
    double      sideDistY;
    int         lineheight;
    //length of ray from one x or y-side to next x or y-side
    double      deltaDistX;
    double      deltaDistY;
    double      perpWallDist;
    //what direction to step in x or y-direction (either +1 or -1)
    int         stepX;
    int         stepY;
    int         hit; //was there a wall hit?
    int         side; //0 = NS(x-side) or 1 = EW(y-side) wall
    //movement
    int         forward;
	int         back;
	int         left;
	int         right;
    int         rotate_left;
    int         rotate_right;
    //frame
    double      moveSpeed;
	double      rotSpeed;
}				t_ray;

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
    int         screen_width;
    int         screen_height;
	char		**map;
    int         save;
	t_img		img;
	t_img		texture[5];
    t_ray       ray;
    t_point     *player;
    t_texture   t;
    t_sprite    s;
    t_sprxy     *sxy;
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

int		check_valid_cub(int ac, const char **av, t_cub *cub);
int		split_file(char *file, t_cub *cub);
void	parse_param(char *line, t_cub *cub);
char	*get_resolution(char *line, size_t *j, t_cub *cub);
char	*get_rgb(char *line, size_t *j, int nb, t_cub *cub);
char	*get_path(char *line, t_cub *cub, char *path);
int		parse_map(t_cub* cub, char **map);
t_point	*spread_map(t_cub *cub, char **map, t_point *stack, t_point *visited);
t_point	*find_player(char **map, t_point *player);

int		create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

int		ft_exit(t_cub *cub);
int		ft_key_press(int keycode, t_cub *cub);
int		ft_key_release(int keycode, t_cub *cub);
int		ft_color_column(t_cub *cub);
void	ft_draw_texture(t_cub *cub, int x, int y);

void	ft_init2(t_cub *cub);
void    ft_init(t_cub *cub);
void	ft_init_sprite(t_cub *cub);
void	ft_init_texture(t_cub *cub);

void	ft_forward_back(t_cub *cub);
void	ft_left_right(t_cub *cub);
void	ft_rotate_right_left(t_cub *cub);

void	ft_get_texture_adress(t_cub *cub);
void	ft_get_texture(t_cub *cub);
int		ft_raycasting(t_cub *cub);
int		ft_mlx(t_cub *cub);

void	ft_stepsidedist(t_cub *cub);
void	ft_incrementray(t_cub *cub);
void	ft_drawstartend(t_cub *cub);

void	ft_sprite(t_cub *cub);

void	ft_header(t_cub *cub, int fd);
void	ft_save(t_cub *cub);
void	ft_error(t_cub *cub, char *str);

#endif
