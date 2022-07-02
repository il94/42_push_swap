/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:31:37 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/02 20:54:48 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list		*lst_a;
	t_list		*lst_b;
	char		**parameters;
	int			nb_parameters;

	if (ac < 2)
		exit (0);
	// if (av[1] && av[1][0])
	// {
		parameters = get_parameters(&nb_parameters, ac, av);
		if (is_valid_inputs(nb_parameters, parameters))
		{
			lst_b = NULL;
			get_list(&lst_a, nb_parameters, parameters);
			free_array(parameters);
			get_positions(&lst_a);
			if (!is_sort(&lst_a))
				push_swap(&lst_a, &lst_b, nb_parameters);
			ft_ps_lstclear(&lst_a, &delete_content);
			ft_ps_lstclear(&lst_b, &delete_content);
		}
		else
			write(2, "Error\n", 6);
	// }
	// else
	// 	write(2, "Error\n", 6);
	return (0);
}
