/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:31:37 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/06 16:04:18 by ilandols         ###   ########.fr       */
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
		// printf("boucle\n");
		if (lst_a != NULL)
		{
			printf("lst_a = %s || ", lst_a->content);
			lst_a = lst_a->next;
		}
		else
			printf("          || ");
		if (lst_b != NULL)
		{
			printf("lst_b = %s\n", lst_b->content);
			lst_b = lst_b->next;
		}
		else
			printf("\n");
		// lst_b = lst_b->next;
	}
}

int	main(int ac, char **av)
{
	t_list	*lst_a;
	t_list	*lst_b;

	if (ac < 2)
		return (0);
	if (is_valid_inputs(ac, av))
	{
		lst_b = NULL;
		get_list(&lst_a, ac, av);
		print_lists(lst_a, lst_b, ac);
		printf("=========\noperation\n");
		push(&lst_a, &lst_b);
		// push(&lst_a, &lst_b);
		// push(&lst_a, &lst_b);
		// push(&lst_a, &lst_b);
		// push(&lst_a->next, &lst_b);
		printf("=========\n");
		print_lists(lst_a, lst_b, ac);
		ft_lstclear(&lst_a, &delete_content);
		ft_lstclear(&lst_b, &delete_content);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
