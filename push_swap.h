/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:41:53 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/13 17:54:29 by ilandols         ###   ########.fr       */
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
int		is_valid_inputs(int nb_parameters, char **parameters);
char	**get_parameters(int *nb_parameters, int ac, char **av);
int		is_number(char *input);
int		is_int(long long input);
int		is_double(long long *inputs, int size);

/* list.c */
void	get_list(t_list **lst, int nb_parameters, char **parameters);
void	delete_content(int content);
float		get_median_list(t_list **lst, int size_list);
int		is_sort(t_list **lst);
void	get_position(t_list **lst);
int	sens_rotate(t_list **lst, int position, int size_list);

/* sort.c */
void	sort_1(t_list **lst_a, t_list **lst_b, int size_list);
void	sort_2(t_list **lst_a, t_list **lst_b, int size_list);

/* utils.c */
void	free_array(char **parameters);

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
