/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:38:28 by aibn-che          #+#    #+#             */
/*   Updated: 2024/01/17 14:41:42 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **top, t_list **null, int ind)
{
	t_list	*last;

	(void)null;
	if (!*top || stack_len(*top) <= 1)
		return ;
	if (ind == 1)
		write(1, "ra\n", 3);
	last = last_node(*top);
	last->next = *top;
	*top = (*top)->next;
	last->next->next = NULL;
}

void	rb(t_list **b, t_list **null, int ind)
{
	(void)null;
	if (ind == 1)
		write(1, "rb\n", 3);
	ra(b, NULL, 0);
}

void	rr(t_list **a, t_list **b, int ind)
{
	if (ind)
		write(1, "rr\n", 3);
	ra(a, NULL, 0);
	rb(b, NULL, 0);
}

void	rra(t_list **top, t_list **null, int ind)
{
	t_list	*b_last;
	t_list	*last;

	(void)null;
	if (!*top || stack_len(*top) <= 1)
		return ;
	if (ind == 1)
		write(1, "rra\n", 4);
	b_last = before_last(*top);
	last = last_node(*top);
	last->next = *top;
	*top = last;
	b_last->next = NULL;
}

void	rrb(t_list **b, t_list **null, int ind)
{
	(void)null;
	if (ind == 1)
		write(1, "rrb\n", 4);
	rra(b, NULL, 0);
}
