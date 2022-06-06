/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:18:50 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/06 16:14:26 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **lst_src, t_list **lst_dest)
{
	if (*lst_src != NULL)
	{
		ft_lstadd_front(lst_dest, ft_lstnew((*lst_src)->content));
		*lst_src = (*lst_src)->next;
	}
	//free a gerer
}