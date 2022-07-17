/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:31:37 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/17 22:21:00 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
		get_positions(&lst_a);
		if (!is_sort(&lst_a))
			push_swap(&lst_a, &lst_b, ac - 1);
		ft_ps_lstclear(&lst_a, &ft_delete_content);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
