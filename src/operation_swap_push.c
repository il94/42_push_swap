/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap_push.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:14:35 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/13 18:19:50 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **lst, t_operation index)
{
	t_list	*tmp;

	tmp = malloc(sizeof(*tmp));
	if (*lst && (*lst)->next)
	{
		tmp->data = (*lst)->data;
		tmp->final = (*lst)->final;
		(*lst)->data = (*lst)->next->data;
		(*lst)->final = (*lst)->next->final;
		(*lst)->next->data = tmp->data;
		(*lst)->next->final = tmp->final;
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

void	push(t_list **src, t_list **dest, t_operation index)
{
	t_list	*tmp;

	if (*src != NULL)
	{
		tmp = (*src)->next;
		ft_lstadd_front(dest, ft_ps_lstnew((*src)->data, (*src)->final));
		ft_ps_lstdelone(*src, &ft_delete_content);
		*src = tmp;
	}
	if (index == PA)
		write(1, "pa\n", 3);
	else if (index == PB)
		write(1, "pb\n", 3);
}
