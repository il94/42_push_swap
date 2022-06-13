/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 08:53:12 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/11 09:53:45 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **parameters)
{
	int	i;

	i = 0;
	while (parameters[i])
	{
		free(parameters[i]);
		i++;
	}
	free(parameters);
}
