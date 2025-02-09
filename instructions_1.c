/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 21:12:03 by aibn-che          #+#    #+#             */
/*   Updated: 2024/01/28 16:18:16 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list **b, t_list **null, int ind)
{
	(void)null;
	if (ind == 1)
		write(1, "sb\n", 3);
	sa(b, NULL, 0);
}

void	sa(t_list **top, t_list **null, int ind)
{
	t_list	*next;
	t_list	*ref;
	t_list	*h;

	(void)null;
	if (!*top || stack_len(*top) <= 1)
		return ;
	if (ind == 1)
		write(1, "sa\n", 3);
	h = *top;
	ref = (*top)->next->next;
	next = (*top)->next;
	*top = (*top)->next;
	(*top)->next = h;
	h->next = ref;
}

void	ss(t_list **a, t_list **b, int ind)
{
	if (ind == 1)
		write(1, "ss\n", 3);
	sb(b, NULL, 0);
	sa(a, NULL, 0);
}

void	pa(t_list **b, t_list **a, int ind)
{
	t_list	*top;

	if (!(*b))
		return ;
	if (ind)
		write(1, "pa\n", 3);
	top = *b;
	*b = (*b)->next;
	push_top(a, top);
}

void	pb(t_list **a, t_list **b, int ind)
{
	t_list	*top;

	if (!(*a) || !a)
		return ;
	if (ind)
		write(1, "pb\n", 3);
	top = *a;
	*a = (*a)->next;
	push_top(b, top);
}
