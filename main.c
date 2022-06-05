/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:31:37 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/05 16:14:02 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_list	*lst_a;
	t_list	*lst_b;

	if (ac < 2)
		return (0);
	if (is_valid_inputs(ac, av))
	{
		// lst_a = get_list(av);
		// printf("test %ld\n", ft_strlen(av[0]));
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
