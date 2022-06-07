/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:41:53 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/07 19:25:49 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef enum e_operation
{
	NOTHING,
	SA,
	SB,
	PA,
	PB,
	RA,
	RB,
	RRA,
	RRB,
}	t_operation;

/* parsing.c */
int	is_valid_inputs(int ac, char **av);
int	is_number(char *input);
int	is_int(long long input);
int	is_double(long long *inputs, int size);

/* list.c */
void	get_list(t_list **lst, int ac, char **av);
void	get_empty_list(t_list **list , int ac);
void	delete_content(int content);

/* operation */

/* swap.c */
void	swap(t_list **lst, t_operation index);
void	swap_ab(t_list **lst_a, t_list **lst_b);

/* push.c */
void	push(t_list **lst_src, t_list **lst_dest, t_operation index);

/* rotate.c */
void	rotate(t_list **lst, t_operation index);
void	rotate_ab(t_list **lst_a, t_list **lst_b);

/* reverse_rotate.c */
void	reverse_rotate(t_list **lst, t_operation index);
void	reverse_rotate_ab(t_list **lst_a, t_list **lst_b);

#endif