/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 22:13:21 by ilandols          #+#    #+#             */
/*   Updated: 2022/05/02 17:15:10 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	get_size(char const *s, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (is_set(s[i], set))
			j++;
		i++;
	}
	return (i - j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = get_size(s1, set);
	str = malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (j < size)
	{
		if (!is_set(s1[i], set))
		{
			str[j] = s1[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}
