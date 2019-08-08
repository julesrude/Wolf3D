/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_multiple.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 17:45:59 by yruda             #+#    #+#             */
/*   Updated: 2019/07/28 22:34:34 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_four(char *c1, char *c2, char *c3, char *c4)
{
	if (c1 == NULL || c2 == NULL)
		return ;
	ft_putstr(c1);
	ft_putstr(c2);
	ft_putstr(c3);
	ft_putstr(c4);
}

void	ft_putendl_four(char *c1, char *c2, char *c3, char *c4)
{
	if (c1 == NULL || c2 == NULL)
		return ;
	ft_putstr(c1);
	ft_putstr(c2);
	ft_putstr(c3);
	ft_putendl(c4);
}
