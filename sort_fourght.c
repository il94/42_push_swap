/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fourght.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:52:08 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/29 17:52:09 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_fourght(t_list **lst_a, t_list **lst_b, int size_list)
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
