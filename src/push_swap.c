/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:35:50 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/03 03:07:17 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_list **lst_a, t_list **lst_b, int size_list)
{
	if ((*lst_a)->pos == size_list)
		rotate(lst_a, RA);
	else if ((*lst_a)->next->pos == size_list)
		reverse_rotate(lst_a, RRA);
	if ((*lst_a)->pos > (*lst_a)->next->pos)
	{
		if (is_sort(lst_b))
			swap_ab(lst_a, lst_b);
		else
			swap(lst_a, SA);
	}
}

void	sort_four(t_list **lst_a, t_list **lst_b, int size_list)
{
	if (sens_rotate(lst_a, 1, size_list))
	{
		while ((*lst_a)->pos != 1)
			rotate(lst_a, RA);
	}
	else
	{
		while ((*lst_a)->pos != 1)
			reverse_rotate(lst_a, RRA);
	}
	if (!is_sort(lst_a))
	{
		push(lst_a, lst_b, PB);
		sort_three(lst_a, lst_b, size_list);
		push(lst_b, lst_a, PA);
	}
}

void	sort_five(t_list **lst_a, t_list **lst_b, int size_list)
{
	int		target;

	target = compare_two_min_position(lst_a, size_list);
	while (ft_lstsize((*lst_b)) != 2)
	{
		if (sens_rotate(lst_a, target, size_list))
		{
			while ((*lst_a)->pos != target)
				rotate(lst_a, RA);
		}
		else
		{
			while ((*lst_a)->pos != target)
				reverse_rotate(lst_a, RRA);
		}
		push(lst_a, lst_b, PB);
		if (target == 2)
			target = 0;
		target++;
	}
	sort_three(lst_a, lst_b, size_list);
	if ((*lst_b)->pos < (*lst_b)->next->pos)
		swap(lst_b, SB);
	while (*lst_b)
		push(lst_b, lst_a, PA);
}

void	radix_sort(t_list **lst_a, t_list **lst_b, int size_list)
{
	int		bit;
	int		move;

	bit = 0;
	move = 0;
	while (!is_sort(lst_a))
	{
		while (bit < size_list && (*lst_a))
		{
			if (!(((*lst_a)->pos >> move) & 1))
				push(lst_a, lst_b, PB);
			else
				rotate(lst_a, RA);
			bit++;
		}
		while (*lst_b)
			push(lst_b, lst_a, PA);
		bit = 0;
		move++;
	}
}

void	push_swap(t_list **lst_a, t_list **lst_b, int nb_parameters)
{
	if (nb_parameters == 2)
		swap(lst_a, SA);
	else if (nb_parameters == 3)
		sort_three(lst_a, lst_b, nb_parameters);
	else if (nb_parameters == 4)
		sort_four(lst_a, lst_b, nb_parameters);
	else if (nb_parameters == 5)
		sort_five(lst_a, lst_b, nb_parameters);
	else
		radix_sort(lst_a, lst_b, nb_parameters);
}
