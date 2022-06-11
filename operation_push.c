/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 20:18:50 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/08 10:30:06 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **lst_src, t_list **lst_dest, t_operation index)
{
	t_list	*temp;

	if (*lst_src != NULL)
	{
		temp = (*lst_src)->next;
		ft_lstadd_front(lst_dest, ft_int_lstnew((*lst_src)->content));
		ft_int_lstdelone(*lst_src, &delete_content);
		*lst_src = temp;
	}
	if (index == PA)
		write(1, "pa\n", 3);
	else if (index == PB)
		write(1, "pb\n", 3);
}
