/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot_maker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 21:18:02 by lmallado          #+#    #+#             */
/*   Updated: 2020/09/24 21:18:20 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static void	create_header(t_vars *vars, int fd, int *pad)
{
	unsigned int	size;
	unsigned char	header[54];

	*pad = (4 - (vars->map->mapstruct.rate_width * 3) % 4) % 4;
	size = 54 + (*pad + (vars->map->mapstruct.rate_width * 3))
	* vars->map->mapstruct.rate_height;
	ft_memset(header, (unsigned char)0, 54);
	header[0] = 'B';
	header[1] = 'M';
	header[2] = (unsigned char)size;
	header[3] = (unsigned char)(size >> 8);
	header[4] = (unsigned char)(size >> 16);
	header[5] = (unsigned char)(size >> 24);
	header[10] = (unsigned char)54;
	header[14] = (unsigned char)40;
	header[18] = (unsigned char)(vars->map->mapstruct.rate_width);
	header[19] = (unsigned char)(vars->map->mapstruct.rate_width >> 8);
	header[20] = (unsigned char)(vars->map->mapstruct.rate_width >> 16);
	header[21] = (unsigned char)(vars->map->mapstruct.rate_width >> 24);
	header[22] = (unsigned char)(vars->map->mapstruct.rate_height);
	header[23] = (unsigned char)(vars->map->mapstruct.rate_height >> 8);
	header[24] = (unsigned char)(vars->map->mapstruct.rate_height >> 16);
	header[25] = (unsigned char)(vars->map->mapstruct.rate_height >> 24);
	header[26] = (unsigned char)1;
	header[28] = (unsigned char)24;
	write(fd, header, 54);
}

void	make_screenshot(t_vars *vars)
{
	int				fd;
	int				i;
	int				pad;
	unsigned char	bmppad[3];

	bmppad[0] = (unsigned char)0;
	bmppad[1] = (unsigned char)0;
	bmppad[2] = (unsigned char)0;
	fd = open("screen.bmp", O_WRONLY | O_CREAT, S_IRWXU, S_IRWXG);
	create_header(vars, fd, &pad);
	vars->map->mapstruct.rate_height--;
	while (vars->map->mapstruct.rate_height >= 0)
	{
		i = 0;
		while (i < vars->map->mapstruct.rate_width)
		{
			write(fd, &((int *)vars->img->addr)[vars->map->mapstruct.rate_height
			* vars->map->mapstruct.rate_width + i], 3);
			i++;
		}
		vars->map->mapstruct.rate_height--;
		write(fd, bmppad, pad);
	}
	close(fd);
	exit(0);
}
