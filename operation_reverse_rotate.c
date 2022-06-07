/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:24:36 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/07 19:19:24 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **lst, t_operation index)
{
	t_list	*temp;

	if (*lst && (*lst)->next)
	{
		temp = *lst;
		while (temp->next->next != NULL)
			temp = temp->next;
		ft_lstadd_front(lst, ft_int_lstnew(temp->next->content));
		ft_int_lstdelone(temp->next, &delete_content);
		temp->next = NULL;
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