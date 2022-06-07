/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:18:50 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/07 14:56:44 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **lst_src, t_list **lst_dest)
{
	t_list	*temp;
	
	if (*lst_src != NULL)
	{
		temp = (*lst_src)->next;
		ft_lstadd_front(lst_dest, ft_lstnew((*lst_src)->content));
		ft_lstdelone(*lst_src, &delete_content);
		*lst_src = temp;
	}
}