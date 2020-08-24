/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:21:22 by lmallado          #+#    #+#             */
/*   Updated: 2020/08/18 18:21:23 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	draw_map(t_data *img, t_map *map)
{
	t_vector2	wh;

	wh.y = (map->mapstruct.rate_width) / 5;
	wh.x = (map->mapstruct.rate_height) / 5;
	render_map(map, img, wh);
//	render_player(map, img, wh);
}