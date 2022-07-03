/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap_push.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:14:35 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/03 03:07:12 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	push(t_list **src, t_list **dest, t_operation index)
{
	t_list	*tmp;

	if (*src != NULL)
	{
		tmp = (*src)->next;
		ft_lstadd_front(dest, ft_ps_lstnew((*src)->content, (*src)->pos));
		ft_ps_lstdelone(*src, &delete_content);
		*src = tmp;
	}
	if (index == PA)
		write(1, "pa\n", 3);
	else if (index == PB)
		write(1, "pb\n", 3);
}
