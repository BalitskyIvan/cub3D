/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:44:22 by lmallado          #+#    #+#             */
/*   Updated: 2020/09/29 12:45:07 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	load_so_no(t_vars *vars)
{
	int	width;
	int	height;

	vars->no_texture = mlx_xpm_file_to_image(vars->mlx,
	vars->map->mapstruct.no_texture, &width, &height);
	if (vars->no_texture == NULL)
		return (0);
	vars->no_texture->addr = mlx_get_data_addr(vars->no_texture,
	&vars->no_texture->bits_per_pixel, &vars->no_texture->line_length,
	&vars->no_texture->endian);
	vars->no_texture_wh.x = width;
	vars->no_texture_wh.y = height;
	vars->so_texture = mlx_xpm_file_to_image(vars->mlx,
	vars->map->mapstruct.so_texture, &width, &height);
	if (vars->so_texture == NULL)
		return (0);
	vars->so_texture->addr = mlx_get_data_addr(vars->so_texture,
	&vars->so_texture->bits_per_pixel, &vars->so_texture->line_length,
	&vars->so_texture->endian);
	vars->so_texture_wh.x = width;
	vars->so_texture_wh.y = height;
	return (1);
}

int	load_we_ea(t_vars *vars)
{
	int	width;
	int	height;

	vars->we_texture = mlx_xpm_file_to_image(vars->mlx,
	vars->map->mapstruct.we_texture, &width, &height);
	if (vars->we_texture == NULL)
		return (0);
	vars->we_texture->addr = mlx_get_data_addr(vars->we_texture,
	&vars->we_texture->bits_per_pixel, &vars->we_texture->line_length,
	&vars->we_texture->endian);
	vars->we_texture_wh.x = width;
	vars->we_texture_wh.y = height;
	vars->ea_texture = mlx_xpm_file_to_image(vars->mlx,
	vars->map->mapstruct.ea_texture, &width, &height);
	if (vars->ea_texture == NULL)
		return (0);
	vars->ea_texture->addr = mlx_get_data_addr(vars->ea_texture,
	&vars->ea_texture->bits_per_pixel, &vars->ea_texture->line_length,
	&vars->ea_texture->endian);
	vars->ea_texture_wh.x = width;
	vars->ea_texture_wh.y = height;
	return (1);
}

int	load_sprite(t_vars *vars)
{
	int	width;
	int	height;

	vars->sprite_texture = mlx_xpm_file_to_image(vars->mlx,
	vars->map->mapstruct.sprite_texture, &width, &height);
	if (vars->sprite_texture == NULL)
		return (0);
	vars->sprite_texture->addr = mlx_get_data_addr(vars->sprite_texture,
	&vars->sprite_texture->bits_per_pixel, &vars->sprite_texture->line_length,
	&vars->sprite_texture->endian);
	vars->sprite_texture_wh.x = width;
	vars->sprite_texture_wh.y = height;
	return (1);
}
