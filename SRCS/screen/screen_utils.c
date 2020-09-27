/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:22:53 by lmallado          #+#    #+#             */
/*   Updated: 2020/08/18 18:22:56 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int				create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

unsigned int	my_mlx_pixel_get(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void			load_so_no(t_vars *vars)
{
	int	width;
	int	height;

	vars->no_texture = mlx_xpm_file_to_image(vars->mlx,
	vars->map->mapstruct.no_texture, &width, &height);
	vars->no_texture->addr = mlx_get_data_addr(vars->no_texture,
	&vars->no_texture->bits_per_pixel, &vars->no_texture->line_length,
	&vars->no_texture->endian);
	vars->no_texture_wh.x = width;
	vars->no_texture_wh.y = height;
	vars->so_texture = mlx_xpm_file_to_image(vars->mlx,
	vars->map->mapstruct.so_texture, &width, &height);
	vars->so_texture->addr = mlx_get_data_addr(vars->so_texture,
	&vars->so_texture->bits_per_pixel, &vars->so_texture->line_length,
	&vars->so_texture->endian);
	vars->so_texture_wh.x = width;
	vars->so_texture_wh.y = height;
}

void			load_we_ea_sprite(t_vars *vars)
{
	int	width;
	int	height;

	vars->we_texture = mlx_xpm_file_to_image(vars->mlx,
	vars->map->mapstruct.we_texture, &width, &height);
	vars->we_texture->addr = mlx_get_data_addr(vars->we_texture,
	&vars->we_texture->bits_per_pixel, &vars->we_texture->line_length,
	&vars->we_texture->endian);
	vars->we_texture_wh.x = width;
	vars->we_texture_wh.y = height;
	vars->ea_texture = mlx_xpm_file_to_image(vars->mlx,
	vars->map->mapstruct.ea_texture, &width, &height);
	vars->ea_texture->addr = mlx_get_data_addr(vars->ea_texture,
	&vars->ea_texture->bits_per_pixel, &vars->ea_texture->line_length,
	&vars->ea_texture->endian);
	vars->ea_texture_wh.x = width;
	vars->ea_texture_wh.y = height;
	vars->sprite_texture = mlx_xpm_file_to_image(vars->mlx,
	vars->map->mapstruct.sprite_texture, &width, &height);
	vars->sprite_texture->addr = mlx_get_data_addr(vars->sprite_texture,
	&vars->sprite_texture->bits_per_pixel, &vars->sprite_texture->line_length,
	&vars->sprite_texture->endian);
	vars->sprite_texture_wh.x = width;
	vars->sprite_texture_wh.y = height;
}
