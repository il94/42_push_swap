/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:42:39 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/15 17:23:13 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lists(t_list *lst_a, t_list *lst_b)
{
	printf("============PRINT LIST============\n");
	while (lst_a != NULL || lst_b != NULL)
	{
		if (lst_a != NULL)
		{
			printf("lst_a = %d -> pos = %d || ", lst_a->content, lst_a->pos);
			lst_a = lst_a->next;
		}
		else
			printf("                      || ");
		if (lst_b != NULL)
		{
			printf("lst_b = %d -> pos = %d\n", lst_b->content, lst_b->pos);
			lst_b = lst_b->next;
		}
		else
			printf("\n");
	}
	// printf("\n");
}

float	get_median_list(t_list **lst, int size_list)
{
	t_list	*tmp;
	float		result;

	tmp = *lst;
	result = 0;
	while (tmp)
	{
		result += tmp->content;
		tmp = tmp->next;
	}
	return (result /= size_list);
}
