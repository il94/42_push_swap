/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:35:50 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/13 18:24:17 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_list **lst_a, t_list **lst_b)
{
	if (is_max(*lst_a, (*lst_a)->final))
		rotate(lst_a, RA);
	else if (is_max(*lst_a, (*lst_a)->next->final))
		reverse_rotate(lst_a, RRA);
	if ((*lst_a)->final > (*lst_a)->next->final)
	{
		if (*lst_b && (*lst_b)->final < (*lst_b)->next->final
			&& (*lst_b)->final != get_min_position(*lst_b))
			swap_ab(lst_a, lst_b);
		else
			swap(lst_a, SA);
	}
}

void	sort_four(t_list **lst_a, t_list **lst_b)
{
	if (sens_rotate(lst_a, get_min_position(*lst_a)))
	{
		while ((*lst_a)->final != 1)
			rotate(lst_a, RA);
	}
	else
	{
		while ((*lst_a)->final != 1)
			reverse_rotate(lst_a, RRA);
	}
	if (!is_sort(lst_a))
	{
		push(lst_a, lst_b, PB);
		sort_three(lst_a, lst_b);
		push(lst_b, lst_a, PA);
	}
}

void	sort_five(t_list **lst_a, t_list **lst_b)
{
	int		target;

	target = compare_two_min_position(lst_a);
	while (ft_lstsize((*lst_b)) != 2)
	{
		if (sens_rotate(lst_a, target))
		{
			while ((*lst_a)->final != target)
				rotate(lst_a, RA);
		}
		else
		{
			while ((*lst_a)->final != target)
				reverse_rotate(lst_a, RRA);
		}
		push(lst_a, lst_b, PB);
		if (target == 2)
			target = 0;
		target++;
	}
	sort_three(lst_a, lst_b);
	if ((*lst_b)->final < (*lst_b)->next->final)
		swap(lst_b, SB);
	while (*lst_b)
		push(lst_b, lst_a, PA);
}

void	push_swap(t_list **lst_a, t_list **lst_b, int nb_parameters)
{
	if (nb_parameters == 2)
		swap(lst_a, SA);
	else if (nb_parameters == 3)
		sort_three(lst_a, lst_b);
	else if (nb_parameters == 4)
		sort_four(lst_a, lst_b);
	else if (nb_parameters == 5)
		sort_five(lst_a, lst_b);
	else
		sort_big(lst_a, lst_b, nb_parameters);
}
