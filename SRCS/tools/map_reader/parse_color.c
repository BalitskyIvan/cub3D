/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 17:44:11 by lmallado          #+#    #+#             */
/*   Updated: 2020/08/16 17:44:12 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static void	check_maxcolor(t_color *color)
{
	if ((*color).red > 255 || (*color).green > 255 || (*color).blue > 255)
	{
		(*color).red = -1;
		(*color).green = -1;
		(*color).blue = -1;
	}
}

static void	check_linevalid(char end_char, t_color *color)
{
	if (end_char != '\0')
	{
		(*color).red = -1;
		(*color).green = -1;
		(*color).blue = -1;
	}
}

t_color		get_color(char *line)
{
	int		i;
	t_color	color;

	i = 1;
	while (line[i] == ' ' && line[i])
		i++;
	color.red = ft_atoi(line + i);
	while (line[i] != ',' && line[i])
		i++;
	i++;
	color.green = ft_atoi(line + i);
	while (line[i] != ',' && line[i])
		i++;
	i++;
	while (line[i] == ' ')
		i++;
	color.blue = ft_atoi(line + i);
	check_maxcolor(&color);
	while (line[i] != ' ' && line[i])
		i++;
	while (line[i] == ' ')
		i++;
	check_linevalid(line[i], &color);
	return (color);
}
