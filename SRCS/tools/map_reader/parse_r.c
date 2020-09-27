/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 17:43:49 by lmallado          #+#    #+#             */
/*   Updated: 2020/08/16 17:43:51 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

static int	split_whitespace(char *line, int i)
{
	while (line[i] == ' ')
		i++;
	while (is_number(line[i]) && line[i])
		i++;
	while (line[i] == ' ')
		i++;
	return (i);
}

static void	check_resolution(char end_sym, int *width, int *height)
{
	if (end_sym != '\0' || *(width) < 1 ||
	*(height) < 1)
	{
		*(width) = -2;
		*(height) = -2;
	}
	if (*(width) > 2560)
		*(width) = 2560;
	if (*(height) > 1440)
		*(height) = 1440;
}

int			parse_r(t_map *map, char *line)
{
	int i;

	i = 1;
	if (map->mapstruct.rate_width != -1 ||
		map->mapstruct.rate_height != -1 || line[i] != ' ')
	{
		map->mapstruct.rate_width = -2;
		map->mapstruct.rate_height = -2;
		return (0);
	}
	while (line[i] == ' ' && line[i])
		i++;
	map->mapstruct.rate_width = ft_atoi(line + i);
	while (is_number(line[i]) && line[i])
		i++;
	map->mapstruct.rate_height = ft_atoi(line + i);
	i = split_whitespace(line, i);
	check_resolution(line[i], &map->mapstruct.rate_width,
	&map->mapstruct.rate_height);
	return (1);
}
