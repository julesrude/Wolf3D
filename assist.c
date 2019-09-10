/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:45:30 by yruda             #+#    #+#             */
/*   Updated: 2019/09/08 21:46:26 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <sys/time.h>

t_point	coords_to_block(double x, double y, t_wolf *w)
{
	t_point	blk;

	blk.x = x / BLKSIZE;
	if (blk.x >= w->xwidth)
		blk.x = w->xwidth - 1;
	else if (blk.x < 0)
		blk.x = 0;
	blk.y = (y) / BLKSIZE;
	if (blk.y >= w->ylength)
		blk.y = w->ylength - 1;
	else if (blk.y < 0)
		blk.y = 0;
	return (blk);
}

int		point_iswall(double x, double y, t_wolf *w)
{
	t_point		b;

	b = coords_to_block(x, y, w);
	return (ISWALL(w->map[b.y][b.x]));
}

long int	get_now_time()
{
	struct timeval	now_time;
	
	gettimeofday(&now_time, NULL);
	return (now_time.tv_sec * 1000000 + now_time.tv_usec);
}

char	*ft_strrealloc(char *s, int numcols)
{
	char	*result;
	int		i;
	int		j;
	int		r;

	i = 0;
	j = 0;
	r = 0;
	result = NULL;
	if (!(result = ft_strnew(sizeof(char) *	(ft_strlen(s) + numcols + 2))))
		return (NULL);
	ft_strcpy(result, s);
	if (s)
		free (s);
	return (result);
}
