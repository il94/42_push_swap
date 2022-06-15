/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:14:35 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/15 17:26:13 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **lst, t_operation index)
{
	t_list	*tmp;

	tmp = malloc(sizeof(*tmp));
	if (*lst && (*lst)->next)
	{
		tmp->content = (*lst)->content;
		tmp->pos = (*lst)->pos;
		(*lst)->content = (*lst)->next->content;
		(*lst)->pos = (*lst)->next->pos;
		(*lst)->next->content = tmp->content;
		(*lst)->next->pos = tmp->pos;
	}
	free(tmp);
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
