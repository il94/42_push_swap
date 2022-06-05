/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 02:06:19 by ilandols          #+#    #+#             */
/*   Updated: 2022/05/02 17:15:07 by ilandols         ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;
	size_t			size_s;

	size_s = get_size(s);
	if (len > size_s)
		len = size_s;
	if (start > size_s)
	{
		str = malloc(sizeof(char));
		str[0] = '\0';
		return (str);
	}
	if (start + len > size_s)
		len = size_s - start;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	start -= 1;
	while (++i < len && s[++start])
		str[i] = s[start];
	str[i] = '\0';
	return (str);
}
