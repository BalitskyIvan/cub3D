/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 16:42:01 by lmallado          #+#    #+#             */
/*   Updated: 2020/08/22 16:42:08 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	int check_angular(t_vector2 *wall_xy, t_map *map, float step)
{
	if (map->map[(int) (wall_xy->y - step)][(int) wall_xy->x] == '1' &&
		map->map[(int) wall_xy->y][(int) (wall_xy->x - step)] == '1')
		return (1);
	if (map->map[(int) (wall_xy->y - step)][(int) wall_xy->x] == '1' &&
		map->map[(int) wall_xy->y][(int) (wall_xy->x + step)] == '1')
		return (1);
	if (map->map[(int) (wall_xy->y + step)][(int) wall_xy->x] == '1' &&
		map->map[(int) wall_xy->y][(int) (wall_xy->x - step)] == '1')
		return (1);
	if (map->map[(int) (wall_xy->y + step)][(int) wall_xy->x] == '1' &&
		map->map[(int) wall_xy->y][(int) (wall_xy->x + step)] == '1')
		return (1);
	return (0);
}

float	get_distance(t_map *map, t_vector2 *wall_xy, float step, float alpha)
{
	float	r;
	float	delta;

	r = 0;
	while (r < 10)
	{
		wall_xy->x = map->player.x + r * cos(alpha);
		wall_xy->y = map->player.y + r * sin(alpha);
		r += step;
		if ((int) wall_xy->x > map->mapstruct.rate_width - 1 ||
			(int) wall_xy->y > map->mapstruct.rate_height - 1 ||
			(int) wall_xy->x < 0 || (int) wall_xy->y < 0)
				break;
		if (check_angular(wall_xy, map, step))
			break;
		if (map->map[(int) wall_xy->y][(int) wall_xy->x] == '1')
			break ;
	}
	return (r);
}

static int		get_ifangular(t_map *map, float vector_pos_x, float vector_pos_y, float step)
{
	if ((map->map[(int) (vector_pos_y - step)][(int) vector_pos_x] == '1' &&
	map->map[(int) (vector_pos_y + step)][(int) (vector_pos_x + step)] == '1'))// ||
	// (map->map[(int) (vector_pos_y - step)][(int) vector_pos_x] == '1' &&
	// map->map[(int) (vector_pos_y + step)][(int) (vector_pos_x + step)] == '1'))// &&
	// get_wall_pole(vector_pos_x - 0.5, vector_pos_y - step, map, step) == 0)) //||
	// // (map->map[(int) (vector_pos.y - step)][(int) vector_pos.x] == '1' &&
	// // map->map[(int) (vector_pos.y - step)][(int) (vector_pos.x + step)] == '0' &&
	// // map->map[(int) (vector_pos.y + step)][(int) (vector_pos.x + step)] == '0'))
		return (0);
	if ((map->map[(int) vector_pos_y][(int) (vector_pos_x - step)] == '1' &&
	map->map[(int) (vector_pos_y - step)][(int) (vector_pos_x + step)] == '1'))// &&
	// get_wall_pole(vector_pos_x - step, vector_pos_y, map, step) == 2))// ||
	// // (map->map[(int) vector_pos_y][(int) (vector_pos_x - step)] == '1' &&
	// // map->map[(int) (vector_pos_y - step)][(int) (vector_pos_x - step)] == '0' &&
	// // map->map[(int) (vector_pos_y - step)][(int) (vector_pos_x + step)] == '0'))
		return (2);
	if ((map->map[(int) (vector_pos_y + step)][(int) vector_pos_x] == '1' &&
	map->map[(int) (vector_pos_y - step)][(int) (vector_pos_x - step)] == '1'))// &&
	// get_wall_pole(vector_pos_x,  vector_pos_y + step, map, step) == 1))// ||
	// // (map->map[(int) (vector_pos_y + step)][(int) vector_pos_x] == '1' &&
	// // map->map[(int) (vector_pos_y + step)][(int) (vector_pos_x - step)] == '0' &&
	// // map->map[(int) (vector_pos_y - step)][(int) (vector_pos_x - step)] == '0'))
		return (1);
	if ((map->map[(int) vector_pos_y][(int) (vector_pos_x + step)] == '1' &&
	map->map[(int) (vector_pos_y + step)][(int) (vector_pos_x - step)] == '1'))// &&
	// get_wall_pole(vector_pos_x + step, vector_pos_y, map, step) == 3))// ||
	// // (map->map[(int) vector_pos_y][(int) (vector_pos_x + step)] == '1' &&
	// // map->map[(int) (vector_pos_y + step)][(int) (vector_pos_x - step)] == '0' &&
	// // map->map[(int) (vector_pos_y + step)][(int) (vector_pos_x + step)] == '0'))
		return (3);
	return (3);
}

int		get_wall_pole(float vector_pos_x, float vector_pos_y, t_map *map, float step)
{
	if (map->map[(int) (vector_pos_y - step)][(int) vector_pos_x] == '1' &&
		map->map[(int) vector_pos_y][(int) (vector_pos_x - step)] == '1' &&
		map->map[(int) vector_pos_y][(int) (vector_pos_x + step)] == '1')
		return (0);
	if (map->map[(int) (vector_pos_y + step)][(int) vector_pos_x] == '1' &&
		map->map[(int) (vector_pos_y - step)][(int) vector_pos_x] == '1' &&
		map->map[(int) vector_pos_y][(int) (vector_pos_x - step)] == '1')
		return (2);
	if (map->map[(int) (vector_pos_y + step)][(int) vector_pos_x] == '1' &&
		map->map[(int) (vector_pos_y)][(int) (vector_pos_x - step)] == '1' &&
		map->map[(int) vector_pos_y][(int) (vector_pos_x + step)] == '1')
		return (1);
	if (map->map[(int) (vector_pos_y + step)][(int) vector_pos_x] == '1' &&
		map->map[(int) (vector_pos_y - step)][(int) vector_pos_x] == '1' &&
		map->map[(int) vector_pos_y][(int) (vector_pos_x + step)] == '1')
		return (3);	
	return (get_ifangular(map, vector_pos_x, vector_pos_y, step));
}
