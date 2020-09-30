/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 16:34:19 by lmallado          #+#    #+#             */
/*   Updated: 2020/08/22 16:34:21 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static float	get_hight_res(t_map *map, t_vector2 *wall_xy, float alpha, float r)
{
	float		delta;
	char 		now;
	t_vector2	position;
	char 		previous;

	previous = map->map[(int)wall_xy->y][(int)wall_xy->x];
	delta = -0.02;
	r += delta;
	position.x = map->player.x + r * cos(alpha);
	position.y = map->player.y + r * sin(alpha);
	now = map->map[(int)position.y][(int)position.x];
	while (now != previous)
	{
		previous = now;
		
		if (delta < 0)
		{
			delta *= -1;
			delta -= 0.0001;
		}
		else if (delta > 0)
		{
			delta -= 0.0001;
			delta *= -1;
		}
		r += delta;
		position.x = map->player.x + r * cos(alpha);
		position.y = map->player.y + r * sin(alpha);
		now = map->map[(int)position.y][(int)position.x];
	}
	return (r);
}

float		get_distance(t_map *map, t_vector2 *wall_xy, float alpha)
{
	float	r;

	r = 0;
	while (r < 100)
	{
		wall_xy->x = map->player.x + r * cos(alpha);
		wall_xy->y = map->player.y + r * sin(alpha);
		r += STEP;
		if ((int)wall_xy->x > map->mapstruct.rate_width - 1 ||
		(int)wall_xy->y > map->mapstruct.rate_height - 1 ||
		(int)wall_xy->x < 0 || (int)wall_xy->y < 0)
			break ;
		if (map->map[(int)wall_xy->y][(int)wall_xy->x] == '1')
			r = get_hight_res(map, wall_xy, alpha, r);
		if (check_angular(wall_xy, map))
			break ;
	}
	return (r);
}

void		draw_world(t_map *map, t_vars *vars)
{
	int		i;
	int		last;
	float	alpha;
	float	dist[map->mapstruct.rate_width];

	i = 0;
	last = 0;
	while (i < map->mapstruct.rate_width)
	{
		alpha = vars->map->player.alpha - FOV / 2 + FOV *
		i / vars->map->mapstruct.rate_width;
		dist[i] = get_distance(vars->map, &(vars->wall_xy), alpha) *
		cos(alpha - vars->map->player.alpha);
		last = draw_walls(vars, i, last, dist[i]);
		i++;
	}
	draw_sprite(vars->sprite_list, vars, dist);
}
