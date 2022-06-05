/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:48:28 by ilandols          #+#    #+#             */
/*   Updated: 2022/05/02 17:13:39 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	convert(char *result, long n, int size)
{
	if (n >= 0 && n <= 9)
	{
		result[size - 1] = n + '0';
	}
	else
	{
		convert(result, n / 10, size - 1);
		convert(result, n % 10, size);
	}	
}

static int	is_negative(long *nc, int *size)
{
	if (*nc < 0)
	{
		*size += 1;
		*nc *= (-1);
		return (1);
	}
	else
		return (0);
}

static void	get_size(long nc, int *size)
{
	if (nc == 0)
		*size = 1;
	while (nc > 0)
	{
		*size += 1;
		nc /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	long	nc;
	int		symb;
	int		size;
	int		i;

	nc = n;
	size = 0;
	symb = is_negative(&nc, &size);
	get_size(nc, &size);
	result = malloc((size + 1) * sizeof(char));
	i = 0;
	nc = n;
	if (symb == 1)
	{
		nc *= (-1);
		result[i] = '-';
		i++;
	}
	if (n == 0)
		result[i] = '0';
	else
		convert(result, nc, size);
	result[size] = '\0';
	return (result);
}
