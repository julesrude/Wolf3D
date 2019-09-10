/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 19:11:14 by yruda             #+#    #+#             */
/*   Updated: 2019/09/06 19:49:36 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_minarr(int *a, int n)
{
	int min;
	int	i;

	i = 1;
	min = *a;
	while (i < n)
	{
		if (min > a[i])
			min = a[i];
		i++;
	}
	return (min);
}

int		ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int		ft_max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}
