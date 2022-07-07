/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:54:24 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/07 18:17:19 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_costs(t_list *lst_a, t_list *lst_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		size_list_b;
	int		index_list;

	tmp_a = lst_a;
	tmp_b = lst_b;
	size_list_b = ft_lstsize(lst_b);
	index_list = 0;
	while (lst_b)
	{
		while (tmp_a)
		{
			if (tmp_a->pos_final < lst_b->pos_final)
				lst_b->cost += 1;
			tmp_a = tmp_a->next;
		}
		if (index_list <= size_list_b / 2)
		{
			printf("IF\n");
			lst_b->cost += index_list;
		}
		else
		{
			printf("ELSE\n");
			lst_b->cost += (size_list_b - index_list);
		}
		index_list++;
		lst_b = lst_b->next;
		tmp_a = lst_a;
	}
}

void	sort(t_list **lst_a, t_list **lst_b, int size_list)
{
	while (ft_lstsize(*lst_a) != 3)
	{
		while (is_3_max(*lst_a, (*lst_a)->pos_final))
		{
			// if (*lst_b && !is_min(*lst_b, (*lst_b)->pos_final))
			// 	rotate_ab(lst_a, lst_b);
			// else
				rotate(lst_a, RA);
		}
		push(lst_a, lst_b, PB);
	}
	sort_three(lst_a, lst_b);
	push(lst_b, lst_a, PA);
	// print_lists(*lst_a, *lst_b);
	get_costs(*lst_a, *lst_b);
	// print_lists(*lst_a, *lst_b);
	while (*lst_b)
	{
/*============================================================================*/
		if (*lst_b && (is_max(*lst_b, (*lst_b)->pos_final) || is_min(*lst_b, (*lst_b)->pos_final)))
		{
			push(lst_b, lst_a, PA);
			if ((*lst_a)->pos_final != (*lst_a)->next->pos_final)
			{
				// rotate(lst_a, RA);
				rotate_ab(lst_a, lst_b);
			}
			else
				rotate(lst_b, RB);
		}
		push(lst_b, lst_a, PA);
		
/*============================================================================*/

	}
	// while (!is_sort(lst_a))
	{
		// if (sens_rotate(lst_a, get_min_position(*lst_a)))
		// {
		// 	rotate(lst_a, RA);
		// }
		// else
		// {
			// reverse_rotate(lst_a, RRA);
		// }
	}
	// printf("is min = %d\n", get_max_position(*lst_a));
	// while (lst_b)
	// {
	// 	get_costs(lst_a, lst_b);
	// }
}