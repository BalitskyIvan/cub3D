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

static void		draw_rect(t_data *img, t_vars *vars, t_vector2 vector, float x, float height, t_map *map, int pole, float dist)
{
	float		i2;
	t_vector2	texture_get;
	t_vector2	texture_wh;
	t_data		*texture;
	float r_h;

	if (pole == 0)
	{
		texture = vars->no_texture;
		texture_wh.x = vars->no_texture_wh.x;
		texture_wh.y = vars->no_texture_wh.y;
		texture_get.x = ((int) (vector.x * texture_wh.x) % (int) texture_wh.x);
	}
	if (pole == 1)
	{
		texture = vars->so_texture;
		texture_wh.x = vars->so_texture_wh.x;
		texture_wh.y = vars->so_texture_wh.y;
		texture_get.x = ((int) ((texture_wh.x - vector.x) * texture_wh.x) % (int) texture_wh.x);
	}
	if (pole == 2)
	{
		texture = vars->we_texture;
		texture_wh.x = vars->we_texture_wh.x;
		texture_wh.y = vars->we_texture_wh.y;
		texture_get.x = ((int) ((texture_wh.x - vector.y) * texture_wh.x) % (int) texture_wh.x);
	}
	if (pole == 3)
	{
		texture = vars->ea_texture;
		texture_wh.x = vars->ea_texture_wh.x;
		texture_wh.y = vars->ea_texture_wh.y;
		texture_get.x = ((int) (vector.y * texture_wh.x) % (int) texture_wh.x);
	}
	r_h = height;
	if (r_h > map->mapstruct.rate_height)
		r_h = map->mapstruct.rate_height;
	i2 = map->mapstruct.rate_height / 2 - r_h / 2;
	while (i2 < map->mapstruct.rate_height / 2 + r_h / 2 &&  i2 <= map->mapstruct.rate_height)
	{
		texture_get.y = (i2 - (map->mapstruct.rate_height / 2 - height / 2)) / (height / texture_wh.y);
		my_mlx_pixel_put(img, x, i2, my_mlx_pixel_get(texture, texture_get.x, texture_get.y));
		i2++;
	}
}

void			draw_world(t_data *img, t_map *map, t_vars *vars)
{
	int			i;
	float		alpha;
	float		dist;
	float		step = 0.01;
	t_vector2	wall_xy;
	float		height;

	i = 0;
	while (i < map->mapstruct.rate_width)
	{
		alpha = map->player.alpha - FOV / 2 + FOV * i / map->mapstruct.rate_width;
		dist = get_distance(map, &wall_xy, step, alpha) * cos(alpha - map->player.alpha);
		draw_rect(img, vars, wall_xy, i, map->mapstruct.rate_height / (float) dist, map, get_wall_pole(wall_xy.x, wall_xy.y, map, step), dist);
		i++;
	}
}