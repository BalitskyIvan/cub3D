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

static void		draw_rect(t_data *img, t_data *source, t_vector2 wh_texture, float x, float x_wall, t_vector2 start_and_width, float height, t_map *map)
{
	float	i2;
	float	width_scale;
	float	height_scale;
	int 	i;

	width_scale = start_and_width.y / wh_texture.x;
	height_scale = height / wh_texture.y;
	i2 = map->mapstruct.rate_height / 2 - height / 2;
	i = 0;
	while (i2 < map->mapstruct.rate_height / 2 + height / 2)
	{
		my_mlx_pixel_put(img, x, i2, my_mlx_pixel_get(source, ((x_wall + start_and_width.x) / width_scale), i / height_scale));
		i2++;
		i++;
	}
}

void			draw_world(t_data *img, t_map *map, t_vars *vars)
{
	int		i;
	int		i2;
	float	*wall;
	float	visible_wall_width;
	t_vector2	wall_xy;

	wall = malloc((map->mapstruct.rate_width + 1) * sizeof(float));
	i = 0;
	while (i < map->mapstruct.rate_width)
	{
		i2 = 0;
		visible_wall_width = get_wall_width(&wall, &wall_xy, map, i);
		printf("WIDTH IS : %f\n", wall_xy.y);
		while (i2 < visible_wall_width)
		{
			draw_rect(img, vars->no_texture, vars->no_texture_wh, i, i2, wall_xy, map->mapstruct.rate_height / wall[i2], map);
			i2++;
			i++;
		}
		i++;
	}
	free(wall);
}