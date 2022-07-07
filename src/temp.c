/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:21:18 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/07 14:55:03 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_min_position(t_list *lst)
{
	int	result;
	
	result = lst->pos_final;
	while (lst)
	{
		if (result > lst->pos_final)
			result = lst->pos_final;
		lst = lst->next;
	}
	return (result);
}

int	get_max_position(t_list *lst)
{
	int	result;
	
	result = lst->pos_final;
	while (lst)
	{
		if (result < lst->pos_final)
			result = lst->pos_final;
		lst = lst->next;
	}
	return (result);
}

int	get_second_position(t_list *lst)
{
	int	result;
	
	result = lst->pos_final;
	while (lst)
	{
		if (result > lst->pos_final && result < get_min_position(lst))
			result = lst->pos_final;
		lst = lst->next;
	}
	return (result);
}

int	is_min(t_list *lst, int element)
{
	if (lst)
	{
		while (lst && element <= lst->pos_final)
			lst = lst->next;
		if (!lst)
			return (1);
	}
	return (0);
}

int	is_max(t_list *lst, int element)
{
	if (lst)
	{
		while (lst && element >= lst->pos_final)
			lst = lst->next;
		if (!lst)
			return (1);
	}
	return (0);
}

int	is_3_max(t_list *lst, int element)
{
	while (lst && (element >= lst->pos_final || element >= lst->pos_final - 1
			|| element >= lst->pos_final - 2))
		lst = lst->next;
	if (!lst)
		return (1);
	return (0);
}