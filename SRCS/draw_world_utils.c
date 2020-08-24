/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 16:42:01 by lmallado          #+#    #+#             */
/*   Updated: 2020/08/22 16:42:08 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	get_post_fov(t_vector2 wall_now, float start_x, t_map *map)
{
	t_vector2	wall_xy;
	int			post_width;
	float		alpha;

	post_width = 0;
	alpha = map->player.alpha - FOV / 2 + FOV * start_x / map->mapstruct.rate_width;
	get_distance(map, &wall_xy, 0.005, alpha);
	wall_now.x = (int) wall_xy.x;
	wall_now.y = (int) wall_xy.y;
	while (wall_now.x == (int) wall_xy.x && wall_now.y == (int) wall_xy.y)
	{
		post_width++;
		alpha = map->player.alpha - FOV / 2 + FOV * (start_x + post_width) / map->mapstruct.rate_width;
		get_distance(map, &wall_xy, 0.005, alpha);
	}
	return (post_width - 3);
}

static int	get_pre_fov(float start_x, t_map *map)
{
	t_vector2	wall_xy;
	t_vector2	wall_now;
	int			pre_width;
	float		alpha;

	pre_width = 0;
	alpha = map->player.alpha - FOV / 2 + FOV * start_x / map->mapstruct.rate_width;
	get_distance(map, &wall_xy, 0.005, alpha);
	wall_now.x = (int) wall_xy.x;
	wall_now.y = (int) wall_xy.y;
	while (wall_now.x == (int) wall_xy.x && wall_now.y == (int) wall_xy.y)
	{
		pre_width++;
		alpha = map->player.alpha - FOV / 2 + FOV * (start_x - pre_width) / map->mapstruct.rate_width;
		get_distance(map, &wall_xy, 0.005, alpha);
	}
	return (pre_width - 3);
}

static int		get_visible_fov(t_vector2 wall_now, float start_x, t_map *map, float **wall)
{
	
	t_vector2	wall_xy;
	int			visible_width;
	float		alpha;

	visible_width = 0;
	alpha = map->player.alpha - FOV / 2 + FOV * start_x / map->mapstruct.rate_width;
	(*wall)[visible_width] = get_distance(map, &wall_xy, 0.005, alpha) * cos(alpha - map->player.alpha);
	if (map->mapstruct.rate_height / (float) (*wall)[visible_width] > map->mapstruct.rate_height)
		(*wall)[visible_width] = 1;
	wall_now.x = (int) wall_xy.x;
	wall_now.y = (int) wall_xy.y;
	visible_width++;
	while (wall_now.x == (int) wall_xy.x && wall_now.y == (int) wall_xy.y && start_x + visible_width < map->mapstruct.rate_width)
	{
		alpha = map->player.alpha - FOV / 2 + FOV * (start_x + visible_width) / map->mapstruct.rate_width;
		(*wall)[visible_width] = get_distance(map, &wall_xy, 0.005, alpha) * cos(alpha - map->player.alpha);
		if (map->mapstruct.rate_height / (float) (*wall)[visible_width] > map->mapstruct.rate_height)
		(*wall)[visible_width] = 1;
		visible_width++;
	}
	return (visible_width);
}

float			get_wall_width(float **wall, t_vector2 *wall_xy, t_map *map, int x_start)
{
	float		pre_width = 0;
	float		visible_width = 0;
	float		post_width = 0;

	pre_width = get_pre_fov(x_start, map);
	visible_width = get_visible_fov((*wall_xy), x_start, map, wall);
//	post_width = get_post_fov((*wall_xy), x_start + visible_width, map);
	printf("PRE_WIDTH IS: %f", pre_width);
	wall_xy->y = pre_width + visible_width + post_width;
	wall_xy->x = visible_width;
	return (visible_width);
}

float			get_distance(t_map *map, t_vector2 *wall_xy, float ration, float alpha)
{
	float	r;

	r = 0;
	while (r < 20)
	{
		wall_xy->x = map->player.x + r * cos(alpha);
		wall_xy->y = map->player.y + r * sin(alpha);
		r += ration;
		if ((int) wall_xy->x > map->mapstruct.rate_width - 1 ||
			(int) wall_xy->y > map->mapstruct.rate_height  - 1 ||
			(int) wall_xy->x <= 0 || (int) wall_xy->y <= 0)
				break;
		if (map->map[(int) wall_xy->y][(int) wall_xy->x] == '1')
			break ;
	}
	return (r);
}
