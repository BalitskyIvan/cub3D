/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 19:07:08 by lmallado          #+#    #+#             */
/*   Updated: 2020/08/10 19:07:09 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	is_right_arg(char c)
{
	if (c == '1' || c == '2' || c == '0' ||
		c == 'N' || c == 'S' || c == 'W' ||
		c == 'E')
		return (1);
	else
		return (0);
}

int	is_valid_arg(char c)
{
	if (c == '1' || c == '2' || c == '0' ||
		c == 'N' || c == 'S' || c == 'W' ||
		c == 'E' || c == ' ')
		return (1);
	else
		return (0);
}

int	is_an_object(char c)
{
	if (c == '2' || c == '0' ||
		c == 'N' || c == 'S' || c == 'W' ||
		c == 'E')
		return (1);
	else
		return (0);
}

int is_wall(char c)
{
	if (c == '1' || c == '2')
		return (1);
	else
		return (0);
}

int	is_a_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' ||
		c == 'E')
		return (1);
	else
		return (0);
}
