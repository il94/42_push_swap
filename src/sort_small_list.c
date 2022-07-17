/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:35:50 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/17 22:43:33 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_list **lst_a)
{
	if (is_max(*lst_a, (*lst_a)->final))
		rotate(lst_a, RA);
	else if (is_max(*lst_a, (*lst_a)->next->final))
		reverse_rotate(lst_a, RRA);
	if ((*lst_a)->final > (*lst_a)->next->final)
		swap(lst_a, SA);
}

void	sort_four(t_list **lst_a, t_list **lst_b)
{
	bring_up_element(lst_a, get_min_position(*lst_a), LSTA);
	if (!is_sort(lst_a))
	{
		push(lst_a, lst_b, PB);
		sort_three(lst_a);
		push(lst_b, lst_a, PA);
	}
}

void	sort_five(t_list **lst_a, t_list **lst_b)
{
	while (ft_lstsize(*lst_a) > 3)
	{
		if ((*lst_a)->final < 3)
			push(lst_a, lst_b, PB);
		else
			rotate(lst_a, RA);
	}
	sort_three(lst_a);
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
		sort_three(lst_a);
	else if (nb_parameters == 4)
		sort_four(lst_a, lst_b);
	else if (nb_parameters == 5)
		sort_five(lst_a, lst_b);
	else
		sort_big(lst_a, lst_b, nb_parameters);
}
