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
		errno = 0;
		free(*res);
		*res = "";
	}
	else
		close(fd);
}

char		*get_texture(char *line, char *now)
{
	int		i;
	int		i2;
	int		i3;
	char	*res;

	i = 0;
	while (line[i] != ' ' && line[i])
		i++;
	while (line[i] == ' ' && line[i])
		i++;
	i2 = i;
	while (line[i2] != ' ' && line[i2])
		i2++;
	i3 = i2;
	while (line[i3] == ' ')
		i3++;
	if (line[i3] != '\0')
		return ("");
	if (line[i])
		res = ft_substr(line, i, i2);
	else
		return ("");
	check_validfile(&res);
	return (res);
}
