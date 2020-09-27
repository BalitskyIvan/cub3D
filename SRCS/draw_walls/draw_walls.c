/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 18:42:34 by lmallado          #+#    #+#             */
/*   Updated: 2020/08/30 18:42:36 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	draw_rect(t_vars *vars, t_drawconfig drawconfig,
float x, float height)
{
	float	i;
	float	r_h;

	r_h = height;
	if (r_h > vars->map->mapstruct.rate_height)
		r_h = vars->map->mapstruct.rate_height;
	i = vars->map->mapstruct.rate_height / 2 - r_h / 2;
	while (i < vars->map->mapstruct.rate_height / 2 + r_h / 2 &&
	i <= vars->map->mapstruct.rate_height)
	{
		drawconfig.texture_get.y =
		(i - (vars->map->mapstruct.rate_height / 2 - height / 2)) /
		(height / drawconfig.texture_wh.y);
		my_mlx_pixel_put(vars->img, x, i, my_mlx_pixel_get(drawconfig.texture,
		drawconfig.texture_get.x, drawconfig.texture_get.y));
		i++;
	}
}

int			draw_walls(t_vars *vars, int i, int last, float dist)
{
	t_drawconfig	drawconfig;

	last = get_wall_pole(vars->wall_xy, vars->map, last);
	init_drawconfig(vars, &drawconfig, last, vars->wall_xy);
	draw_rect(vars, drawconfig, i,
	vars->map->mapstruct.rate_height / (float)dist);
	return (last);
}
