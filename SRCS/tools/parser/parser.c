/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 12:43:29 by lmallado          #+#    #+#             */
/*   Updated: 2020/08/09 12:43:30 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static int	is_sym_closed(char **map, int x, int y, t_map *mapconf)
{
	if (x == 0 || y == 0 || x == mapconf->map_width ||
		y == mapconf->map_height - 1)
		return (0);
	if (is_right_arg(map[y][x + 1]) && is_right_arg(map[y][x - 1]) &&
		is_right_arg(map[y + 1][x]) && is_right_arg(map[y - 1][x]))
		return (1);
	return (0);
}

static float get_player_angle(char a)
{
	if (a == 'N')
		return (0);
	if (a == 'S')
		return (PI + PI/2);
	if (a == 'W')
		return (PI);
	if (a == 'E')
		return (PI/2);
	return (0);
}
static int	check(t_map *map, int x, int y)
{
	if (!is_valid_arg(map->map[y][x]))
		return (0);
	if (is_an_object(map->map[y][x]))
	{
		if (!is_sym_closed(map->map, x, y, map))
			return (0);
		if (is_a_player(map->map[y][x]))
		{
			if (map->player.x != -1)
				return (0);
			else
			{
				map->player.x = x;
				map->player.y = y;
				map->player.alpha = get_player_angle(map->map[y][x]);
				(*map).map[y][x] = '0';
			}
		}
	}
	return (1);
}

t_list		*init_spritelist(t_vars *vars)
{
	t_vector2		position;
	t_vector2		*pos;
	t_list			*first_list;
	int				flag;

	position.x = 0;
	flag = 0;
	while (position.x < vars->map->map_width)
	{
		position.y = 0;
		while (position.y < vars->map->map_height)
		{
			if (vars->map->map[(int)position.y][(int)position.x] == '2')
			{
				pos = malloc(sizeof(t_vector2));
				pos->x = position.x;
				pos->y = position.y;
				if (!flag)
				{
					flag = 1;
					first_list = ft_lstnew(pos);
				}
				else
					ft_lstadd_back(&first_list, ft_lstnew(pos));
			}
			position.y++;
		}
		position.x++;
		
	}
	return (first_list);
}

int			is_map_valid(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->map_height - 1)
	{
		x = 0;
		while (x < map->map_width)
		{
			if (!check(map, x, y))
				return (0);
			x++;
		}
		y++;
	}
	if (map->player.x == -1)
		return (0);
	else
		return (1);
}
