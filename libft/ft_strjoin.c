/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 02:43:57 by ilandols          #+#    #+#             */
/*   Updated: 2022/05/02 17:14:41 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		size1;
	int		size2;
	int		i;
	int		j;

	size1 = get_size(s1);
	size2 = get_size(s2);
	result = malloc((size1 + size2 + 1) * sizeof(char));
	i = 0;
	j = 0;
	while (i < size1)
	{
		result[i] = s1[i];
		i++;
	}
	while (i < size1 + size2)
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}
