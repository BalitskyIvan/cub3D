/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:37:04 by lmallado          #+#    #+#             */
/*   Updated: 2020/08/18 18:37:06 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_back(t_map *map, t_data *img)
{
	int i;
	int i2;

	i = 0;
	while (i < map->mapstruct.rate_width)
	{
		i2 = 0;
		while(i2 < map->mapstruct.rate_height / 2)
		{
			my_mlx_pixel_put(img, i, i2, create_trgb(1,
			map->mapstruct.floor_color.red, map->mapstruct.floor_color.green,
			map->mapstruct.floor_color.blue));
			i2++;
		}
		i++;
	}
	i = 0;
	while (i < map->mapstruct.rate_width)
	{
		i2 = map->mapstruct.rate_height / 2;
		while(i2 < map->mapstruct.rate_height)
		{
			my_mlx_pixel_put(img, i, i2, create_trgb(1,
			map->mapstruct.ceilling_color.red, map->mapstruct.ceilling_color.green,
			map->mapstruct.ceilling_color.blue));
			i2++;
		}
		i++;
	}
}
