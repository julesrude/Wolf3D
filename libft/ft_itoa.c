/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:48:58 by yruda             #+#    #+#             */
/*   Updated: 2019/09/06 17:25:49 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_putitoa(int n, int symbols, int index, char *result)
{
	if (n < 0)
	{
		result[0] = '-';
		ft_putitoa(-n, symbols, index, result);
	}
	else
	{
		if (n >= 10 && n <= 2147483647)
			ft_putitoa(n / 10, symbols, index - 1, result);
		result[index] = n % 10 + '0';
		result[index + 1] = '\0';
	}
	return (result);
}

void	ft_itoa_special(int n, char *result)
{
	if (n == -2147483648)
	{
		ft_strcpy(result, "-2147483648\0");
		return ;
	}
	if (n == 0)
	{
		ft_strcpy(result, "0\0");
		return ;
	}
	return ;
}

void		ft_itoa(int n, char *result)
{
	long	temp;
	int		i;

	temp = n;
	i = 0;
	ft_bzero(result, 12);
	if (n == -2147483648 || n == 0)
	{
		ft_itoa_special(n, result);
		return ;
	}
	if (n < 0)
		i++;
	while (temp != 0)
	{
		temp = temp / 10;
		i++;
	}
	ft_putitoa(n, i, i - 1, result);
}
