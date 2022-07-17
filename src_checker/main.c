/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:55:32 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/17 22:46:29 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	checker(t_list **lst_a, t_list **lst_b, int nb_parameters, char **parameters)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
}

int	main(int ac, char **av)
{
	t_list		*lst_a;
	t_list		*lst_b;

	if (ac < 2)
		exit (0);
	if (is_valid_inputs(ac - 1, av + 1))
	{
		lst_b = NULL;
		get_list(&lst_a, ac - 1, av + 1);
		checker(&lst_a, &lst_b, ac - 1, av + 1);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
