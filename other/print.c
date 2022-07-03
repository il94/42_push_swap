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

/* Pour push_swap.h */
/* print.c */
/*
void	print_lists(t_list *lst_a, t_list *lst_b);
void	print_bits(int byte);
void	print_all_bits(t_list *lst_a, t_list *lst_b);
*/

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
}

void	print_bits(int byte)
{
	int	i;
	int	oct;

	i = 32;
	while (i--)
	{
		oct = byte >> i;
		printf("%d", oct & 1);
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
			print_bits((lst_a)->pos);
			printf(" -> pos = %d || ", lst_a->pos);
			lst_a = lst_a->next;
		}
		else
			printf("                                 || ");
		if (lst_b != NULL)
		{
			printf("lst_b = %d = ", (lst_b)->content);
			print_bits((lst_b)->pos);
			printf(" -> pos = %d\n", lst_b->pos);
			lst_b = lst_b->next;
		}
		else
			printf("\n");
	}
}
