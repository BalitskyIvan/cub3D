/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 12:43:29 by lmallado          #+#    #+#             */
/*   Updated: 2020/08/09 12:43:30 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int	is_sym_closed(char **map, int x, int y, t_map *mapconf)
{
	if (x == 0 || y == 0 || x == mapconf->map_width ||
		y == mapconf->map_height - 1)
		return (0);
	if (is_right_arg(map[y][x + 1]) && is_right_arg(map[y][x - 1]) &&
		is_right_arg(map[y + 1][x]) && is_right_arg(map[y - 1][x]))
		return (1);
	return (0);
}

static int	check(t_map *map, int x, int y)
{
	if (!is_valid_arg(map->map[y][x]))
		return (0);
	if (is_an_object(map->map[y][x]))
	{
		if (!is_sym_closed(map->map, x, y, map))
			return (0);
		if (is_a_player(map->map[y][x]))
		{
			if (map->player.x != -1)
				return (0);
			else
			{
				map->player.x = x;
				map->player.y = y;
			}
		}
	}
	return (1);
}

int			is_map_valid(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->map_height - 1)
	{
		x = 0;
		while (x < map->map_width)
		{
			if (!check(map, x, y))
				return (0);
			x++;
		}
		y++;
	}
	if (map->player.x == -1)
		return (0);
	else
		return (1);
}
