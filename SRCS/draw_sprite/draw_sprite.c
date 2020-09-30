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

static float	get_dst(t_vars *vars, t_vector2 *config)
{
	return (sqrt(pow((vars->map->player.x - config->x), 2) +
		pow((vars->map->player.y - config->y), 2)) * 0.95);
}

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
		dist = get_dst(vars, config);
		while (current->next)
		{
			config = current->next->content;
			if (dist > get_dst(vars, config))
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

static void		draw(t_vars *vars, t_vector2 *config, float dist[])
{
	t_vector2	size;
	t_vector2	iterator;
	float		sprite_dist;
	int			sprite_screen_size;

	sprite_dist = sqrt((pow((vars->map->player.x - config->x), 2)
	+ pow((vars->map->player.y - config->y), 2))) * 0.95;
	sprite_screen_size = get_sprite_screensize(sprite_dist, vars);
	iterator.x = 0;
	size = get_sprite_size(vars, config, sprite_screen_size);
	while (iterator.x < sprite_screen_size)
	{
		if (size.x + iterator.x < -sprite_screen_size ||
		size.x + iterator.x >= vars->map->mapstruct.rate_width)
			break ;
		if (dist[(int)(size.x + iterator.x)] > sprite_dist)
			draw_sprite_rect(iterator.x, size, vars, sprite_screen_size);
		iterator.x++;
	}
}

int				draw_sprite(t_list *sprite_list, t_vars *vars, float dist[])
{
	t_list		*current;
	t_vector2	*config;
	int			i2;

	if (sprite_list == NULL)
		return (1);
	sort(sprite_list, vars);
	i2 = ft_lstsize(sprite_list) - 1;
	current = get_current_item(sprite_list, i2);
	while (i2 >= 0)
	{
		config = current->content;
		draw(vars, config, dist);
		i2--;
		current = get_current_item(sprite_list, i2);
	}
	return (1);
}
