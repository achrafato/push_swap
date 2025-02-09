/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_chuncks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 10:31:28 by aibn-che          #+#    #+#             */
/*   Updated: 2024/01/30 18:01:13 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	node_b_and_target_node_above(t_list **b, t_list **a, t_list *min_cost)
{
	while (node_index(*b, min_cost) && node_index(*a, min_cost->target_node))
		rr(a, b, 1);
	while (node_index(*b, min_cost))
		rb(b, NULL, 1);
	while (node_index(*a, min_cost->target_node))
		ra(a, NULL, 1);
}

void	node_b_and_target_node_below(t_list **b, t_list **a, t_list *min_cost)
{
	while (node_index(*b, min_cost) && node_index(*a, min_cost->target_node))
		rrr(a, b, 1);
	while (node_index(*b, min_cost))
		rrb(b, NULL, 1);
	while (node_index(*a, min_cost->target_node))
		rra(a, NULL, 1);
}

void	transmit_b_to_a(t_list **a, t_list **b, t_list *min_cost)
{
	if (min_cost->above)
	{
		if (min_cost->target_node->above)
			node_b_and_target_node_above(b, a, min_cost);
		else
		{
			while (node_index(*b, min_cost))
				rb(b, NULL, 1);
			while (node_index(*a, min_cost->target_node))
				rra(a, NULL, 1);
		}
	}
	else
	{
		if (!min_cost->target_node->above)
			node_b_and_target_node_below(b, a, min_cost);
		else
		{
			while (node_index(*b, min_cost))
				rrb(b, NULL, 1);
			while (node_index(*a, min_cost->target_node))
				ra(a, NULL, 1);
		}
	}
}

void	transmit_a_to_b(t_list **a, t_list **b)
{
	int	pv1;
	int	pv2;

	pv1 = 0;
	pv2 = (stack_len(*a) / 4) + pv1;
	pv1 = (stack_len(*a) / 2) + pv1;
	while (stack_len(*a) > 3)
	{
		if (stack_len(*b) >= 2)
		{
			if ((*a)->index >= pv1 && (*b)->index < pv2)
				rr(a, b, 1);
			else if ((*b)->index < pv2)
				rb(b, NULL, 1);
		}
		if ((*a)->index >= pv1)
			ra(a, NULL, 1);
		else
			pb(a, b, 1);
		if (stack_len(*b) >= pv1)
		{
			pv2 = (stack_len(*a) / 4) + pv1;
			pv1 = (stack_len(*a) / 2) + pv1;
		}
	}
}

void	quick_sort_chunks(t_list **a)
{
	t_list	*b;
	t_list	*min_cost;

	b = NULL;
	min_cost = NULL;
	index_each_node(*a);
	transmit_a_to_b(a, &b);
	sort_three(a);
	while (b)
	{
		update_stacks_b(a, b);
		min_cost = cheaper_cost(b);
		transmit_b_to_a(a, &b, min_cost);
		pa(&b, a, 1);
	}
	min_node_to_top(a);
}
