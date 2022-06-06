/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:14:35 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/06 11:59:56 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **lst)
{
	t_list	*temp;

	temp = malloc(sizeof(*temp));
	if (*lst != NULL)
	{
		temp->content = (*lst)->content;
		(*lst)->content = (*lst)->next->content;
		(*lst)->next->content = temp->content;
	}
	free(temp);
}

void	swap_ab(t_list **lst_a, t_list **lst_b)
{
	swap(lst_a);
	swap(lst_b);
}
