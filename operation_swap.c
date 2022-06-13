/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:14:35 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/13 21:01:30 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **lst, t_operation index)
{
	t_list	*temp;

	temp = malloc(sizeof(*temp));
	if (*lst && (*lst)->next)
	{
		temp->content = (*lst)->content;
		temp->position = (*lst)->position;
		(*lst)->content = (*lst)->next->content;
		(*lst)->position = (*lst)->next->position;
		(*lst)->next->content = temp->content;
		(*lst)->next->position = temp->position;
	}
	free(temp);
	if (index == SA)
		write(1, "sa\n", 3);
	else if (index == SB)
		write(1, "sb\n", 3);
}

void	swap_ab(t_list **lst_a, t_list **lst_b)
{
	swap(lst_a, NOTHING);
	swap(lst_b, NOTHING);
	write(1, "ss\n", 3);
}
