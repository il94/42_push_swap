/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:47:16 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/17 21:42:14 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	get_previous_position(t_list **lst, int element)
{
	t_list	*start;
	int		result;

	start = *lst;
	result = 0;
	if (element < get_min_position(*lst))
			result = get_min_position(*lst);
	else
	{
		while ((*lst)->next)
		{
			if (element > (*lst)->final && element < (*lst)->next->final)
				result = (*lst)->next->final;
			*lst = (*lst)->next;
		}
		if (element > (*lst)->final && element < start->final)
			result = start->final;
		*lst = start;
	}
	return (result);
}

void	get_positions(t_list **lst)
{
	t_list	*start;	
	t_list	*tmp;	

	start = *lst;
	tmp = *lst;
	while (*lst)
	{
		(*lst)->final = 1;
		(*lst)->cost = 0;
		while (tmp)
		{
			if ((*lst)->data > tmp->data)
				(*lst)->final++;
			tmp = tmp->next;
		}
		*lst = (*lst)->next;
		tmp = start;
	}
	*lst = start;
}

void	get_list(t_list **list, int nb_parameters, char **parameters)
{
	t_list	*element;
	int		i;

	i = nb_parameters - 1;
	*list = ft_ps_lstnew(ft_atoi(parameters[i--]), 0);
	while (i >= 0)
	{
		element = ft_ps_lstnew(ft_atoi(parameters[i]), 0);
		ft_lstadd_front(list, element);
		i--;
	}
}
