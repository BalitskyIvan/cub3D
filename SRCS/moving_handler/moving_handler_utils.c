/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_handler_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 11:15:08 by lmallado          #+#    #+#             */
/*   Updated: 2020/08/19 11:15:09 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	turn_left(t_map *map, float delta)
{
	if (map->player.x + delta * cos(map->player.alpha - PI / 2) < map->map_width - 1 &&
		map->player.y + delta * sin(map->player.alpha - PI / 2) < map->map_height - 1 &&
		map->player.x + delta * cos(map->player.alpha - PI / 2) >= 0 &&
		map->player.y + delta * sin(map->player.alpha - PI / 2) >= 0)
	{
		if (!is_wall(map->map[(int) (map->player.y + delta * sin(map->player.alpha - PI / 2))]
			[(int) (map->player.x + delta * cos(map->player.alpha - PI / 2))]))
		{
			map->player.x += delta * cos(map->player.alpha - PI / 2);
			map->player.y += delta * sin(map->player.alpha - PI / 2);
		}
	}
}

void	turn_right(t_map *map, float delta)
{
	if (map->player.x + delta * cos(map->player.alpha + PI / 2) < map->map_width - 1 &&
		map->player.y + delta * sin(map->player.alpha + PI / 2) < map->map_height - 1 &&
		map->player.x + delta * cos(map->player.alpha + PI / 2) >= 0 &&
		map->player.y + delta * sin(map->player.alpha + PI / 2) >= 0)
	{
		if (!is_wall(map->map[(int) (map->player.y + delta * sin(map->player.alpha + PI / 2))]
			[(int) (map->player.x + delta * cos(map->player.alpha + PI / 2))]))
		{
			map->player.x += delta * cos(map->player.alpha + PI / 2);
			map->player.y += delta * sin(map->player.alpha + PI / 2);
		}
	}
}

void	turn_up(t_map *map, float delta)
{
	if (map->player.x + delta * cos(map->player.alpha) < map->map_width - 1 &&
		map->player.y + delta * sin(map->player.alpha) < map->map_height - 1 &&
		map->player.x + delta * cos(map->player.alpha) >= 0 &&
		map->player.y + delta * sin(map->player.alpha) >= 0)
	{
		if (!is_wall(map->map[(int) (map->player.y + delta * sin(map->player.alpha))]
			[(int) (map->player.x + delta * cos(map->player.alpha))]))
		{
			map->player.x += delta * cos(map->player.alpha);
			map->player.y += delta * sin(map->player.alpha);
		}
	}
}

void	turn_down(t_map *map, float delta)
{
	if (map->player.x - delta * cos(map->player.alpha) < map->map_width - 1 &&
		map->player.y - delta * sin(map->player.alpha) < map->map_height - 1 &&
		map->player.x - delta * cos(map->player.alpha) >= 0 &&
		map->player.y - delta * sin(map->player.alpha) >= 0)
	{
		if (!is_wall(map->map[(int) (map->player.y - delta * sin(map->player.alpha))]
			[(int) (map->player.x - delta * cos(map->player.alpha))]))
		{
			map->player.x -= delta * cos(map->player.alpha);
			map->player.y -= delta * sin(map->player.alpha);
		}
	}
}