/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pole_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 19:00:46 by lmallado          #+#    #+#             */
/*   Updated: 2020/08/30 19:00:48 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	search_no_wall(t_map *map, t_vector2 vector_pos, int last)
{
	if ((map->map[(int)(vector_pos.y - STEP)][(int)vector_pos.x] == '1' &&
	map->map[(int)(vector_pos.y + STEP)][(int)(vector_pos.x + STEP)] == '1' &&
	last == 0) ||
	(map->map[(int)(vector_pos.y - STEP)][(int)vector_pos.x] == '1' &&
	map->map[(int)(vector_pos.y + STEP)][(int)(vector_pos.x - STEP)] == '1' &&
	(last == 2 || last == 0)) ||
	(map->map[(int)(vector_pos.y - STEP)][(int)vector_pos.x] == '1' &&
	is_an_object(map->map[(int)(vector_pos.y - STEP)]
	[(int)(vector_pos.x + STEP)]) &&
	is_an_object(map->map[(int)(vector_pos.y + STEP)]
	[(int)(vector_pos.x + STEP)]) &&
	last == 0) ||
	(map->map[(int)(vector_pos.y - STEP)][(int)vector_pos.x] == '1' &&
	is_an_object(map->map[(int)(vector_pos.y - STEP)]
	[(int)(vector_pos.x - STEP)]) &&
	is_an_object(map->map[(int)(vector_pos.y + STEP)]
	[(int)(vector_pos.x - STEP)]) &&
	(last == 0 || last == 2)))
		return (1);
	return (0);
}

static int	search_ea_wall(t_map *map, t_vector2 vector_pos, int last)
{
	if ((map->map[(int)vector_pos.y][(int)(vector_pos.x - STEP)] == '1' &&
	map->map[(int)(vector_pos.y - STEP)][(int)(vector_pos.x + STEP)] == '1' &&
	last == 2) ||
	(map->map[(int)vector_pos.y][(int)(vector_pos.x - STEP)] == '1' &&
	map->map[(int)(vector_pos.y + STEP)][(int)(vector_pos.x + STEP)] == '1' &&
	(last == 1 || last == 2)) ||
	(map->map[(int)vector_pos.y][(int)(vector_pos.x - STEP)] == '1' &&
	is_an_object(map->map[(int)(vector_pos.y - STEP)]
	[(int)(vector_pos.x - STEP)]) &&
	is_an_object(map->map[(int)(vector_pos.y - STEP)]
	[(int)(vector_pos.x + STEP)]) && last == 2) ||
	(map->map[(int)vector_pos.y][(int)(vector_pos.x - STEP)] == '1' &&
	is_an_object(map->map[(int)(vector_pos.y + STEP)]
	[(int)(vector_pos.x - STEP)]) &&
	is_an_object(map->map[(int)(vector_pos.y + STEP)]
	[(int)(vector_pos.x + STEP)]) && (last == 1 || last == 2)))
		return (1);
	return (0);
}

static int	search_so_wall(t_map *map, t_vector2 vector_pos, int last)
{
	if ((map->map[(int)(vector_pos.y + STEP)][(int)vector_pos.x] == '1' &&
	map->map[(int)(vector_pos.y - STEP)][(int)(vector_pos.x - STEP)] == '1' &&
	last == 1) ||
	(map->map[(int)(vector_pos.y + STEP)][(int)vector_pos.x] == '1' &&
	is_an_object(map->map[(int)(vector_pos.y + STEP)]
	[(int)(vector_pos.x - STEP)]) &&
	is_an_object(map->map[(int)(vector_pos.y - STEP)]
	[(int)(vector_pos.x - STEP)]) && last == 1) ||
	(map->map[(int)(vector_pos.y + STEP)][(int)vector_pos.x] == '1' &&
	is_an_object(map->map[(int)(vector_pos.y + STEP)]
	[(int)(vector_pos.x + STEP)]) &&
	is_an_object(map->map[(int)(vector_pos.y - STEP)]
	[(int)(vector_pos.x + STEP)]) && (last == 1 || last == 3)))
		return (1);
	return (0);
}

static int	get_ifangular(t_map *map, t_vector2 vector_pos, int last)
{
	if (search_no_wall(map, vector_pos, last))
		return (0);
	if (search_ea_wall(map, vector_pos, last))
		return (2);
	if (search_so_wall(map, vector_pos, last))
		return (1);
	if ((map->map[(int)vector_pos.y][(int)(vector_pos.x + STEP)] == '1' &&
	map->map[(int)(vector_pos.y + STEP)][(int)(vector_pos.x - STEP)] == '1' &&
	last == 3) ||
	(map->map[(int)vector_pos.y][(int)(vector_pos.x + STEP)] == '1' &&
	is_an_object(map->map[(int)(vector_pos.y + STEP)]
	[(int)(vector_pos.x - STEP)]) &&
	is_an_object(map->map[(int)(vector_pos.y + STEP)]
	[(int)(vector_pos.x + STEP)]) && last == 3))
		return (3);
	return (3);
}

int			get_wall_pole(t_vector2 vector_pos, t_map *map, int last)
{
	if (map->map[(int)(vector_pos.y - STEP)][(int)vector_pos.x] == '1' &&
		map->map[(int)vector_pos.y][(int)(vector_pos.x - STEP)] == '1' &&
		map->map[(int)vector_pos.y][(int)(vector_pos.x + STEP)] == '1')
		return (0);
	if (map->map[(int)(vector_pos.y + STEP)][(int)vector_pos.x] == '1' &&
		map->map[(int)(vector_pos.y - STEP)][(int)vector_pos.x] == '1' &&
		map->map[(int)vector_pos.y][(int)(vector_pos.x - STEP)] == '1')
		return (2);
	if (map->map[(int)(vector_pos.y + STEP)][(int)vector_pos.x] == '1' &&
		map->map[(int)(vector_pos.y)][(int)(vector_pos.x - STEP)] == '1' &&
		map->map[(int)vector_pos.y][(int)(vector_pos.x + STEP)] == '1')
		return (1);
	if (map->map[(int)(vector_pos.y + STEP)][(int)vector_pos.x] == '1' &&
		map->map[(int)(vector_pos.y - STEP)][(int)vector_pos.x] == '1' &&
		map->map[(int)vector_pos.y][(int)(vector_pos.x + STEP)] == '1')
		return (3);
	return (get_ifangular(map, vector_pos, last));
}
