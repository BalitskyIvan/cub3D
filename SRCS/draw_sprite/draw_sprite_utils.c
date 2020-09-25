/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 13:57:50 by lmallado          #+#    #+#             */
/*   Updated: 2020/09/01 13:57:52 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static float	get_sprite_dir(t_vars *vars, t_vector2 *config)
{
	float sprite_dir;

	sprite_dir = atan2((config->y - vars->map->player.y),
	(config->x - vars->map->player.x));
	while (sprite_dir - vars->map->player.alpha > PI)
		sprite_dir -= 2 * PI;
	while (sprite_dir - vars->map->player.alpha < -PI)
		sprite_dir += 2 * PI;
	return (sprite_dir);
}

t_vector2		get_sprite_size(t_vars *vars, t_vector2 *config,
int sprite_screen_size)
{
	t_vector2	size;

	size.x = ((get_sprite_dir(vars, config) - vars->map->player.alpha)
	* vars->map->mapstruct.rate_width) / ((float)FOV)
	+ (vars->map->mapstruct.rate_width / 2) - (sprite_screen_size / 2);
	size.y = vars->map->mapstruct.rate_height / 2 - sprite_screen_size / 2;
	return (size);
}

int				get_sprite_screensize(float sprite_dist, t_vars *vars)
{
	int sprite_screen_size;

	sprite_screen_size = vars->map->mapstruct.rate_height / sprite_dist;
	if (sprite_screen_size > vars->map->mapstruct.rate_height * 2)
		sprite_screen_size = vars->map->mapstruct.rate_height * 2;
	return (sprite_screen_size);
}

void			draw_sprite_rect(int x, t_vector2 size, t_vars *vars,
int sprite_screen_size)
{
	int	y;

	y = 0;
	while (y < sprite_screen_size)
	{
		if (size.y + y < 0 || size.y + y >= vars->map->mapstruct.rate_height)
			break ;
		if (size.x + x >= 0 && my_mlx_pixel_get(vars->sprite_texture,
		x * vars->sprite_texture_wh.x / sprite_screen_size,
		y * vars->sprite_texture_wh.y / sprite_screen_size)
		!= 4278190080)
			my_mlx_pixel_put(vars->img, size.x + x, size.y + y,
			my_mlx_pixel_get(vars->sprite_texture,
			x * vars->sprite_texture_wh.x / sprite_screen_size,
			y * vars->sprite_texture_wh.y / sprite_screen_size));
		y++;
	}
}
