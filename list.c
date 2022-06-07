/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:47:16 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/07 11:46:03 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_content(void *content)
{
	content = NULL;
}

void	get_list(t_list **list, int ac, char **av)
{
	t_list	*element;
	int		i;

	i = ac - 1;
	*list = ft_lstnew(av[i--]);
	while (i > 0)
	{
		// printf("next = %p\n", element);
		element = ft_lstnew(av[i]);
		ft_lstadd_front(list, element);
		i--;
	}
}
