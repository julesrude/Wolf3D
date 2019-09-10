/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_scheme.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 22:32:01 by yruda             #+#    #+#             */
/*   Updated: 2019/09/09 16:41:25 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"


int		get_shadedcolor(t_wall wall, int color)
{
	double	frac;
	int		r;
	int		g;
	int		b;

	if (wall.height >= WIN_H)
		frac = 1.0;
	else
	{
		frac = 1.0 - (double)wall.height / WIN_H;
		frac = 1.0 - frac * frac;
	}
//	if (psycho)
//		frac *= 3;
	r = (int)(((color >> 16) & 0xFF) * frac);
	g = (int)(((color >> 8) & 0xFF) * frac);
	b = (int)((color & 0xFF) * frac);
	return (0 | r << 16 | g << 8 | b);
}

