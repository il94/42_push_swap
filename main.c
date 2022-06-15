/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:31:37 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/15 17:17:38 by ilandols         ###   ########.fr       */
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
	parameters = get_parameters(&nb_parameters, ac, av);
	if (is_valid_inputs(nb_parameters, parameters))
	{
		lst_b = NULL;
		get_list(&lst_a, nb_parameters, parameters);
		free_array(parameters);
		get_position(&lst_a);
		// print_lists(lst_a, lst_b);
		// printf("=========\noperation\n");
		if (nb_parameters == 3)
			sort_three(&lst_a, &lst_b, nb_parameters);
		else if (nb_parameters == 5)
			sort_five(&lst_a, &lst_b, nb_parameters);
		// printf("=========\n");
		// print_lists(lst_a, lst_b);
		ft_ps_lstclear(&lst_a, &delete_content);
		ft_ps_lstclear(&lst_b, &delete_content);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
