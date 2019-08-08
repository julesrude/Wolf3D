/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 19:11:14 by yruda             #+#    #+#             */
/*   Updated: 2019/01/26 19:18:15 by yruda            ###   ########.fr       */
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
