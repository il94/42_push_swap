/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:47:16 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/07 19:26:15 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_content(int content)
{
	content = 0;
}

void	get_list(t_list **list, int ac, char **av)
{
	t_list	*element;
	int		i;

	i = ac - 1;
	*list = ft_int_lstnew(ft_atoi(av[i--]));
	while (i > 0)
	{
		element = ft_int_lstnew(ft_atoi(av[i]));
		ft_lstadd_front(list, element);
		i--;
	}
}
