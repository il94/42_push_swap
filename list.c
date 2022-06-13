/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:47:16 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/13 21:58:03 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sens_rotate(t_list **lst, int position, int size_list)
{
	t_list	*start;
	int		counter;

	start = *lst;
	counter = 0;
	while (position != (*lst)->position - 1)
	{
		counter++;
		if ((*lst)->next == NULL)
			(*lst) = start;
		else
			(*lst) = (*lst)->next;
	}
	*lst = start;
	// printf("counter = %d && size_list / 2 = %d\n", counter, size_list / 2);
	if (counter < size_list / 2)
		return (1);
	else
		return (0);
}

void	get_position(t_list **lst)
{
	t_list	*start;	
	t_list	*temp;	

	start = *lst;
	temp = *lst;
	while (*lst)
	{
		(*lst)->position = 1;
		while (temp)
		{
			if ((*lst)->content > temp->content)
			{
				(*lst)->position++;
				// printf("pos = %d\n", (*lst)->position);
			}
			temp = temp->next;
		}
		*lst = (*lst)->next;
		temp = start;
	}
	*lst = start;
}

int	is_sort(t_list **lst)
{
	t_list	*temp;
	
	temp = *lst;
	if (!(*lst))
		return (1);
	while ((*lst)->next)
	{
		if ((*lst)->content > (*lst)->next->content)
		{
			*lst = temp;
			return (0);
		}
		*lst = (*lst)->next;
	}
	*lst = temp;
	return (1);
}

float	get_median_list(t_list **lst, int size_list)
{
	t_list	*temp;
	float		result;

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

void	get_list(t_list **list, int nb_parameters, char **parameters)
{
	t_list	*element;
	int		i;

	i = nb_parameters - 1;
	*list = ft_int_lstnew(ft_atoi(parameters[i--]), 0);
	while (i >= 0)
	{
		element = ft_int_lstnew(ft_atoi(parameters[i]), 0);
		ft_lstadd_front(list, element);
		i--;
	}
}
