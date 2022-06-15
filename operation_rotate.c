/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:23:42 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/15 17:28:56 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
