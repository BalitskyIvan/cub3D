/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 11:14:53 by lmallado          #+#    #+#             */
/*   Updated: 2020/08/19 11:14:56 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	change_anchorleft(t_map *map, float delta)
{
	map->player.alpha -= delta;
}

static void	change_anchorright(t_map *map, float delta)
{
	map->player.alpha += delta;
}

int			get_key(int keycode, t_vars *vars)
{
	float	anchor_delta;
	float	moving_delta;

	anchor_delta = 0.1;
	moving_delta = 0.1;
	if (keycode == 0)
		turn_left(vars->map, moving_delta);
	if (keycode == 53)
		exit(0);
	if (keycode == 2)
		turn_right(vars->map, moving_delta);
	if (keycode == 13)
		turn_up(vars->map, moving_delta);
	if (keycode == 1)
		turn_down(vars->map, moving_delta);
	if (keycode == 123)
		change_anchorleft(vars->map, anchor_delta);
	if (keycode == 124)
		change_anchorright(vars->map, anchor_delta);
	render(vars);
	return (1);
}

int			on_close(int keycode, t_vars *vars)
{
	keycode = 5;
	vars->wall_xy.y = 0;
	exit(0);
	return (1);
}

void		hook_keys(t_vars *vars)
{
	mlx_hook(vars->win, 2, 0, get_key, vars);
	mlx_hook(vars->win, 17, 0, on_close, vars);
}
