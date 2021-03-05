/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 18:15:33 by lmallado          #+#    #+#             */
/*   Updated: 2020/08/09 18:15:47 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int		is_valid_structure(t_map *map)
{
	if (map->map_height > 0 && map->map_width > 0 &&
		map->mapstruct.rate_height > 0 && map->mapstruct.rate_width > 0 &&
		map->mapstruct.ea_texture != NULL &&
		map->mapstruct.no_texture != NULL &&
		map->mapstruct.so_texture != NULL &&
		map->mapstruct.we_texture != NULL &&
		map->mapstruct.sprite_texture != NULL &&
		map->mapstruct.floor_color.red > -1 &&
		map->mapstruct.floor_color.green > -1 &&
		map->mapstruct.floor_color.blue > -1 &&
		map->mapstruct.ceilling_color.red > -1 &&
		map->mapstruct.ceilling_color.green > -1 &&
		map->mapstruct.ceilling_color.blue > -1
		&& map->map != NULL && map->is_map_valid == 1)
		return (1);
	else
		return (0);
}

void	line_copy(char **src, char *dst, int width)
{
	int i;

	i = 0;
	while (dst[i])
	{
		(*src)[i] = dst[i];
		i++;
	}
	while (i < width)
	{
		(*src)[i] = ' ';
		i++;
	}
	(*src)[i] = '\0';
}

void	skip_to_map(int parameters_h, int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (i < parameters_h)
	{
		get_next_line(fd, &line);
		free(line);
		i++;
	}
}

int		is_line_valid(char *line)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (line[i] == ' ')
	{
		flag = 1;
		i++;
	}
	if ((is_right_arg(line[i]) || line[i] == '\0') && (flag == 1 || (i == 0 &&
	line[i] != '\0')))
		return (1);
	else
		return (0);
}
