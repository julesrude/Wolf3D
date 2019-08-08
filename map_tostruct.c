/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tostruct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 14:22:31 by yruda             #+#    #+#             */
/*   Updated: 2019/08/08 19:41:49 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	calc_playercoords(t_wolf *w)
{
	printf(COLOR_BLUE "%d %d\n" COLOR_RESET, w->xplayer, w->yplayer);
	w->xplayer = BLKSIZE * (w->xplayer) - 1 + BLKSIZE / 2;
	w->yplayer = BLKSIZE * (w->yplayer) - 1 + BLKSIZE / 2;
	printf(COLOR_BLUE "%d %d\n" COLOR_RESET, w->xplayer, w->yplayer);
}

void	parse_playerposition(char *map, t_wolf *w)
{
	int		pos;

	pos = ft_strchrindex(map, 'x');
	printf("pos %d\n%s\n", ft_strchrindex(map, 'x'), map);
	if (pos == -1)
	{
		pos = ft_strchrindex(map, '.');
		if (pos == -1)
			put_error(ERR_MESSAGE,
				"wolf3d: there should be at least one '.' or'x' in the map", 1);
	}
	w->xplayer = pos % (w->xwidth + 1);
	w->yplayer = pos / (w->xwidth + 1);
	if (w->xplayer == 0)
		w->xplayer++;
	else if (w->xplayer == w->xwidth - 1)
		w->xplayer--;
	if (w->yplayer == 0)
		w->yplayer++;
	else if (w->yplayer == w->ylength - 1)
		w->yplayer--;
}

int		parse_map(char *map, t_wolf *w)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	w->map = (char **)malloc(sizeof(char*) * w->ylength);
	while (++j < w->ylength)
	{
		w->map[j] = ft_strsub(map, i, w->xwidth);
		i = i + w->xwidth + 1;
	}
	return (1);
}

int		map_tostruct(char *map, t_wolf *w)
{
	parse_playerposition(map, w);
	calc_playercoords(w);
	parse_map(map, w);
	return (1);
}
