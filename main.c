/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:31:37 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/07 19:18:13 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lists(t_list *lst_a, t_list *lst_b, int ac)
{
	int 	i;

	i = 0;
	printf("|!| lst_b a l'envers |!|\n");
	while (lst_a != NULL || lst_b != NULL)
	{
		if (lst_a != NULL)
		{
			printf("lst_a = %d || ", lst_a->content);
			lst_a = lst_a->next;
		}
		else
			printf("          || ");
		if (lst_b != NULL)
		{
			printf("lst_b = %d\n", lst_b->content);
			lst_b = lst_b->next;
		}
		else
			printf("\n");
	}
}

int	main(int ac, char **av)
{
	t_list		*lst_a;
	t_list		*lst_b;
	t_operation	index;

	if (ac < 2)
		return (0);
	if (is_valid_inputs(ac, av))
	{
		lst_b = NULL;
		get_list(&lst_a, ac, av);
		print_lists(lst_a, lst_b, ac);
		printf("=========\noperation\n");
			swap(&lst_a, SA);
			swap(&lst_b, SB);
			swap_ab(&lst_a, &lst_b);
			push(&lst_b, &lst_a, PA);
			push(&lst_a, &lst_b, PB);
			rotate(&lst_a, RA);
			rotate(&lst_b, RB);
			rotate_ab(&lst_a, &lst_b);
			reverse_rotate(&lst_a, RRA);
			reverse_rotate(&lst_b, RRB);
			reverse_rotate_ab(&lst_a, &lst_b);
		printf("=========\n");
		print_lists(lst_a, lst_b, ac);
		ft_int_lstclear(&lst_a, &delete_content);
		ft_int_lstclear(&lst_b, &delete_content);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
