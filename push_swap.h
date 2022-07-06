/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:41:53 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/06 17:21:39 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
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

void	print_lists(t_list *lst_a, t_list *lst_b);
void	print_all_bits(t_list *lst_a, t_list *lst_b);

/* parsing.c */
char	**get_parameters(int *nb_parameters, int ac, char **av);
int		is_valid_inputs(int nb_parameters, char **parameters);
int		is_number(char *input);
int		is_int(long long value, char *input);
int		is_double(long long *inputs, int size);

/* list.c */
void	get_list(t_list **lst, int nb_parameters, char **parameters);
void	get_positions(t_list **lst);
int		is_sort(t_list **lst);
int		compare_two_min_position(t_list **lst, int size_list);
int		sens_rotate(t_list **lst, int position, int size_list);

/* push_swap.c */
void	push_swap(t_list **lst_a, t_list **lst_b, int nb_parameters);
void	sort_three(t_list **lst_a, t_list **lst_b, int size_list);
void	sort_four(t_list **lst_a, t_list **lst_b, int size_list);
void	sort_five(t_list **lst_a, t_list **lst_b, int size_list);
void	radix_sort(t_list **lst_a, t_list **lst_b, int size_list);
void	sort(t_list **lst_a, t_list **lst_b, int size_list);

/* operation_swap_push.c */
void	swap(t_list **lst, t_operation index);
void	swap_ab(t_list **lst_a, t_list **lst_b);
void	push(t_list **lst_src, t_list **lst_dst, t_operation index);

/* operation_rotate_reverse.c */
void	rotate(t_list **lst, t_operation index);
void	rotate_ab(t_list **lst_a, t_list **lst_b);
void	reverse_rotate(t_list **lst, t_operation index);
void	reverse_rotate_ab(t_list **lst_a, t_list **lst_b);

#endif
