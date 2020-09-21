/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 19:01:04 by lmallado          #+#    #+#             */
/*   Updated: 2020/08/30 19:01:05 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_angular(t_vector2 *wall_xy, t_map *map)
{
	if (map->map[(int)(wall_xy->y - STEP)][(int)wall_xy->x] == '1' &&
		map->map[(int)wall_xy->y][(int)(wall_xy->x - STEP)] == '1')
		return (1);
	if (map->map[(int)(wall_xy->y - STEP)][(int)wall_xy->x] == '1' &&
		map->map[(int)wall_xy->y][(int)(wall_xy->x + STEP)] == '1')
		return (1);
	if (map->map[(int)(wall_xy->y + STEP)][(int)wall_xy->x] == '1' &&
		map->map[(int)wall_xy->y][(int)(wall_xy->x - STEP)] == '1')
		return (1);
	if (map->map[(int)(wall_xy->y + STEP)][(int)wall_xy->x] == '1' &&
		map->map[(int)wall_xy->y][(int)(wall_xy->x + STEP)] == '1')
		return (1);
	return (0);
}

static void	init_ifeano(t_vars *vars, t_drawconfig *drawconfig, int pole,
t_vector2 vector)
{
	if (pole == 0)
	{
		drawconfig->texture = vars->no_texture;
		drawconfig->texture_wh.x = vars->no_texture_wh.x;
		drawconfig->texture_wh.y = vars->no_texture_wh.y;
		drawconfig->texture_get.x = ((int)(vector.x * drawconfig->texture_wh.x)
		% (int)drawconfig->texture_wh.x);
	}
	if (pole == 1)
	{
		drawconfig->texture = vars->so_texture;
		drawconfig->texture_wh.x = vars->so_texture_wh.x;
		drawconfig->texture_wh.y = vars->so_texture_wh.y;
		drawconfig->texture_get.x = ((int)((drawconfig->texture_wh.x - vector.x)
		* drawconfig->texture_wh.x) % (int)drawconfig->texture_wh.x);
	}
}

void		init_drawconfig(t_vars *vars, t_drawconfig *drawconfig, int pole,
t_vector2 vector)
{
	init_ifeano(vars, drawconfig, pole, vector);
	if (pole == 2)
	{
		drawconfig->texture = vars->we_texture;
		drawconfig->texture_wh.x = vars->we_texture_wh.x;
		drawconfig->texture_wh.y = vars->we_texture_wh.y;
		drawconfig->texture_get.x = ((int)((drawconfig->texture_wh.x - vector.y)
		* drawconfig->texture_wh.x) % (int)drawconfig->texture_wh.x);
	}
	if (pole == 3)
	{
		drawconfig->texture = vars->ea_texture;
		drawconfig->texture_wh.x = vars->ea_texture_wh.x;
		drawconfig->texture_wh.y = vars->ea_texture_wh.y;
		drawconfig->texture_get.x = ((int)(vector.y * drawconfig->texture_wh.x)
		% (int)drawconfig->texture_wh.x);
	}
}
