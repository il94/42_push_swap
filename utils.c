/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 08:53:12 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/15 16:32:40 by ilandols         ###   ########.fr       */
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

void	delete_content(int *content)
{
	*content = 0;
}