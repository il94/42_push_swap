/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:55:32 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/19 15:17:16 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		if (checker(&lst_a, &lst_b))
		{
			if (is_sort(&lst_a))
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
		}
		else
			write(2, "Error\n", 6);
		ft_ps_lstclear(&lst_a, &ft_delete_content);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
