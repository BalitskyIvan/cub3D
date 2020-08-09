/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 10:40:19 by lmallado          #+#    #+#             */
/*   Updated: 2020/08/09 10:40:21 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static void free_map(t_map *map)
{
	int i;
	
	i = 0;
	while (i < map->map_height - 1){
		free(map->map[i]);
	}
	free(map->map);
}

static int get_map_line_size(char *path, t_map *map)
{
	int		fd;
	char	*line;
	int		i;
	int		size;
	
	line = NULL;
	map->map_height = 1;
	map->map_width = 0;
	fd = open(path, O_RDONLY);
	catch_error();
	i = 0;
	size = 0;
	while(get_next_line(fd, &line) == 1)
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '1')
			break;
		size++;
	}
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_strlen(line) > map->map_width)
			map->map_width = ft_strlen(line);
		free(line);
		map->map_height++;
	}
	catch_error();
	map->map_height++;
	free(line);
	close(fd);
	return (size);
}

static int	read_map(t_map *map, char *path)
{
	int	i;
	char *line;
	int	res;
	int	fd;
	
	fd = open(path, O_RDONLY);
	skip_to_map(get_map_line_size(path, map), fd);
	map->map = (char **)malloc(sizeof(char *) * (map->map_height + 1));
	i = 0;
	while ((res = get_next_line(fd, &line)))
	{
		map->map[i] = (char *)malloc(map->map_width + 1);
		line_copy(&map->map[i], line, map->map_width);
		free(line);
		i++;
	}
	if (res == -1)
		free_map(map);
	catch_error();
	map->map[i] = (char *)malloc(map->map_width + 1);
	line_copy(&map->map[i], line, map->map_width);
	free(line);
	close(fd);
	return (1);
}

int		read_file(t_map *map, char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	catch_error();
	while (get_next_line(fd, &line))
	{
		if(ft_strlen(line) > 2)
		{
			if (line[0] == 'R')
				parse_r(map, line);
			if (line[0] == 'N' && line[1] == 'O')
				map->mapstruct.no_texture = get_texture(line);
			if (line[0] == 'S' && line[1] == 'O')
				map->mapstruct.so_texture = get_texture(line);
			if (line[0] == 'W' && line[1] == 'E')
				map->mapstruct.we_texture = get_texture(line);
			if (line[0] == 'E' && line[1] == 'A')
				map->mapstruct.ea_texture = get_texture(line);
			if (line[0] == 'S' && line[1] == ' ')
				map->mapstruct.sprite_texture = get_texture(line);
			if (line[0] == 'F' && line[1] == ' ')
				map->mapstruct.floor_color = get_color(line);
			if (line[0] == 'C' && line[1] == ' ')
				map->mapstruct.ceilling_color = get_color(line);
		}
		free(line);
	}
	free(line);
	close(fd);
	//read_map(map, path);
	return (is_valid_structure(map));
}