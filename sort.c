/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:25:31 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/09 12:23:28 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_list **lst_a, t_list **lst_b, int size_list)
{
	int		median_list;
	t_list	*temp;
	t_list	*temp_2;

	median_list = get_median_list(lst_a, size_list);
	// printf("median = %d & size = %d\n", median_list, size_list);
	while (ft_lstsize(*lst_b) < (size_list / 2))
	{
		if ((*lst_a)->content <= median_list)
			push(lst_a, lst_b, PA);
		rotate(lst_a, RA);
	}
/*====================================================================*/
	temp = *lst_a;
	temp_2 = *lst_a;
	while (temp->next)
	{
		while ((*lst_a)->next)
		{
			if ((*lst_a)->content > (*lst_a)->next->content)
				swap(lst_a, SA);
			*lst_a = (*lst_a)->next;
		}
		temp = temp->next;
		*lst_a = temp_2;
	}
/*====================================================================*/
	temp = *lst_b;
	temp_2 = *lst_b;
	while (temp->next)
	{
		while ((*lst_b)->next)
		{
			if ((*lst_b)->content < (*lst_b)->next->content)
				swap(lst_b, SA);
			*lst_b = (*lst_b)->next;
		}
		temp = temp->next;
		*lst_b = temp_2;
	}
/*====================================================================*/
	while (ft_lstsize(*lst_b) > 0)
		push(lst_b, lst_a, PB);
}
