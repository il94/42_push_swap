/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:17:06 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/20 10:07:24 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	apply_move(t_list **lst_a, t_list **lst_b, char *mv)
{
	if (ft_strnstr(mv, "sa\n", 3))
		c_swap(lst_a);
	else if (ft_strnstr(mv, "sb\n", 3))
		c_swap(lst_b);
	else if (ft_strnstr(mv, "ss\n", 3))
		c_swap_double(lst_a, lst_b);
	else if (ft_strnstr(mv, "pa\n", 3))
		c_push(lst_b, lst_a);
	else if (ft_strnstr(mv, "pb\n", 3))
		c_push(lst_a, lst_b);
	else if (ft_strnstr(mv, "ra\n", 3))
		c_rotate(lst_a);
	else if (ft_strnstr(mv, "rb\n", 3))
		c_rotate(lst_b);
	else if (ft_strnstr(mv, "rr\n", 3))
		c_rotate_double(lst_a, lst_b);
	else if (ft_strnstr(mv, "rra\n", 4))
		c_reverse_rotate(lst_a);
	else if (ft_strnstr(mv, "rrb\n", 4))
		c_reverse_rotate(lst_b);
	else if (ft_strnstr(mv, "rrr\n", 4))
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
