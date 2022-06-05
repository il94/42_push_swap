/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:54:15 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/05 17:22:49 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_double(long long *inputs, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (inputs[i] == inputs[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_int(long long input)
{
	if (input < INT_MIN || input > INT_MAX)
		return (0);
	return (1);
}

int	is_number(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (!ft_isdigit(input[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_inputs(int ac, char **av)
{
	int			i;
	int			j;
	long long	*inputs;

	inputs = malloc((ac - 1) * sizeof(long long));
	if (!inputs)
		exit (1);
	i = 1;
	while (av[i])
	{
		inputs[i - 1] = ft_long_long_atoi(av[i]);
		if (!is_number(av[i]) || !is_int(inputs[i - 1]) || is_double(inputs, i))
		{
			free(inputs);
			return (0);
		}
		i++;
	}
	free(inputs);
	return (1);
}
