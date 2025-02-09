/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_8.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:40:59 by aibn-che          #+#    #+#             */
/*   Updated: 2024/01/17 12:41:14 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*match_index_b(t_list *a, int index)
{
	int		max_val;
	t_list	*closer_val;

	max_val = INT_MAX;
	closer_val = NULL;
	while (a && index != 0)
	{
		if (a->index > index && max_val > a->index)
		{
			max_val = a->index;
			closer_val = a;
		}
		a = a->next;
	}
	return (closer_val);
}

t_list	*cheaper_cost(t_list *top)
{
	t_list	*min_cost;

	min_cost = top;
	while (top)
	{
		if (top->push_cost < min_cost->push_cost)
			min_cost = top;
		top = top->next;
	}
	return (min_cost);
}
