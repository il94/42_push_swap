/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_lstdelone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:02:53 by ilyes             #+#    #+#             */
/*   Updated: 2022/06/07 19:24:40 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_int_lstdelone(t_list *lst, void (*del)(int))
{
	if (lst == NULL)
		return ;
	else
	{
		del(lst->content);
		free(lst);
	}
}
