/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:24:36 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/07 16:28:37 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **lst)
{
	t_list	*temp;

	if ((*lst) != NULL)
	{
		temp = *lst;
		while (temp->next->next != NULL)
			temp = temp->next;
		ft_lstadd_front(lst, ft_lstnew(temp->next->content));
		ft_lstdelone(temp->next, &delete_content);
		temp->next = NULL;
	}
}

void	reverse_rotate_ab(t_list **lst_a, t_list **lst_b)
{
	reverse_rotate(lst_a);
	reverse_rotate(lst_b);
}