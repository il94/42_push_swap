/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:56:14 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/19 15:20:30 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	c_push(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (*src != NULL)
	{
		tmp = (*src)->next;
		ft_lstadd_front(dest, ft_ps_lstnew((*src)->data, (*src)->final));
		ft_ps_lstdelone(*src, &ft_delete_content);
		*src = tmp;
	}
}
