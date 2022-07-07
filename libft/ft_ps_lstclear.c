/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_lstclear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 18:35:28 by ilyes             #+#    #+#             */
/*   Updated: 2022/06/15 16:38:55 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ps_lstclear(t_list **lst, void (*del)(int *))
{
	t_list	*temp;

	temp = *lst;
	if (lst == NULL)
		return ;
	else
	{
		while (temp != NULL)
		{
			temp = (*lst)->next;
			del(&(*lst)->content);
			del(&(*lst)->cost);
			del(&(*lst)->pos_final);
			free(*lst);
			*lst = temp;
		}
	}
}
