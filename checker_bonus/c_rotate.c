/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:05:29 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/19 14:48:27 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	c_rotate(t_list **lst)
{
	t_list	*tmp;

	if (*lst && (*lst)->next)
	{
		tmp = *lst;
		ft_lstadd_back(lst, ft_ps_lstnew((*lst)->data, (*lst)->final));
		(*lst) = tmp->next;
		free(tmp);
	}
}

void	c_rotate_double(t_list **lst_a, t_list **lst_b)
{
	c_rotate(lst_a);
	c_rotate(lst_b);
}
