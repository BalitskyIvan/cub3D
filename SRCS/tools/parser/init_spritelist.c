/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_spritelist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 14:10:36 by lmallado          #+#    #+#             */
/*   Updated: 2020/09/27 14:10:41 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int		write_position(t_vars *vars, t_vector2 position,
t_list **first_list, int flag)
{
	t_vector2	*pos;

	if (vars->map->map[(int)position.y][(int)position.x] == '2')
	{
		pos = malloc(sizeof(t_vector2));
		pos->x = position.x + 0.5;
		pos->y = position.y + 0.5;
		if (!flag)
		{
			flag = 1;
			*(first_list) = ft_lstnew(pos);
		}
		else
			ft_lstadd_back(&(*(first_list)), ft_lstnew(pos));
	}
	return (flag);
}

t_list			*init_spritelist(t_vars *vars)
{
	t_vector2		position;
	t_list			*first_list;
	int				flag;

	first_list = NULL;
	position.x = 0;
	flag = 0;
	while (position.x < vars->map->map_width)
	{
		position.y = 0;
		while (position.y < vars->map->map_height)
		{
			flag = write_position(vars, position, &first_list, flag);
			position.y++;
		}
		position.x++;
	}
	return (first_list);
}
