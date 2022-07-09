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

#include "../push_swap.h"

void	print_lists(t_list *lst_a, t_list *lst_b)
{
	printf("============PRINT LIST============\n");
	while (lst_a != NULL || lst_b != NULL)
	{
		if (lst_a != NULL)
		{
			printf("lst_a = %d -> cost = %d -> final = %d || ", lst_a->content, lst_a->cost, lst_a->pos_final);
			lst_a = lst_a->next;
		}
		else
			printf("                                   || ");
		if (lst_b != NULL)
		{
			printf("lst_b = %d -> cost = %d -> final = %d\n", lst_b->content, lst_b->cost, lst_b->pos_final);
			lst_b = lst_b->next;
		}
		else
			printf("\n");
	}
}

void	print_all_bits(t_list *lst_a, t_list *lst_b)
{
	printf("==========PRINT BITS LIST==========\n");
	while (lst_a != NULL || lst_b != NULL)
	{
		if (lst_a != NULL)
		{
			printf("lst_a = %d = ", (lst_a)->content);
			ft_print_bits((lst_a)->pos_final);
			printf(" -> pos_final = %d || ", lst_a->pos_final);
			lst_a = lst_a->next;
		}
		else
			printf("                                 || ");
		if (lst_b != NULL)
		{
			printf("lst_b = %d = ", (lst_b)->content);
			ft_print_bits((lst_b)->pos_final);
			printf(" -> pos_final = %d\n", lst_b->pos_final);
			lst_b = lst_b->next;
		}
		else
			printf("\n");
	}
}
