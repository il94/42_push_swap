/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:31:37 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/05 21:37:26 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list_test(t_list *lst, int ac)
{
	int 	i;
	char	**array;
	
	array = malloc((ac - 1) * sizeof(char *));
	i = 0;
	while (i < ac - 1)
	{
		array[i] = lst->content;
		lst = lst->next;
		i++;
	}
	while (i - 1 >= 0)
	{
		// printf("i = %d\n", i - 1);
		printf("element = %s\n", array[i - 1]);
		i--;
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
		get_list(&lst_a, ac, av);
		print_list_test(lst_a, ac);
		printf("=========\noperation\n");
		swap_a(&lst_a);
		printf("=========\n");
		print_list_test(lst_a, ac);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
