/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:13:03 by yruda             #+#    #+#             */
/*   Updated: 2019/07/25 15:13:18 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstreverse(t_list **head)
{
	t_list	*prev;
	t_list	*current;

	if (!head || !(*head))
		return (NULL);
	prev = *head;
	*head = (prev->next);
	prev->next = NULL;
	current = (*head);
	while (current)
	{
		*head = (*head)->next;
		current->next = prev;
		prev = current;
		current = (*head);
	}
	(*head) = prev;
	return (*head);
}
