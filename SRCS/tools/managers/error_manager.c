/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 14:03:30 by lmallado          #+#    #+#             */
/*   Updated: 2020/08/09 14:03:33 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	catch_error(void)
{
	if (errno != 0)
	{
		perror("Error\n");
		exit(errno);
	}
}

void	catch_maperror(void)
{
	if (errno != 0)
	{
		perror("Error\n");
		exit(errno);
	}
}

void	sprite_error(void)
{
	ft_putstr_fd("Error:\nnot a valid sprite file\n", 0);
	exit(0);
}
