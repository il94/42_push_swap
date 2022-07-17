/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:54:24 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/17 22:43:39 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_costs(t_list *lst_a, t_list *lst_b, int size_list_b)
{
	t_list	*tmp_a;
	int		index_list_b;
	int		target;

	tmp_a = lst_a;
	index_list_b = 0;
	while (lst_b)
	{
		lst_b->cost = 0;
		target = get_previous_position(&lst_a, lst_b->final);
		while (tmp_a && tmp_a->final != target)
		{
			lst_b->cost += 1;
			tmp_a = tmp_a->next;
		}
		if (lst_b->cost >= ft_lstsize(lst_a) / 2)
			lst_b->cost = ft_lstsize(lst_a) - lst_b->cost + 1;
		if (index_list_b <= size_list_b / 2)
			lst_b->cost += index_list_b;
		else
			lst_b->cost += (size_list_b - index_list_b);
		index_list_b++;
		lst_b = lst_b->next;
		tmp_a = lst_a;
	}
}

void	push_to_b(t_list **lst_a, t_list **lst_b, int size_list)
{
	int	range;

	range = size_list / 3;
	while (ft_lstsize(*lst_a) > range)
	{
		if ((*lst_a)->final <= size_list - range)
		{
			push(lst_a, lst_b, PB);
			if ((*lst_b)->final <= range)
				rotate(lst_b, RB);
		}
		else
			rotate(lst_a, RA);
	}
	while (ft_lstsize(*lst_a) > 3)
	{
		if ((!is_max(*lst_a, (*lst_a)->final + 2)))
			push(lst_a, lst_b, PB);
		else
			rotate(lst_a, RA);
	}
}

void	sort_big(t_list **lst_a, t_list **lst_b, int size_list)
{
	int	target;

	push_to_b(lst_a, lst_b, size_list);
	sort_three(lst_a);
	while (*lst_b)
	{
		get_costs(*lst_a, *lst_b, ft_lstsize(*lst_b));
		target = get_min_cost(*lst_b);
		bring_up_element(lst_b, target, LSTB);
		if ((*lst_b)->final == target)
		{
			bring_up_element(lst_a, get_previous_position(lst_a, target), LSTA);
			push(lst_b, lst_a, PA);
		}
	}
	bring_up_element(lst_a, get_min_position(*lst_a), LSTA);
}
