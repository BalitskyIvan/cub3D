/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 15:19:28 by lmallado          #+#    #+#             */
/*   Updated: 2020/09/21 15:19:33 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void		sort(t_list *sprite_list, t_vars *vars)
{
	t_list		*current;
	t_vector2	*config;
	float		dist;
	int			flag;
	
	flag = 0;
	while (flag == 0)
	{
		flag = 1;
		current = sprite_list;
		config = current->content;
		dist = sqrt(pow((vars->map->player.x - config->x - 0.5), 2) + pow((vars->map->player.y - config->y - 0.5), 2)) * 0.85;
		while (current->next)
		{
			config = current->next->content;
			if (dist > sqrt(pow((vars->map->player.x - config->x - 0.5), 2) + pow((vars->map->player.y - config->y - 0.5), 2))* 0.85)
			{
				flag = 0;
				current->next->content = current->content;
				current->content = config;
			}
			current = current->next;
		}
	}
}

static t_list	*get_current_item(t_list *sprite_list, int i)
{
	int		i2;
	t_list	*current;
	
	i2 = 0;
	current = sprite_list;
	while (i2 < i)
	{
		i2++;
		current = current->next;
	}
	return (current);
}

int				draw_sprite(t_list *sprite_list, t_vars *vars, float dist[])
{
	t_list		*current;
	t_vector2	*config;
	int			i2;

	sort(sprite_list, vars);
	i2 = ft_lstsize(sprite_list) - 1;
	current = get_current_item(sprite_list, i2);
	while (i2 >= 0)
	{
		config = current->content;
		float fov = PI/3;
		float player_alpha = vars->map->player.alpha;
		float p = 3.14;
		float sprite_dir = atan2((config->y - vars->map->player.y + 0.5), (config->x - vars->map->player.x + 0.5));
		while (sprite_dir - vars->map->player.alpha >  PI) sprite_dir -= 2 * PI;
		while (sprite_dir - vars->map->player.alpha < -PI) sprite_dir += 2 * PI;
		float	sprite_dist = sqrt((pow((vars->map->player.x - config->x - 0.5), 2) + pow((vars->map->player.y - config->y - 0.5), 2))) * 0.85;
		 
		int		sprite_screen_size = vars->map->mapstruct.rate_height / sprite_dist;
		if (sprite_screen_size > vars->map->mapstruct.rate_height)
			sprite_screen_size = vars->map->mapstruct.rate_height;
		int		h_offset = ((sprite_dir - player_alpha) * vars->map->mapstruct.rate_width)/fov + (vars->map->mapstruct.rate_width / 2) - (sprite_screen_size / 2);
		int		v_offset = vars->map->mapstruct.rate_height/2 - sprite_screen_size/2;

		for (int i = 0; i < sprite_screen_size; i++) {
			if (h_offset + i < -sprite_screen_size || h_offset + i >= vars->map->mapstruct.rate_width )
				break;
			if (dist[h_offset + i] > sprite_dist)
			{
				for (int j = 0; j < sprite_screen_size; j++) {
					if (v_offset + j < 0 || v_offset + j >= vars->map->mapstruct.rate_height)
						break;
					if (h_offset + i >= 0 && my_mlx_pixel_get(vars->sprite_texture, i * vars->sprite_texture_wh.x/sprite_screen_size, j * vars->sprite_texture_wh.y/ sprite_screen_size) !=  4278190080)
						my_mlx_pixel_put(vars->img, h_offset + i, v_offset + j, my_mlx_pixel_get(vars->sprite_texture, i * vars->sprite_texture_wh.x/sprite_screen_size, j * vars->sprite_texture_wh.y/ sprite_screen_size));
				}
			}
		}
		i2--;
		current = get_current_item(sprite_list, i2);
	}
	return (1);
}
