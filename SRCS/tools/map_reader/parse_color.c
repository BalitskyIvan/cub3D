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

static int	set_color(int start, int *res, char *line, char exit_sym)
{
	int i;

	i = start;
	while (line[i] == ' ' && line[i])
		i++;
	*res = ft_atoi(line + i);
	while (line[i] >= '0' && line[i] <= '9')
		i++;
	while (line[i] == ' ')
		i++;
	if (line[i] != exit_sym)
		*res = -1;
	i++;
	return (i);
}

t_color		get_color(char *line)
{
	int		i;
	t_color	color;

	i = set_color(1, &color.red, line, ',');
	i = set_color(i, &color.green, line, ',');
	i = set_color(i, &color.blue, line, '\0');
	check_maxcolor(&color);
	return (color);
}
