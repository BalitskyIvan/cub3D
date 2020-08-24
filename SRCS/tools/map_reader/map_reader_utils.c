/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 15:35:36 by lmallado          #+#    #+#             */
/*   Updated: 2020/08/09 15:35:38 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int	is_already_exist(char *line, t_mapstruct conf)
{
	if (line[0] == 'N' && line[1] == 'O' && conf.no_texture != NULL)
		return (1);
	if (line[0] == 'S' && line[1] == 'O' && conf.so_texture != NULL)
		return (1);
	if (line[0] == 'W' && line[1] == 'E' && conf.we_texture != NULL)
		return (1);
	if (line[0] == 'E' && line[1] == 'A' && conf.ea_texture != NULL)
		return (1);
	if (line[0] == 'S' && line[1] == ' ' && conf.sprite_texture != NULL)
		return (1);
	if (line[0] == 'F' && line[1] == ' ' && conf.floor_color.red > -1)
		return (1);
	if (line[0] == 'C' && line[1] == ' ' && conf.ceilling_color.red > -1)
		return (1);
	return (0);
}

void		catch_params(t_map *map, t_mapstruct conf, char *line)
{
	if (is_already_exist(line, conf) == 1)
		map->is_map_valid = 0;
	if (line[0] == 'R')
		parse_r(map, line);
	if (line[0] == 'N' && line[1] == 'O')
		map->mapstruct.no_texture = get_texture(line, conf.no_texture);
	if (line[0] == 'S' && line[1] == 'O')
		map->mapstruct.so_texture = get_texture(line, conf.so_texture);
	if (line[0] == 'W' && line[1] == 'E')
		map->mapstruct.we_texture = get_texture(line, conf.we_texture);
	if (line[0] == 'E' && line[1] == 'A')
		map->mapstruct.ea_texture = get_texture(line, conf.ea_texture);
	if (line[0] == 'S' && line[1] == ' ')
		map->mapstruct.sprite_texture = get_texture(line, conf.sprite_texture);
	if (line[0] == 'F' && line[1] == ' ')
		map->mapstruct.floor_color = get_color(line);
	if (line[0] == 'C' && line[1] == ' ')
		map->mapstruct.ceilling_color = get_color(line);
	if (!is_already_exist(line, map->mapstruct) && line[0] != 'R' &&
		!is_line_valid(line) && ft_strlen(line) != 0)
		map->is_map_valid = 0;
}

int			skip_map_struct(int fd, char *line)
{
	int	i;
	int	size;

	size = 0;
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '1')
			break ;
		size++;
	}
	return (size);
}

void		check_valid_end(char *line, t_map *map, int fd)
{
	if (is_line_valid(line))
	{
		if (ft_strlen(line) > map->map_width)
			map->map_width = ft_strlen(line);
		catch_error();
		map->map_height++;
	}
	else
	{
		while (get_next_line(fd, &line) == 1)
		{
			if (is_line_valid(line))
			{
				map->map_width = 0;
				map->map_height = 0;
			}
			free(line);
		}
		if (is_line_valid(line))
		{
			map->map_width = 0;
			map->map_height = 0;
		}
	}
}

void		free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->map_height - 1)
	{
		free(map->map[i]);
	}
	free(map->map);
}
