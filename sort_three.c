/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:52:50 by aibn-che          #+#    #+#             */
/*   Updated: 2024/01/17 14:47:29 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*max_node(t_list *top)
{
	t_list	*max;

	if (!top)
		return (NULL);
	max = top;
	while (top)
	{
		if (max->data < top->data)
			max = top;
		top = top->next;
	}
	return (max);
}

void	sort_three(t_list **top)
{
	t_list	*max;

	if (!(stack_len(*top) == 3))
		return ;
	max = max_node(*top);
	if (*top == max)
		ra(top, NULL, 1);
	else if ((*top)->next == max)
		rra(top, NULL, 1);
	if ((*top)->data > (*top)->next->data)
		sa(top, NULL, 1);
}

t_list	*min_node(t_list *top)
{
	t_list	*min;

	min = top;
	while (top)
	{
		if (min->data > top->data)
			min = top;
		top = top->next;
	}
	return (min);
}
