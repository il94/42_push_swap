/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:41:53 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/11 14:33:08 by ilandols         ###   ########.fr       */
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

/* temp.c */
int		is_sort_reverse(t_list **lst);
int		is_last(t_list **lst, int element);
int		get_insert_place(t_list **lst, int element);
int		get_min_cost(t_list *lst);
int		get_min_position(t_list *lst);
int		get_max_position(t_list *lst);
int		get_second_position(t_list *lst);
int		is_min(t_list *lst, int element);
int		is_max(t_list *lst, int element);
int		is_3_max(t_list *lst, int element);

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
int		compare_two_min_position(t_list **lst);
int		sens_rotate(t_list **lst, int position);

/* push_swap.c */
void	push_swap(t_list **lst_a, t_list **lst_b, int nb_parameters);
void	sort_three(t_list **lst_a, t_list **lst_b);
void	sort_four(t_list **lst_a, t_list **lst_b);
void	sort_five(t_list **lst_a, t_list **lst_b);
void	sort_big(t_list **lst_a, t_list **lst_b, int size_list);

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
