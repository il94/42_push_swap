/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:25:31 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/13 22:22:54 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_list **lst_a, t_list **lst_b, int size_list)
{
	t_list	*temp;

	get_position(lst_a);
			// print_lists(*lst_a, *lst_b);

	while (!is_sort(lst_a))
	{
		// printf("content = %d\n", (*lst_a)->position);
		// if ((*lst_a)->position == ((*lst_a)->next->position - 1))
		// 	swap(lst_a, SA);
		if ((*lst_a)->position < size_list / 2)
		{
			push(lst_a, lst_b, PB);
			while ((*lst_b)->position == (*lst_a)->position - 1 && (*lst_a)->next)
			{
				push(lst_a, lst_b, PB);
			}
						// print_lists(*lst_a, *lst_b);
			while ((*lst_b)->position != (*lst_a)->position - 1 && (*lst_a)->next)
			{
				// printf("test\n");
				if (sens_rotate(lst_a, (*lst_b)->position, size_list))
					rotate(lst_a, RA);
				else
					reverse_rotate(lst_a, RRA);
			}
							// printf("Debug\n");

			while (*lst_b)
			{
					// printf("Debug\n");
				push(lst_b, lst_a, PA);
			}
			// push(lst_b, lst_a, PA);
		}
		if (sens_rotate(lst_a, (*lst_a)->position, size_list))
			reverse_rotate(lst_a, RRA);
		else
			rotate(lst_a, RA);
		// reverse_rotate(lst_a, RRA);
			// print_lists(*lst_a, *lst_b);
	}
}
