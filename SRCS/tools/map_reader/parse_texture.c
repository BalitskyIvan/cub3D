/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmallado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 17:44:01 by lmallado          #+#    #+#             */
/*   Updated: 2020/08/16 17:44:02 by lmallado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static void	check_validfile(char **res)
{
	int	fd;

	if ((fd = open(*res, O_RDONLY)) < 0)
	{
		ft_putstr_fd("Error:\ninvalid path", 0);
		exit(0);
	}
	else
		close(fd);
}

char		*get_texture(char *line)
{
	int		i;
	int		i2;
	char	*res;
	char	*copy;

	i = 0;
	while (line[i] != ' ' && line[i])
		i++;
	while (line[i] == ' ' && line[i])
		i++;
	i2 = i;
	while (line[i2])
		i2++;
	copy = ft_substr(line, i, i2);
	res = ft_strtrim(copy, " ");
	free(copy);
	check_validfile(&res);
	return (res);
}
