/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:54:24 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/13 18:37:47 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	up_target_lst_a(t_list **lst_a, t_list **lst_b, int target, int insert_place)
{
	if ((*lst_b)->final == target)
	{
		if (sens_rotate(lst_a, insert_place))
		{
			while ((*lst_a)->final != insert_place)
				rotate(lst_a, RA);
			push(lst_b, lst_a, PA);
		}
		else
		{
			while ((*lst_a)->final != insert_place)
				reverse_rotate(lst_a, RRA);
			push(lst_b, lst_a, PA);
		}
	}
}

void	up_target_lst_b(t_list **lst_b, int target)
{
	if (sens_rotate(lst_b, target))
	{
		while ((*lst_b)->final != target)
			rotate(lst_b, RB);
	}
	else
	{
		while ((*lst_b)->final != target)
			reverse_rotate(lst_b, RRB);
	}
}

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
		target = get_insert_place(&lst_a, lst_b->final);
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
	int	i;
	int	range;

	i = 0;
	range = size_list - (size_list % 3);
	while (i < 3)
	{
		range -= (size_list / 3);
		while (ft_lstsize(*lst_a) > range + 3)
		{
			if ((*lst_a)->final >= range && (!is_3_max(*lst_a, (*lst_a)->final)))
				push(lst_a, lst_b, PB);
			else
			{
				if (*lst_b && !is_min(*lst_b, (*lst_b)->final))
					rotate_ab(lst_a, lst_b);
				else
					rotate(lst_a, RA);
			}
		}
		i++;
	}
}

void	sort_big(t_list **lst_a, t_list **lst_b, int size_list)
{
	push_to_b(lst_a, lst_b, size_list);
	sort_three(lst_a, lst_b);
	while (*lst_b)
	{
		get_costs(*lst_a, *lst_b, ft_lstsize(*lst_b));
		while ((*lst_b)->cost == 0 && ft_lstsize(*lst_b) != 1)
		{
			push(lst_b, lst_a, PA);
			get_costs(*lst_a, *lst_b, ft_lstsize(*lst_b));
		}
		up_target_lst_b(lst_b, get_min_cost(*lst_b));
		up_target_lst_a(lst_a, lst_b, get_min_cost(*lst_b), get_insert_place(lst_a, get_min_cost(*lst_b)));
	}
	while (!is_sort(lst_a))
	{
		if (sens_rotate(lst_a, get_min_position(*lst_a)))
			rotate(lst_a, RA);
		else
			reverse_rotate(lst_a, RRA);
	}
}
