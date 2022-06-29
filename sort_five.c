/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:53:23 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/29 18:16:04 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
