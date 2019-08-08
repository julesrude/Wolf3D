/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 20:53:15 by yruda             #+#    #+#             */
/*   Updated: 2019/07/30 21:07:57 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	char	*start;

	start = s1;
	while (*s1++)
		continue ;
	s1 = s1 - 1;
	while ((*s1++ = *s2++))
		continue ;
	return (start);
}

char	ft_strcat_last(char *restrict s1, const char *restrict s2)
{
	int		i;

	i = 0;
	while (*s1++)
		continue ;
	s1 = s1 - 1;
	while (s1[i] && s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1[i - 1]);
}
