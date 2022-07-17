/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:21:18 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/17 21:36:41 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sens_rotate(t_list **lst, int target)
{
	t_list	*start;
	int		counter;
	int		size_list;

	start = *lst;
	counter = 0;
	size_list = ft_lstsize(*lst);
	while (target != (*lst)->final)
	{
		counter++;
		if ((*lst)->next == NULL)
			(*lst) = start;
		else
			(*lst) = (*lst)->next;
	}
	*lst = start;
	if (counter <= size_list / 2)
		return (1);
	else
		return (0);
}

int	is_max(t_list *lst, int element)
{
	if (lst)
	{
		while (lst && element >= lst->final)
			lst = lst->next;
		if (!lst)
			return (1);
	}
	return (0);
}

int	is_sort(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	if (!(*lst))
		return (1);
	while ((*lst)->next)
	{
		if ((*lst)->data > (*lst)->next->data)
		{
			*lst = tmp;
			return (0);
		}
		*lst = (*lst)->next;
	}
	*lst = tmp;
	return (1);
}
