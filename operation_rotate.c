/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:23:42 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/13 14:39:12 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **lst, t_operation index)
{
	t_list	*temp;

	if (*lst && (*lst)->next)
	{
		temp = *lst;
		ft_lstadd_back(lst, ft_int_lstnew((*lst)->content, (*lst)->position));
		(*lst) = temp->next;
		free(temp);
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
