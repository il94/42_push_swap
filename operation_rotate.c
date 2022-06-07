/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:23:42 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/07 16:23:16 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **lst)
{
	t_list	*temp;

	if ((*lst) != NULL)
	{
		temp = *lst;
		ft_lstadd_back(lst, ft_lstnew((*lst)->content));
		(*lst) = temp->next;
		free(temp);
	}
}

void	rotate_ab(t_list **lst_a, t_list **lst_b)
{
	rotate(lst_a);
	rotate(lst_b);
}