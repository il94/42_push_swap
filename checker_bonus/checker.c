/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:17:06 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/19 15:33:16 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	apply_move(t_list **lst_a, t_list **lst_b, char *mv)
{
	if (mv[0] == 's' && mv[1] == 'a' && mv[2] == '\n')
		c_swap(lst_a);
	else if (mv[0] == 's' && mv[1] == 'b' && mv[2] == '\n')
		c_swap(lst_b);
	else if (mv[0] == 's' && mv[1] == 's' && mv[2] == '\n')
		c_swap_double(lst_a, lst_b);
	else if (mv[0] == 'p' && mv[1] == 'a' && mv[2] == '\n')
		c_push(lst_b, lst_a);
	else if (mv[0] == 'p' && mv[1] == 'b' && mv[2] == '\n')
		c_push(lst_a, lst_b);
	else if (mv[0] == 'r' && mv[1] == 'a' && mv[2] == '\n')
		c_rotate(lst_a);
	else if (mv[0] == 'r' && mv[1] == 'b' && mv[2] == '\n')
		c_rotate(lst_b);
	else if (mv[0] == 'r' && mv[1] == 'r' && mv[2] == '\n')
		c_rotate_double(lst_a, lst_b);
	else if (mv[0] == 'r' && mv[1] == 'r' && mv[2] == 'a' && mv[3] == '\n')
		c_reverse_rotate(lst_a);
	else if (mv[0] == 'r' && mv[1] == 'r' && mv[2] == 'b' && mv[3] == '\n')
		c_reverse_rotate(lst_b);
	else if (mv[0] == 'r' && mv[1] == 'r' && mv[2] == '\n')
		c_reverse_rotate_double(lst_a, lst_b);
	else
		return (0);
	return (1);
}

int	checker(t_list **lst_a, t_list **lst_b)
{
	char	*move;

	move = "";
	while (move != NULL)
	{
		move = ft_get_next_line(0);
		if (move)
		{
			if (apply_move(lst_a, lst_b, move))
				free(move);
			else
			{
				free(move);
				return (0);
			}
		}
	}
	return (1);
}
