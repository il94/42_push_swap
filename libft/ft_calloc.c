/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 00:44:23 by ilandols          #+#    #+#             */
/*   Updated: 2022/05/02 17:13:23 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*p;
	char		*c;
	size_t		i;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);
	c = p;
	i = 0;
	while (i < nmemb)
	{
		c[i] = 0;
		i++;
	}
	return (p);
}
