/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:14:12 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/17 11:18:03 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **lst_a, t_list **lst_b, int size_list)
{
	if ((*lst_a)->pos == size_list)
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
	else if ((*lst_a)->pos == size_list - 1)
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
	else
	{
		reverse_rotate(lst_a, RRA);
		if (is_sort(lst_b))
			swap_ab(lst_a, lst_b);
		else
			swap(lst_a, SA);
	}
}
