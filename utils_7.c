/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:39:43 by aibn-che          #+#    #+#             */
/*   Updated: 2024/01/31 16:33:50 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	measure_push_cost(t_list *b, t_list *a)
{
	t_list	*op;

	op = b;
	while (op)
	{
		op->push_cost = node_index(b, op);
		if (!op->above)
			op->push_cost = stack_len(b) - node_index(b, op);
		if (op->target_node->above)
			op->push_cost += node_index(a, op->target_node);
		else
			op->push_cost += stack_len(a) - node_index(a, op->target_node);
		op = op->next;
	}
}

void	update_stacks_b(t_list **a, t_list *b)
{
	divide_stack(*a);
	divide_stack(b);
	set_target_node_b(b, *a);
	measure_push_cost(b, *a);
}

int	str_l(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_spac(char c)
{
	if (c == 32)
		return (1);
	return (0);
}
