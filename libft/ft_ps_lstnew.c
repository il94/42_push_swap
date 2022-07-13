/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_lstnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:43:31 by ilyes             #+#    #+#             */
/*   Updated: 2022/06/13 14:37:12 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_ps_lstnew(int data, int position)
{
	t_list	*element;

	element = malloc(sizeof(*element));
	if (element == NULL)
		return (0);
	element->data = data;
	element->cost = 0;
	element->final = position;
	element->next = NULL;
	return (element);
}
