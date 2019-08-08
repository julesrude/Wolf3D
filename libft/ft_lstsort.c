/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yruda <yruda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:34:37 by yruda             #+#    #+#             */
/*   Updated: 2019/07/24 17:29:17 by yruda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	list_swap_neigh(t_list **head, t_list *a, t_list *b)
{
	t_list	*temp;

	temp = NULL;
	a->next = b->next;
	b->next = a;
	if (*head == a)
		(*head) = b;
	else
	{
		temp = *head;
		while (temp->next != a)
			temp = temp->next;
		temp->next = b;
	}
}

void	ft_lstsortalpha(t_list **head, t_list *current)
{
	if (current->next->next)
		ft_lstsortalpha(head, current->next);
	if (ft_strcmp(current->content, current->next->content) > 0)
		list_swap_neigh(head, current, current->next);
}

void	ft_lstsortcycle(t_list **head, t_list *current)
{
	int		i;
	int		n;

	i = 0;
	n = ft_lstsize(*head);
	while (i < n - 1)
	{
		current = *head;
		ft_lstsortalpha(head, ft_lstat(current, i + 1));
		i++;
	}
}
