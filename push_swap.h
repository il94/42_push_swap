/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:41:53 by ilandols          #+#    #+#             */
/*   Updated: 2022/06/05 16:22:13 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./libft_custom/libft_custom.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

/* parsing.c */
int	is_valid_inputs(int ac, char **av);
int	is_number(char *input);
int	is_int(long long input);
int	is_double(long long *inputs, int size);

#endif