/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:54:15 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/02 21:02:09 by ilandols         ###   ########.fr       */
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
	if (input[i] == '\0')
		return (0);
	if (input[i] == '-' || input[i] == '+')
		i++;
	while (input[i])
	{
		if (!ft_isdigit(input[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_inputs(int nb_parameters, char **parameters)
{
	int			i;
	long long	*inputs;

	if (!parameters)
		return (0);
	inputs = malloc((nb_parameters) * sizeof(long long));
	if (!inputs)
		exit (1);
	i = 0;
	while (parameters[i])
	{
		inputs[i] = ft_long_long_atoi(parameters[i]);
		if (!is_number(parameters[i]) || !is_int(inputs[i])
			|| is_double(inputs, i + 1))
		{
			free_array(parameters);
			free(inputs);
			return (0);
		}
		i++;
	}
	free(inputs);
	return (1);
}

char	**get_parameters(int *nb_parameters, int ac, char **av)
{
	char	**parameters;

	*nb_parameters = 0;
	if (!av[1][0])
	{
		return (NULL);
	}
	if (ac == 2)
	{
		parameters = ft_split(av[1], ' ');
		while (parameters[*nb_parameters])
			(*nb_parameters)++;
	}
	else
	{
		parameters = malloc(ac * sizeof(char *));
		while (av[*nb_parameters + 1])
		{
			parameters[*nb_parameters] = ft_strdup(av[*nb_parameters + 1]);
			(*nb_parameters)++;
		}
		parameters[*nb_parameters] = NULL;
	}
	return (parameters);
}
