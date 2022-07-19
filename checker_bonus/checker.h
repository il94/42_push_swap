/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:33:44 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/19 15:35:50 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../libft/libft.h"

/* checker.c */
int		apply_move(t_list **lst_a, t_list **lst_b, char *mv);
int		checker(t_list **lst_a, t_list **lst_b);

/* list.c */
void	get_list(t_list **list, int nb_parameters, char **parameters);
int		is_sort(t_list **lst);

/* parsing.c */
int		is_double(long long *inputs, int size);
int		is_int(long long value, char *input);
int		is_number(char *input);
int		is_valid_inputs(int nb_parameters, char **parameters);

/* c_swap.c */
void	c_swap(t_list **lst);
void	c_swap_double(t_list **lst_a, t_list **lst_b);

/* c_push.c */
void	c_push(t_list **src, t_list **dest);

/* c_rotate.c */
void	c_rotate(t_list **lst);
void	c_rotate_double(t_list **lst_a, t_list **lst_b);

/* c_reverse_rotate.c */
void	c_reverse_rotate(t_list **lst);
void	c_reverse_rotate_double(t_list **lst_a, t_list **lst_b);

#endif
