/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate_reverse.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:23:42 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/03 03:07:10 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_list **lst, t_operation index)
{
	t_list	*tmp;

	if (*lst && (*lst)->next)
	{
		tmp = *lst;
		ft_lstadd_back(lst, ft_ps_lstnew((*lst)->content, (*lst)->pos));
		(*lst) = tmp->next;
		free(tmp);
	}
	if (index == RA)
		write(1, "ra\n", 3);
	else if (index == RB)
		write(1, "rb\n", 3);
}

void	rotate_ab(t_list **lst_a, t_list **lst_b)
{
	rotate(lst_a, NOTHING);
	rotate(lst_b, NOTHING);
	write(1, "rr\n", 3);
}

void	reverse_rotate(t_list **lst, t_operation index)
{
	t_list	*tmp;

	if (*lst && (*lst)->next)
	{
		tmp = *lst;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		ft_lstadd_front(lst, ft_ps_lstnew(tmp->next->content, tmp->next->pos));
		ft_ps_lstdelone(tmp->next, &delete_content);
		tmp->next = NULL;
	}
	if (index == RRA)
		write(1, "rra\n", 4);
	else if (index == RRB)
		write(1, "rrb\n", 4);
}

void	reverse_rotate_ab(t_list **lst_a, t_list **lst_b)
{
	reverse_rotate(lst_a, NOTHING);
	reverse_rotate(lst_b, NOTHING);
	write(1, "rrr\n", 4);
}
