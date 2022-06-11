/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:47:16 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/11 09:04:30 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_median_list(t_list **lst, int size_list)
{
	t_list	*temp;
	int	result;
	
	temp = *lst;
	result = 0;
	while (temp)
	{
		result += temp->content;
		temp = temp->next;
	}
	return (result /= size_list);
}

void	delete_content(int content)
{
	content = 0;
}

void    get_list(t_list **list, int nb_parameters, char **parameters)
{
	t_list	*element;
	int		i;

	i = nb_parameters - 1;
	*list = ft_int_lstnew(ft_atoi(parameters[i--]));
	while (i >= 0)
	{
		element = ft_int_lstnew(ft_atoi(parameters[i]));
		ft_lstadd_front(list, element);
		i--;
	}
}
