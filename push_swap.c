/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:35:50 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/02 20:35:10 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **lst_a, t_list **lst_b, int nb_parameters)
{
	if (nb_parameters == 2)
		swap(lst_a, SA);
	else if (nb_parameters == 3)
		sort_three(lst_a, lst_b, nb_parameters);
	else if (nb_parameters == 4)
		sort_four(lst_a, lst_b, nb_parameters);
	else if (nb_parameters == 5)
		sort_five(lst_a, lst_b, nb_parameters);
	else
		radix_sort(lst_a, lst_b, nb_parameters);
}
