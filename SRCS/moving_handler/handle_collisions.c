/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_collisions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:53:30 by lmallado          #+#    #+#             */
/*   Updated: 2020/09/24 11:53:44 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	get_map_element(float delta_x, float delta_y, t_map *map)
{
	return (
	map->map[(int)(map->player.y + delta_y)][(int)(map->player.x + delta_x)]);
}

int			is_collision_detected(float delta_x, float delta_y, t_map *map)
{
	if (is_wall(get_map_element(delta_x + 0.5, delta_y, map)) ||
		is_wall(get_map_element(delta_x, delta_y + 0.5, map)) ||
		is_wall(get_map_element(delta_x - 0.5, delta_y, map)) ||
		is_wall(get_map_element(delta_x, delta_y - 0.5, map)))
		return (1);
	else
		return (0);
}
