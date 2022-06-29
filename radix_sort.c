/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:57:00 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/29 18:22:31 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
