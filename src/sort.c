/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:54:24 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/09 22:23:52 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_cost(t_list **lst_a, t_list **lst_b)
{
	int	coup;
	int	target;
	int	insert_place;

	target = get_min_cost(*lst_b);
	insert_place = get_insert_place(lst_a, target);
	if ((*lst_b)->pos_final == target)
	{
		if (sens_rotate(lst_a, insert_place))
		{
			while (!is_last(lst_a, insert_place))
				rotate(lst_a, RA);
			push(lst_b, lst_a, PA);
		}
		else
		{
			while (!is_last(lst_a, insert_place))
				reverse_rotate(lst_a, RRA);
			push(lst_b, lst_a, PA);
		}
	}
	else
	{
		if (sens_rotate(lst_b, target))
		{
			while ((*lst_b)->pos_final != target)
				rotate(lst_b, RB);
		}
		else
		{
			while ((*lst_b)->pos_final != target)
				reverse_rotate(lst_b, RRB);
		}
	}
}

void	get_costs(t_list *lst_a, t_list *lst_b)
{
	t_list	*tmp_a;
	int		size_list_b;
	int		index_list_b;
	int		target;

	tmp_a = lst_a;
	size_list_b = ft_lstsize(lst_b);
	index_list_b = 0;
	while (lst_b)
	{
		lst_b->cost = 0;
			target = get_insert_place(&lst_a, lst_b->pos_final);
			while (tmp_a && tmp_a->pos_final <= target)
			{
				lst_b->cost += 1;
				tmp_a = tmp_a->next;
			}
			if (lst_b->cost == 0 && target != ft_lstlast(lst_a)->pos_final)
			{
				tmp_a = lst_a;
				while (tmp_a && tmp_a->pos_final >= target)
				{
					lst_b->cost += 1;
					tmp_a = tmp_a->next;
				}
			}
			if (index_list_b <= size_list_b / 2)
				lst_b->cost += index_list_b;
			else
				lst_b->cost += (size_list_b - index_list_b);
		index_list_b++;
		lst_b = lst_b->next;
		tmp_a = lst_a;
	}
}

void	sort(t_list **lst_a, t_list **lst_b, int size_list)
{
	while (ft_lstsize(*lst_a) != 3 && !is_sort(lst_a))
	{
		while (is_3_max(*lst_a, (*lst_a)->pos_final))
		{
			if (*lst_b && !is_min(*lst_b, (*lst_b)->pos_final))
				rotate_ab(lst_a, lst_b);
			else
				rotate(lst_a, RA);
		}
		push(lst_a, lst_b, PB);
	}
	sort_three(lst_a, lst_b);
	if (!is_sort_reverse(lst_b))
	{
		while (*lst_b && ft_lstsize(*lst_b) > 1 && (is_max(*lst_b, (*lst_b)->pos_final) || is_min(*lst_b, (*lst_b)->pos_final)))
		{
			push(lst_b, lst_a, PA);
			if ((*lst_a)->pos_final != (*lst_a)->next->pos_final - 1 || (is_min(*lst_b, (*lst_a)->pos_final)))
				rotate_ab(lst_a, lst_b);
			else
				rotate(lst_b, RB);
		}
	}
	while (*lst_b)
	{
		get_costs(*lst_a, *lst_b);
		// print_lists(*lst_a, *lst_b);
		while ((*lst_b)->cost == 0 && ft_lstsize(*lst_b) != 1) /* push une suite (a verifier) */
		{
			push(lst_b, lst_a, PA);
			get_costs(*lst_a, *lst_b);
		}
		// printf("==============START=============\n");
		// print_lists(*lst_a, *lst_b);
		push_cost(lst_a, lst_b);
		// printf("==============END=============\n");
		// push(lst_b, lst_a, PA); /* debug */
		// printf("Debug\n");

/*============================================================================*/
	}
	while (!is_sort(lst_a))
	{
		// print_lists(*lst_a, *lst_b);
		if (sens_rotate(lst_a, get_min_position(*lst_a)))
			rotate(lst_a, RA);
		else
			reverse_rotate(lst_a, RRA);
	}

}
