/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 15:48:10 by lmallado          #+#    #+#             */
/*   Updated: 2020/ ,08/18 15:48:13 by lmallado         ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void load(t_vars *vars)
{
	int	width;
	int	height;

	vars->no_texture = mlx_xpm_file_to_image(vars->mlx, vars->map->mapstruct.no_texture,
	&width, &height);
	vars->no_texture->addr = mlx_get_data_addr(vars->no_texture, &vars->no_texture->bits_per_pixel, &vars->no_texture->line_length,
	&vars->no_texture->endian);
	vars->no_texture_wh.x = width;
	vars->no_texture_wh.y = height;
	vars->so_texture = mlx_xpm_file_to_image(vars->mlx, vars->map->mapstruct.so_texture,
	&width, &height);
	vars->so_texture->addr = mlx_get_data_addr(vars->so_texture, &vars->so_texture->bits_per_pixel, &vars->so_texture->line_length,
	&vars->so_texture->endian);
	vars->so_texture_wh.x = width;
	vars->so_texture_wh.y = height;
	vars->we_texture = mlx_xpm_file_to_image(vars->mlx, vars->map->mapstruct.we_texture,
	&width, &height);
	vars->we_texture->addr = mlx_get_data_addr(vars->we_texture, &vars->we_texture->bits_per_pixel, &vars->we_texture->line_length,
	&vars->we_texture->endian);
	vars->we_texture_wh.x = width;
	vars->we_texture_wh.y = height;
	vars->ea_texture = mlx_xpm_file_to_image(vars->mlx, vars->map->mapstruct.ea_texture,
	&width, &height);
	vars->ea_texture->addr = mlx_get_data_addr(vars->ea_texture, &vars->ea_texture->bits_per_pixel, &vars->ea_texture->line_length,
	&vars->ea_texture->endian);
	vars->ea_texture_wh.x = width;
	vars->ea_texture_wh.y = height;
	vars->sprite_texture = mlx_xpm_file_to_image(vars->mlx, vars->map->mapstruct.sprite_texture,
	&width, &height);
	vars->sprite_texture->addr = mlx_get_data_addr(vars->sprite_texture, &vars->sprite_texture->bits_per_pixel, &vars->sprite_texture->line_length,
	&vars->sprite_texture->endian);
	vars->sprite_texture_wh.x = width;
	vars->sprite_texture_wh.y = height;
}

void	render(t_vars *vars)
{
	draw_back(vars->map, vars->img);
	draw_world(vars->img, vars->map, vars);
//	draw_map(vars->img, vars->map);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}

void	create(t_map *map)
{
	t_vars			vars;
	t_data			img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, map->mapstruct.rate_width, map->mapstruct.rate_height, "cub3D");
	img.img = mlx_new_image(vars.mlx, map->mapstruct.rate_width, map->mapstruct.rate_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
		&img.endian);
	vars.map = map;
	vars.img = &img;
	vars.sprite_list = init_spritelist(&vars);
	load(&vars);
	render(&vars);
	hook_keys(&vars);
	mlx_loop(vars.mlx);
}
