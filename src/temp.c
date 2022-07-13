/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:21:18 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/13 18:20:06 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sort_reverse(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	if (!(*lst))
		return (1);
	while ((*lst)->next)
	{
		if ((*lst)->data < (*lst)->next->data)
		{
			*lst = tmp;
			return (0);
		}
		*lst = (*lst)->next;
	}
	*lst = tmp;
	return (1);
}

int	is_last(t_list **lst, int element)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->final == element)
		return (1);
	return (0);
}

int	get_insert_place(t_list **lst, int element)
{
	t_list	*start;
	int		result;

	start = *lst;
	result = 0;
	if (element < get_min_position(*lst))
	{
		// if (is_sort(lst))
			result = get_min_position(*lst);
		// else
		// 	result = get_max_position(*lst);
		// printf("test = %d\n", result);
	}
	else
	{
		while ((*lst)->next)
		{
			if (element > (*lst)->final && element < (*lst)->next->final)
				result = (*lst)->next->final;
			*lst = (*lst)->next;
		}
		// printf("test = %d\n", result);
		if (element > (*lst)->final && element < start->final)
		{
			// printf("IF\n");
			result = start->final;
		}
		// if (result > element)
		// {
		// 	printf("IF\n");
		// 	result = start->final;
		// }
		*lst = start;
	}
	return (result);
}

int	get_min_cost(t_list *lst)
{
	int	result;
	int	i;
	
	i = lst->cost;
	result = lst->final;
	while (lst)
	{
		if (i > lst->cost)
		{
			i = lst->cost;
			result = lst->final;
		}
		lst = lst->next;
	}
	return (result);
}

int	get_min_position(t_list *lst)
{
	int	result;
	
	result = lst->final;
	while (lst)
	{
		if (result > lst->final)
			result = lst->final;
		lst = lst->next;
	}
	return (result);
}

int	get_max_position(t_list *lst)
{
	int	result;
	
	result = lst->final;
	while (lst)
	{
		if (result < lst->final)
			result = lst->final;
		lst = lst->next;
	}
	return (result);
}

int	get_second_position(t_list *lst)
{
	int	result;
	
	result = lst->final;
	while (lst)
	{
		if (result > lst->final && result < get_min_position(lst))
			result = lst->final;
		lst = lst->next;
	}
	return (result);
}

int	is_min(t_list *lst, int element)
{
	// printf("debug is min\n");
	if (lst)
	{
		while (lst && element <= lst->final)
			lst = lst->next;
		if (!lst)
			return (1);
	}
	return (0);
}

int	is_max(t_list *lst, int element)
{
	// printf("debug is max\n");
	if (lst)
	{
		while (lst && element >= lst->final)
			lst = lst->next;
		if (!lst)
			return (1);
	}
	return (0);
}

int	is_3_max(t_list *lst, int element)
{
	while (lst && (element >= lst->final || element >= lst->final - 1
			|| element >= lst->final - 2))
		lst = lst->next;
	if (!lst)
		return (1);
	return (0);
}