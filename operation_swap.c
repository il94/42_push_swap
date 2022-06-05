/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:14:35 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/05 21:12:36 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **lst)
{
	t_list	*temp;

	if (*lst != NULL)
	{
		temp = (*lst)->next;
		(*lst)->next = *lst;
		*lst = temp;
	}
}

void	swap_b(t_list **lst)
{
	
}

void	swap_ab(t_list **lst_a, t_list **lst_b)
{
	
}
