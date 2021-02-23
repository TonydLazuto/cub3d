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

typedef struct		s_coor
{
	size_t			x;
    size_t          y;
    char            val;
    struct s_coor   *next;          
}                   t_coor;

typedef struct		s_ptr
{
	void			*mlx;
    void			*win;
}                   t_ptr;

typedef struct      s_data
{
    void            *img;
    char            *addr;
    int             bits_per_pixel;
    int             line_length;
    int             endian;
}                   t_data;

void	ft_free(char **s);
char	*my_strjoin(char *s1, char *s2);
char	*strjoinfree(char *s1, char *s2);
int		skip_space(char *line, unsigned int i);
char	*trim_line(char *line);
int		get_col_player(char *line, char player);

int     check_valid_cub(int ac, const char **av, t_cub *cub, t_ptr ptr);
int		split_params_map(char *file, t_cub *cub, t_ptr ptr);
int     parse_param(char *line, t_cub *cub);
char    *get_resolution(char *line, size_t *j, t_cub *cub);
char    *get_rgb(char *line, size_t *j, int nb);
char    *get_path(char *line, size_t *j);
int     parse_map(char **map, size_t len_map);

int     create_trgb(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void	draw(t_ptr ptr, int i, int color);

void	draw_sprite(t_data *img, int color);
void	draw_wall(t_data *img, int color);
void	draw_pers(t_data *img, int color);

#endif