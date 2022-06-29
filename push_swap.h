/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:41:53 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/29 18:38:44 by ilandols         ###   ########.fr       */
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

/* temp.c */ /* bits.c */
void	print_lists(t_list *lst_a, t_list *lst_b);
float		get_median_list(t_list **lst, int size_list);
void	print_bits(int byte);
void	print_all_bits(t_list *lst_a, t_list *lst_b);

/* parsing.c */
char	**get_parameters(int *nb_parameters, int ac, char **av);
int		is_valid_inputs(int nb_parameters, char **parameters);
int		is_number(char *input);
int		is_int(long long input);
int		is_double(long long *inputs, int size);

/* list.c */
void	get_list(t_list **lst, int nb_parameters, char **parameters);
void	get_positions(t_list **lst);
int		is_sort(t_list **lst);
int	compare_two_min_position(t_list **lst, int size_list);
int	sens_rotate(t_list **lst, int position, int size_list);

/* sort */

/* sort_three.c */
void	sort_three(t_list **lst_a, t_list **lst_b, int size_list);
void	min_is_first(t_list **lst_a, t_list **lst_b, int size_list);
void	mid_is_first(t_list **lst_a, t_list **lst_b, int size_list);
void	max_is_first(t_list **lst_a, t_list **lst_b, int size_list);

/* sort_fourght.c */
void	sort_fourght(t_list **lst_a, t_list **lst_b, int size_list);

/* sort_five.c */
void	sort_five(t_list **lst_a, t_list **lst_b, int size_list);

/* radix_sort.c */
void	radix_sort(t_list **lst_a, t_list **lst_b, int size_list);

/* push_swap.c */
void	push_swap(t_list **lst_a, t_list **lst_b, int nb_parameters);

/* utils.c */
void	free_array(char **parameters);
void	delete_content(int *content);

/* operation */

/* swap.c */
void	swap(t_list **lst, t_operation index);
void	swap_ab(t_list **lst_a, t_list **lst_b);

/* push.c */
void	push(t_list **lst_src, t_list **lst_dst, t_operation index);

/* rotate.c */
void	rotate(t_list **lst, t_operation index);
void	rotate_ab(t_list **lst_a, t_list **lst_b);

/* reverse_rotate.c */
void	reverse_rotate(t_list **lst, t_operation index);
void	reverse_rotate_ab(t_list **lst_a, t_list **lst_b);

#endif
