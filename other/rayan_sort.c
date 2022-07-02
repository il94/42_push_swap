/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayan_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:57:00 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/29 14:37:18 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rayan_sort(t_list **lst_a, t_list **lst_b, int size_list)
{
	t_list	*start;
	int		i;
	int		move;

	i = 0;
	move = 0;
	start = *lst_a;

	while (ft_lstsize(*lst_b) < size_list)
	{
		if ((*lst_a)->next->content > (*lst_a)->content)
			swap(lst_a, SA);
		push(lst_a, lst_b, PB);
	}
	// print_lists(*lst_a, *lst_b);
	while (*lst_b != 0)
	{
		push(lst_b, lst_a, PA);
	}
}
