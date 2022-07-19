/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_reverse_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:58:27 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/19 14:48:31 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	c_reverse_rotate(t_list **lst)
{
	t_list	*tmp;

	if (*lst && (*lst)->next)
	{
		tmp = *lst;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		ft_lstadd_front(lst, ft_ps_lstnew(tmp->next->data, tmp->next->final));
		ft_ps_lstdelone(tmp->next, &ft_delete_content);
		tmp->next = NULL;
	}
}

void	c_reverse_rotate_double(t_list **lst_a, t_list **lst_b)
{
	c_reverse_rotate(lst_a);
	c_reverse_rotate(lst_b);
}
