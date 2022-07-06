/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:54:24 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/06 18:08:21 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(t_list **lst_a, t_list **lst_b, int size_list)
{
	print_lists(*lst_a, *lst_b);
	while (ft_lstsize(*lst_a) != 5)
	{
		// while (((*lst_a)->pos_final == size_list || (*lst_a)->pos_final == size_list - 1) && (*lst_a)->next)
		// 	rotate(lst_a, RA);
		push(lst_a, lst_b, PB);
	}
	// size_list++;
	sort_five(lst_a, lst_b, size_list);
	print_lists(*lst_a, *lst_b);
}