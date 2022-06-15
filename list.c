/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:47:16 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/15 17:27:08 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare_two_min_position(t_list **lst, int size_list)
{
	t_list	*start;
	int		counter;
	int		targets[3];

	start = *lst;
	counter = 0;
	while (*lst)
	{
		if ((*lst)->pos == 1)
		{
			targets[1] = counter;
			if (targets[1] > 2)
				targets[1] = size_list - targets[1];
		}
		if ((*lst)->pos == 2)
		{
			targets[2] = counter;
			if (targets[2] > 2)
				targets[2] = size_list - targets[2];
		}
		counter++;
		(*lst) = (*lst)->next;
	}
	*lst = start;
	return ((targets[1] > targets[2]) + 1);
}

int	sens_rotate(t_list **lst, int target, int size_list)
{
	t_list	*start;
	int		counter;

	start = *lst;
	counter = 0;
	while (target != (*lst)->pos && target != size_list)
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

void	get_position(t_list **lst)
{
	t_list	*start;	
	t_list	*tmp;	

	start = *lst;
	tmp = *lst;
	while (*lst)
	{
		(*lst)->pos = 1;
		while (tmp)
		{
			if ((*lst)->content > tmp->content)
				(*lst)->pos++;
			tmp = tmp->next;
		}
		*lst = (*lst)->next;
		tmp = start;
	}
	*lst = start;
}

int	is_sort(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	if (!(*lst))
		return (1);
	while ((*lst)->next)
	{
		if ((*lst)->content > (*lst)->next->content)
		{
			*lst = tmp;
			return (0);
		}
		*lst = (*lst)->next;
	}
	*lst = tmp;
	return (1);
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
