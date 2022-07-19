/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:16:28 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/19 15:35:43 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	get_list(t_list **list, int nb_parameters, char **parameters)
{
	t_list	*element;
	int		i;

	i = nb_parameters - 1;
	*list = ft_ps_lstnew(ft_atoi(parameters[i--]), 0);
	while (i >= 0)
	{
		element = ft_ps_lstnew(ft_atoi(parameters[i]), 0);
		ft_lstadd_front(list, element);
		i--;
	}
}

int	is_sort(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	if (!(*lst))
		return (1);
	while ((*lst)->next)
	{
		if ((*lst)->data > (*lst)->next->data)
		{
			*lst = tmp;
			return (0);
		}
		*lst = (*lst)->next;
	}
	*lst = tmp;
	return (1);
}
