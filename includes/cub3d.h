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

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif

# ifndef PI
#  define PI 3.14
# endif

# ifndef FOV
#  define FOV PI/3
# endif

# ifndef STEP
#  define STEP 0.01
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"

typedef struct			s_vector2 {
	float				x;
	float				y;
}						t_vector2;

typedef struct			s_data {
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_data;

typedef struct			s_drawconfig
{
	t_vector2			texture_get;
	t_vector2			texture_wh;
	t_data				*texture;
}						t_drawconfig;

typedef struct			s_player
{
	float				x;
	float				y;
	float				alpha;
}						t_player;

typedef struct			s_color
{
	int					red;
	int					green;
	int					blue;
}						t_color;

typedef struct			s_mapstruct
{
	int					rate_width;
	int					rate_height;
	char				*no_texture;
	char				*so_texture;
	char				*we_texture;
	char				*ea_texture;
	char				*sprite_texture;
	t_color				floor_color;
	t_color				ceilling_color;
}						t_mapstruct;

typedef struct			s_map
{
	char				**map;
	int					is_map_valid;
	int					map_width;
	int					map_height;
	t_player			player;
	t_mapstruct			mapstruct;
}						t_map;

typedef struct			s_vars {
	void				*mlx;
	void				*win;
	t_map				*map;
	t_data				*img;
	t_data				*no_texture;
	t_data				*so_texture;
	t_data				*we_texture;
	t_data				*ea_texture;
	t_data				*sprite_texture;
	t_vector2			no_texture_wh;
	t_vector2			so_texture_wh;
	t_vector2			we_texture_wh;
	t_vector2			ea_texture_wh;
	t_vector2			sprite_texture_wh;
	t_vector2			wall_xy;
	t_list				*sprite_list;
}						t_vars;

void					sprite_error(void);
int						load_so_no(t_vars *vars);
int						load_we_ea(t_vars *vars);
int						load_sprite(t_vars *vars);
void					make_screenshot(t_vars *vars);
int						is_collision_detected(float delta_x,
float delta_y, t_map *map);
int						get_sprite_screensize(float sprite_dist, t_vars *vars);
void					draw_sprite_rect(int x, t_vector2 size, t_vars *vars,
int sprite_screen_size);
void					print_position(void *content);
int						draw_sprite(t_list *sprite_list,
t_vars *vars, float dist[]);
t_list					*init_spritelist(t_vars *vars);
t_vector2				get_sprite_size(t_vars *vars, t_vector2 *config,
int sprite_screen_size);
int						check_angular(t_vector2 *wall_xy, t_map *map);
int						draw_walls(t_vars *vars, int i, int last, float dist);
void					init_drawconfig(t_vars *vars, t_drawconfig *drawconfig,
int pole, t_vector2 vector);
int						get_wall_pole(t_vector2 vector_pos,
t_map *map, int last);
float					get_distance(t_map *map,
t_vector2 *wall_xy, float alpha);
float					get_wall_width(float **wall, t_vector2 *wall_xy,
t_map *map, int i);
unsigned int			my_mlx_pixel_get(t_data *data, int x, int y);
void					draw_world(t_map *map, t_vars *vars);
void					render_player(t_map *map, t_data *img, t_vector2 wh);
void					render(t_vars *vars);
int						is_wall(char c);
void					turn_down(t_map *map, float delta);
void					turn_up(t_map *map, float delta);
void					turn_right(t_map *map, float delta);
void					turn_left(t_map *map, float delta);
void					hook_keys(t_vars *vars);
void					render_map(t_map *map, t_data *img, t_vector2 wh);
void					draw_back(t_map *map, t_data *img);
void					draw_map(t_data *img, t_map *map);
int						create_trgb(int t, int r, int g, int b);
void					my_mlx_pixel_put(t_data *data, int x, int y, int color);
void					create(t_map *map, int is_screenshot);
int						skip_map_struct(int fd, char *line);
void					check_valid_end(char *line, t_map *map, int res);
void					catch_maperror();
int						is_a_player(char c);
int						is_an_object(char c);
int						is_line_valid(char *line);
int						is_valid_arg(char c);
int						is_right_arg(char c);
void					free_map(t_map *map);
void					catch_params(t_map *map, t_mapstruct conf, char *line);
void					line_copy(char **src, char *dst, int width);
void					skip_to_map(int parameters_h, int fd);
int						is_valid_structure(t_map *map);
int						parse_r(t_map *map, char *line);
char					*get_texture(char *line);
t_color					get_color(char *line);
void					catch_error();
int						is_map_valid(t_map *map);
int						read_file(t_map *map, char *path);
int						get_next_line(int fd, char **line);
void					*ft_strdup(const char *source);
char					*ft_strrchr(const char *str, int ch);
char					*ft_substr(char const *s,
unsigned int start, size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
size_t					ft_strlen(const char *str);
#endif
