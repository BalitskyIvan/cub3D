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

void print_map(t_map map)
{
	int i = 0;
	printf("WIDTH : %d\n", map.map_width);
	printf("HEIGHT : %d\n", map.map_height);
	printf("RATE: %d %d\n", map.mapstruct.rate_width, map.mapstruct.rate_height);
	printf("NO %s\n", map.mapstruct.no_texture);
	printf("SO %s\n", map.mapstruct.so_texture);
	printf("WE %s\n", map.mapstruct.we_texture);
	printf("EA %s\n", map.mapstruct.ea_texture);
	printf("S %s\n", map.mapstruct.sprite_texture);
	printf("F: %d, %d, %d\n", map.mapstruct.floor_color.red, map.mapstruct.floor_color.green, map.mapstruct.floor_color.blue);
	printf("C: %d, %d, %d\n", map.mapstruct.ceilling_color.red, map.mapstruct.ceilling_color.green, map.mapstruct.ceilling_color.blue);
	printf("\n__________MAP____________\n\n");
	while (i < map.map_height)
	{
		printf("%s\n", map.map[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	errno = 0;
	t_map map;
	
	map = init_map();
	if (argc == 2)
	{
		if (!read_file(&map, argv[1]))
		{
			print_map(map);
			ft_putstr_fd("Error: not a valid map structure", 0);
			return (-1);
		}
		print_map(map);
		if (!is_map_valid(&map))
		{
			ft_putstr_fd("Error: not a valid map", 0);
			return (-1);
		}
		create(&map);
	}
	return (0);
}