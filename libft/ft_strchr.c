/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 17:35:36 by yruda             #+#    #+#             */
/*   Updated: 2019/08/08 15:16:51 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** function locates the first occurrence of c (converted to a char)
** in the string pointed to by s. The terminating null character is
** considered to be part of the string; therefore if c is `\0', the func-
** tions locate the terminating `\0'.
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		if (*s++)
			continue ;
	}
	if (*s == '\0' && c == '\0')
		return ((char *)s);
	return (NULL);
}

/*
**	function locates the first occurrence of c (converted to a char)
**	in the string pointed to by s.
**	returns index of the char in the string.
**	returns (-1) if there is no such char in the string.
*/

int		ft_strchrindex(const char *s, int c)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		if (*s == c)
			return (i);
		i++;
		if (*s++)
			continue ;
	}
	if (*s == '\0' && c == '\0')
		return (i);
	return (-1);
}
