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

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include "../libft/libft.h"

typedef struct		s_player
{
	float			x;
	float			y;
	float			alpha;
}					t_player;

typedef struct 		s_color
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
}				t_mapstruct;

typedef struct		s_map
{
	char			**map;
	int				map_width;
	int				map_height;
	t_player		player;
	t_mapstruct		mapstruct;
}					t_map;

void	line_copy(char **src, char *dst, int width);
void	skip_to_map(int parameters_h, int fd);
int		is_valid_structure(t_map *map);
void	parse_r(t_map *map, char *line);
char	*get_texture(char *line);
t_color	get_color(char *line);
void		catch_error();
int		is_map_valid(t_map *map);
int		read_file(t_map *map, char *path);
int		get_next_line(int fd, char **line);
void	*ft_strdup(const char *source);
char	*ft_strrchr(const char *str, int ch);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
#endif