/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 15:35:36 by lmallado          #+#    #+#             */
/*   Updated: 2020/08/09 15:35:38 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	is_valid_structure(t_map *map)
{
	if (map->map_height != 0 && map->map_width != 0 &&
		map->mapstruct.rate_height > 0 && map->mapstruct.rate_width > 0 &&
		map->mapstruct.ea_texture != NULL && map->mapstruct.no_texture != NULL &&
		map->mapstruct.so_texture != NULL && map->mapstruct.we_texture != NULL &&
		map->mapstruct.sprite_texture != NULL && map->mapstruct.floor_color.red != -1 &&
		map->mapstruct.floor_color.green != -1 && map->mapstruct.floor_color.blue != -1 &&
		map->mapstruct.ceilling_color.red != -1 && map->mapstruct.ceilling_color.green != -1 &&
		map->mapstruct.ceilling_color.blue != -1 && map->map != NULL)
			return (1);
	else
		return (0);
}

void line_copy(char **src, char *dst, int width)
{
	int i;
	
	i = 0;
	while (dst[i])
	{
		(*src)[i] = dst[i];
		i++;
	}
	while (i < width)
	{
		(*src)[i] = ' ';
		i++;
	}
	(*src)[i] = '\0';
}
