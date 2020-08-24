/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:22:17 by lmallado          #+#    #+#             */
/*   Updated: 2020/08/18 18:22:19 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	draw_pixel(t_vector2 wh, t_vector2 xy, t_data *img, int mode)
{
	int i;
	int i2;
	unsigned int color;

	i = 0;
	if (mode == 0)
		color = 0x14000000;
	if (mode == 1)
		color = 0x14C32E10;
	if (mode == 2)
		color = 0x1403AACF;
	while (i < wh.x)
	{
		i2 = 0;
		while (i2 < wh.y)
		{
			my_mlx_pixel_put(img, i + (xy.x * wh.x), i2 + (xy.y * wh.y), color);
			i2++;
		}
		i++;
	}
}

void	render_map(t_map *map, t_data *img, t_vector2 wh)
{
	t_vector2	position;

	position.y = wh.x;
	while (position.y >= 0)
	{
		position.x = map->mapstruct.rate_width - wh.y;
		while (position.x < map->mapstruct.rate_width)
		{
			//printf ("X: %f, Y: %f", position.x, position.y);
		//	if (map->map[(int) position.y][(int) position.x] == '1')
			//my_mlx_pixel_put(img, position.x, position.y, 0x14C32E10);
		//	draw_pixel(wh, position, img, 0);
		//	if (map->map[(int) position.y][(int) position.x] == '2')
		//		draw_pixel(wh, position, img, 2);
			position.x++;
		}
		position.y--;
	}
}

void	render_player(t_map *map, t_data *img, t_vector2 wh)
{
	t_vector2 position;
	
	position.x = map->player.x;
	position.y = map->player.y;
	draw_pixel(wh, position, img, 1);
}