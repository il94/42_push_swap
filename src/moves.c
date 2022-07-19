/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilyes@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:30:12 by ilandols          #+#    #+#             */
/*   Updated: 2022/07/18 16:07:37 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **lst, t_operation index)
{
	t_list	*tmp;

	if (*lst && (*lst)->next)
	{
		tmp = (*lst)->next;
		(*lst)->next = (*lst)->next->next;
		ft_lstadd_front(lst, ft_ps_lstnew(tmp->data, tmp->final));
		free(tmp);
	}
	if (index == SA)
		write(1, "sa\n", 3);
	else if (index == SB)
		write(1, "sb\n", 3);
}

void	push(t_list **src, t_list **dest, t_operation index)
{
	t_list	*tmp;

	if (*src != NULL)
	{
		tmp = (*src)->next;
		ft_lstadd_front(dest, ft_ps_lstnew((*src)->data, (*src)->final));
		ft_ps_lstdelone(*src, &ft_delete_content);
		*src = tmp;
	}
	if (index == PA)
		write(1, "pa\n", 3);
	else if (index == PB)
		write(1, "pb\n", 3);
}

void	rotate(t_list **lst, t_operation index)
{
	t_list	*tmp;

	if (*lst && (*lst)->next)
	{
		tmp = *lst;
		ft_lstadd_back(lst, ft_ps_lstnew((*lst)->data, (*lst)->final));
		(*lst) = tmp->next;
		free(tmp);
	}
	if (index == RA)
		write(1, "ra\n", 3);
	else if (index == RB)
		write(1, "rb\n", 3);
}

void	reverse_rotate(t_list **lst, t_operation index)
{
	t_list	*tmp;

	if (*lst && (*lst)->next)
	{
		tmp = *lst;
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		ft_lstadd_front(lst, ft_ps_lstnew(tmp->next->data, tmp->next->final));
		ft_ps_lstdelone(tmp->next, &ft_delete_content);
		tmp->next = NULL;
	}
	if (index == RRA)
		write(1, "rra\n", 4);
	else if (index == RRB)
		write(1, "rrb\n", 4);
}

void	bring_up_element(t_list **lst, int element, t_operation index)
{
	if (sens_rotate(lst, element))
	{
		if (index == LSTA)
			index = RA;
		else
			index = RB;
		while ((*lst)->final != element)
			rotate(lst, index);
	}
	else
	{
		if (index == LSTA)
			index = RRA;
		else
			index = RRB;
		while ((*lst)->final != element)
			reverse_rotate(lst, index);
	}
}
