/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:33:54 by aibn-che          #+#    #+#             */
/*   Updated: 2024/01/28 12:33:42 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_each_node(t_list *a)
{
	int		i;
	t_list	*cloned_a;
	t_list	*cl;

	cl = a;
	i = 0;
	while (cl)
	{
		i = 0;
		cl->index = i;
		cloned_a = a;
		while (cloned_a)
		{
			if (cloned_a->data < cl->data)
				cl->index = ++i;
			cloned_a = cloned_a->next;
		}
		cl = cl->next;
	}
}

void	divide_stack(t_list *b)
{
	int	half;
	int	i;

	i = 0;
	half = stack_len(b) / 2;
	while (b)
	{
		if (i <= half)
			b->above = 1;
		else
			b->above = 0;
		b = b->next;
		i++;
	}
}

int	node_index(t_list *top, t_list *current_node)
{
	int	i;

	i = 0;
	while (top && current_node && top != current_node)
	{
		top = top->next;
		i++;
	}
	return (i);
}

void	min_node_to_top(t_list **a)
{
	t_list	*mi_node;

	divide_stack(*a);
	mi_node = min_node(*a);
	if (mi_node->above)
	{
		while (node_index(*a, mi_node))
			ra(a, NULL, 1);
	}
	else
	{
		while (node_index(*a, mi_node))
			rra(a, NULL, 1);
	}
}

void	set_target_node_b(t_list *b, t_list *a)
{
	int		index_val;
	t_list	*aa;
	t_list	*bb;
	t_list	*target;

	target = NULL;
	aa = a;
	bb = b;
	while (bb)
	{
		aa = a;
		index_val = bb->index;
		while (aa)
		{
			target = match_index_b(a, index_val);
			aa = aa->next;
		}
		if (!target)
			target = min_node(a);
		bb->target_node = target;
		bb = bb->next;
	}
}
