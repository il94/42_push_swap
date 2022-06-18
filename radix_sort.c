/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:57:00 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/17 16:48:50 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_list **lst_a, t_list **lst_b, int size_list)
{
	t_list	*start;
	int		i;
	int		move;

	i = 0;
	move = 0;
	start = *lst_a;
	print_all_bits(*lst_a, *lst_b);
	while (move < 32)
	{
		while (i < size_list && (*lst_a))
		{
			if (((*lst_a)->content >> move) & 1)
				push(lst_a, lst_b, PB);
			else
				rotate(lst_a, RA);
			i++;
		}
		while (*lst_b)
		{
				push(lst_b, lst_a, PA);
		}
		i = 0;
		move++;
	}
	print_all_bits(*lst_a, *lst_b);
}
