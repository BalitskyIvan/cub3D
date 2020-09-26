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

static int	get_map_line_size(char *path, t_map *map)
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
	size = skip_map_struct(fd, line);
	while (get_next_line(fd, &line) == 1)
	{
		if (!is_line_valid(line))
			break ;
		if (ft_strlen(line) > map->map_width)
			map->map_width = ft_strlen(line);
		free(line);
		map->map_height++;
	}
	check_valid_end(line, map, fd);
	free(line);
	close(fd);
	return (size);
}

static int	read_map(t_map *map, char *path)
{
	int		i;
	char	*line;
	int		res;
	int		fd;

	fd = open(path, O_RDONLY);
	skip_to_map(get_map_line_size(path, map), fd);
	map->map = (char **)malloc(sizeof(char *) * (map->map_height + 1));
	i = 0;
	while ((res = get_next_line(fd, &line)) && i < map->map_height - 1)
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

static int	is_file_valid(char *path)
{
	int	i;

	i = 0;
	while (path[i] != '.' && path[i])
		i++;
	if (path[i] == '.' &&
		path[i + 1] == 'c' &&
		path[i + 2] == 'u' &&
		path[i + 3] == 'b' &&
		path[i + 4] == '\0')
		return (1);
	return (0);
}

int			read_file(t_map *map, char *path)
{
	int		fd;
	char	*line;

	if (!is_file_valid(path))
		return (0);
	fd = open(path, O_RDONLY);
	catch_error();
	while (get_next_line(fd, &line))
	{
		if (ft_strlen(line) > 2)
			catch_params(map, map->mapstruct, line); 
		free(line);
	}
	catch_params(map, map->mapstruct, line);
	free(line);
	close(fd);
	read_map(map, path);
	return (is_valid_structure(map));
}
