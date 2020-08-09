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

void parse_r(t_map *map, char *line)
{
	int i;

	i = 1;
	while (line[i] == ' ')
		i++;
	map->mapstruct.rate_width = ft_atoi(line + i);
	while (line[i] != ' ' && line[i])
		i++;
	map->mapstruct.rate_height = ft_atoi(line + i);
}

char *get_texture(char *line)
{
	int i;

	i = 2;
	while (line[i] == ' ')
		i++;
	if (line[i])
		return (line + i);
	else
		return (NULL);
}

t_color get_color(char *line)
{
	int i;
	t_color color;

	i = 1;
	while (line[i] == ' ')
		i++;
	color.red = ft_atoi(line + i);
	while (line[i] != ',' && line[i])
		i++;
	i++;
	color.green = ft_atoi(line + i);
	while (line[i] != ',' && line[i])
		i++;
	i++;
	color.blue = ft_atoi(line + i);
	return (color);
}

void	skip_to_map(int parameters_h, int fd)
{
	int i;
	char *line;
	
	i = 0;
	while (i < parameters_h){
		get_next_line(fd, &line);
		free(line);
	}
}
