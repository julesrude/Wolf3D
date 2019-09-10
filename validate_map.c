/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:14:30 by yruda             #+#    #+#             */
/*   Updated: 2019/09/08 22:01:20 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
**	[1-9] are different kinds of walls
**	[x] is the position of the player
**	[.] are free space
*/

int		is_valid(char c)
{
	if (c >= '1' && c <= '9')
		return (1);
	if (c == '.')
		return (1);
	if (c == 'x')
		return (1);
	return (0);
}

/*
**	returns (-1) if there is an unknown character
*/

int		count_chars(char *line)
{
	int		i;

	i = 0;
	while (*line)
	{
		if (is_valid(*line))
			i++;
		else if (!ft_iswhitespace(*line))
			return (-1);
		line++;
	}
	return (i);
}

int		read_line(char *line, char *map)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = ft_strrchr(map, '\0');
	while (*line)
	{
		if (is_valid(*line))
		{
			ptr[i] = *line;
			i++;
		}
		else if (!ft_iswhitespace(*line))
			return (-1);
		line++;
	}
	ptr[i] = '\n';
	ptr[i + 1] = '\0';
	return (i);
}

void	exit_map(char *line, char *map)
{
	ft_strdel(&line);
	ft_strdel(&map);
	put_error(ERR_MESSAGE, "wolf3d: valid map has > 2 columns and rows,\n\
	\r	even number of characters in every row and\n\
	\r	only valid characters:\n	[1 - 9] are walls,\n\
	\r	[.] are free spaces,\n\
	\r	[x] is the position of the player", 1);
}

int		read_file(char *file, char **map, t_wolf *w)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = 0;
	ft_strdel(map);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (put_error(ERR_ERRNO, file, 1));
	(get_next_line(fd, &line) == -1) ?
		put_error(ERR_ERRNO, file, 1) : (w->xwidth = count_chars(line));
	(w->xwidth < 3) ?
		exit_map(line, *map) : (*map = ft_strnew(8));
	read_line(line, *map);
	free(line);
	while(get_next_line(fd, &line))
	{
		*map = ft_strrealloc(*map, w->xwidth);
		if (read_line(line, *map) != w->xwidth)
			exit_map(line, *map);
		w->ylength++;
		free(line);
	}
	(w->ylength < 3 || w->xwidth < 3) ?
		exit_map(line, *map) : (1);
	free(line);
	return (0);
}