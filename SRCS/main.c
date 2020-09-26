/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 10:20:54 by lmallado          #+#    #+#             */
/*   Updated: 2020/08/09 10:20:56 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_color init_color()
{
	t_color color;
	color.red = -1;
	color.green = -1;
	color.blue = -1;
	return (color);
}

static t_mapstruct init_mapstruct()
{
	t_mapstruct mapstruct;
	
	mapstruct.rate_width = -1;
	mapstruct.rate_height = -1;
	mapstruct.no_texture = NULL;
	mapstruct.so_texture = NULL;
	mapstruct.we_texture = NULL;
	mapstruct.ea_texture = NULL;
	mapstruct.sprite_texture = NULL;
	mapstruct.ceilling_color = init_color();
	mapstruct.floor_color = init_color();
	return (mapstruct);
}

static t_map init_map()
{
	t_map map;
	t_player player;
	t_mapstruct mapstruct;
	
	player.x = -1;
	player.y = -1;
	map.is_map_valid = 1;
	map.map = NULL;
	map.player = player;
	map.mapstruct = init_mapstruct();
	return (map);
}

int main(int argc, char **argv)
{
	errno = 0;
	t_map map;

	map = init_map();
	if (argc == 2 || (argc == 3 && ft_strlen(argv[2]) == 6 &&
	ft_strncmp(argv[2], "--save", 6) == 0))
	{
		if (!read_file(&map, argv[1]))
		{
			ft_putstr_fd("Error:\nnot a valid file", 0);
			return (-1);
		}
		if (!is_map_valid(&map))
		{
			ft_putstr_fd("Error:\nnot a valid map", 0);
			return (-1);
		}
		if (argc == 3)
			create(&map, 1);
		else
			create(&map, 0);
	}
	ft_putstr_fd("Error:\nivalid arguments", 0);
	return (0);
}