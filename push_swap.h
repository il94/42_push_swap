/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:41:53 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/17 22:43:18 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef enum e_operation
{
	SA,
	SB,
	PA,
	PB,
	RA,
	RB,
	RRA,
	RRB,
	LSTA,
	LSTB
}	t_operation;

/* sort_big_list.c */
void	get_costs(t_list *lst_a, t_list *lst_b, int size_list_b);
void	push_to_b(t_list **lst_a, t_list **lst_b, int size_list);
void	sort_big(t_list **lst_a, t_list **lst_b, int size_list);

/* sort_small_list.c */
void	sort_three(t_list **lst_a);
void	sort_four(t_list **lst_a, t_list **lst_b);
void	sort_five(t_list **lst_a, t_list **lst_b);
void	push_swap(t_list **lst_a, t_list **lst_b, int nb_parameters);

/* utils.c */
int		sens_rotate(t_list **lst, int position);
int		is_sort(t_list **lst);
int		is_max(t_list *lst, int element);

/* list.c */
int		get_min_cost(t_list *lst);
int		get_min_position(t_list *lst);
int		get_previous_position(t_list **lst, int element);
void	get_positions(t_list **lst);
void	get_list(t_list **lst, int nb_parameters, char **parameters);

/* parsing.c */
int		is_double(long long *inputs, int size);
int		is_int(long long value, char *input);
int		is_number(char *input);
int		is_valid_inputs(int nb_parameters, char **parameters);

/* moves.c */
void	swap(t_list **lst, t_operation index);
void	push(t_list **lst_src, t_list **lst_dst, t_operation index);
void	rotate(t_list **lst, t_operation index);
void	reverse_rotate(t_list **lst, t_operation index);
void	bring_up_element(t_list **lst, int element, t_operation index);

#endif
