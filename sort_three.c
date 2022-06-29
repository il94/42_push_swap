/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:14:12 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/29 18:16:26 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	max_is_first(t_list **lst_a, t_list **lst_b, int size_list)
{
	rotate(lst_a, RA);
	if ((*lst_a)->pos > (*lst_a)->next->pos)
	{
		if (is_sort(lst_b))
			swap_ab(lst_a, lst_b);
		else
			swap(lst_a, SA);
	}
}

void	mid_is_first(t_list **lst_a, t_list **lst_b, int size_list)
{
	if ((*lst_a)->pos > (*lst_a)->next->pos)
	{
		if (is_sort(lst_b))
			swap_ab(lst_a, lst_b);
		else
			swap(lst_a, SA);
	}
	else
		reverse_rotate(lst_a, RRA);
}

void	min_is_first(t_list **lst_a, t_list **lst_b, int size_list)
{
	reverse_rotate(lst_a, RRA);
	if (is_sort(lst_b))
		swap_ab(lst_a, lst_b);
	else
		swap(lst_a, SA);
}

void	sort_three(t_list **lst_a, t_list **lst_b, int size_list)
{
	if (!is_sort(lst_a))
	{
		if ((*lst_a)->pos == size_list)
			max_is_first(lst_a, lst_b, size_list);
		else if ((*lst_a)->pos == size_list - 1)
			mid_is_first(lst_a, lst_b, size_list);
		else
			min_is_first(lst_a, lst_b, size_list);
	}
}
