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

static int	is_valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == '2')
		return (1);
	else
		return (0);
}

static int	is_sym_closed(char **map, int x, int y, int max_width, int max_height)
{
	if (x == 0 || y == 0 || x == max_width || y == max_height)
		return (0);
	if (is_valid_char(map[y][x + 1]) && is_valid_char(map[y][x - 1]) &&
		is_valid_char(map[y + 1][x]) && is_valid_char(map[y - 1][x]))
		return (1);
	return (0);
}

int is_map_valid(t_map *map)
{
	int x;
	int y;
	
	y = 0;
	while (y < map->map_height)
	{
		x = 0;
		while(x < map->map_width)
		{
			if (map->map[y][x] == '0' || map->map[y][x] == '2' || map->map[y][x] == 'N')
			{
				if (!is_sym_closed(map->map, x, y, map->map_width, map->map_height))
					return (0);
				if (map->map[y][x] == 'N')
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
			x++;
		}
		y++;
	}
	if (map->player.x == -1)
		return (0);
	else
		return (1);
}
