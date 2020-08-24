/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 10:23:22 by lmallado          #+#    #+#             */
/*   Updated: 2020/08/09 10:23:25 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

# ifndef PI
#  define PI 3.14
# endif

# ifndef FOV
#  define FOV PI/3
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"


typedef struct	s_vector2 {
	float		x;
	float		y;
}				t_vector2;

typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct		s_player
{
	float			x;
	float			y;
	float			alpha;
}					t_player;

typedef struct		s_color
{
	int				red;
	int				green;
	int				blue;
}					t_color;

typedef struct		s_mapstruct
{
	int				rate_width;
	int				rate_height;
	char			*no_texture;
	char			*so_texture;
	char			*we_texture;
	char			*ea_texture;
	char			*sprite_texture;
	t_color			floor_color;
	t_color			ceilling_color;
}					t_mapstruct;

typedef struct		s_map
{
	char			**map;
	int				is_map_valid;
	int				map_width;
	int				map_height;
	t_player		player;
	t_mapstruct		mapstruct;
}					t_map;

typedef struct		s_vars {
		void		*mlx;
		void		*win;
		t_map		*map;
		t_data		*img;
		t_data		*no_texture;
		t_data		*so_texture;
		t_data		*we_texture;
		t_data		*ea_texture;
		t_data		*sprite_texture;
		t_vector2	no_texture_wh;
		t_vector2	so_texture_wh;
		t_vector2	we_texture_wh;
		t_vector2	ea_texture_wh;
		t_vector2	sprite_texture_wh;
}					t_vars;

float			get_distance(t_map *map, t_vector2 *wall_xy, float ration, float alpha);
float			get_wall_width(float **wall, t_vector2 *wall_xy, t_map *map, int i);
unsigned int	my_mlx_pixel_get(t_data *data, int x, int y);
void			draw_world(t_data *img, t_map *map, t_vars *vars);
void			render_player(t_map *map, t_data *img, t_vector2 wh);
void			render(t_vars *vars);
void			turn_down(t_map *map, float delta);
void			turn_up(t_map *map, float delta);
void			turn_right(t_map *map, float delta);
void			turn_left(t_map *map, float delta);
void			hook_keys(t_vars *vars);
void			render_map(t_map *map, t_data *img, t_vector2 wh);
void			draw_back(t_map *map, t_data *img);
void			draw_map(t_data *img, t_map *map);
int				create_trgb(int t, int r, int g, int b);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			create(t_map *map);
int				skip_map_struct(int fd, char *line);
void			check_valid_end(char *line, t_map *map, int fd);
void			catch_maperror();
int				is_a_player(char c);
int				is_an_object(char c);
int				is_line_valid(char *line);
int				is_valid_arg(char c);
int				is_right_arg(char c);
void			free_map(t_map *map);
void			catch_params(t_map *map, t_mapstruct conf, char *line);
void			line_copy(char **src, char *dst, int width);
void			skip_to_map(int parameters_h, int fd);
int				is_valid_structure(t_map *map);
int				parse_r(t_map *map, char *line);
char			*get_texture(char *line, char *now);
t_color			get_color(char *line);
void			catch_error();
int				is_map_valid(t_map *map);
int				read_file(t_map *map, char *path);
int				get_next_line(int fd, char **line);
void			*ft_strdup(const char *source);
char			*ft_strrchr(const char *str, int ch);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *str);
#endif