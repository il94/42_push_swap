/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:02:32 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/19 14:48:16 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	c_swap(t_list **lst)
{
	t_list	*tmp;

	if (*lst && (*lst)->next)
	{
		tmp = (*lst)->next;
		(*lst)->next = (*lst)->next->next;
		ft_lstadd_front(lst, ft_ps_lstnew(tmp->data, tmp->final));
		free(tmp);
	}
}

void	c_swap_double(t_list **lst_a, t_list **lst_b)
{
	c_swap(lst_a);
	c_swap(lst_b);
}
