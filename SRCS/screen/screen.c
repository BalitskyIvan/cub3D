/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 15:48:10 by lmallado          #+#    #+#             */
/*   Updated: 2020/08/18 15:48:13 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	load(t_vars *vars)
{
	if (!load_so_no(vars) ||
		!load_we_ea(vars) ||
		!load_sprite(vars))
		sprite_error();
}

void		render(t_vars *vars)
{
	draw_back(vars->map, vars->img);
	draw_world(vars->map, vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}

static void	create_screenshot(t_vars *vars)
{
	draw_back(vars->map, vars->img);
	draw_world(vars->map, vars);
	make_screenshot(vars);
}

void		create(t_map *map, int is_screenshot)
{
	t_vars			vars;
	t_data			img;

	vars.mlx = mlx_init();
	img.img = mlx_new_image(vars.mlx, map->mapstruct.rate_width,
	map->mapstruct.rate_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
		&img.endian);
	vars.win = mlx_new_window(vars.mlx, map->mapstruct.rate_width,
	map->mapstruct.rate_height, "cub3D");
	vars.map = map;
	vars.img = &img;
	vars.sprite_list = init_spritelist(&vars);
	load(&vars);
	if (is_screenshot == 1)
		create_screenshot(&vars);
	render(&vars);
	hook_keys(&vars);
	mlx_loop(vars.mlx);
}
