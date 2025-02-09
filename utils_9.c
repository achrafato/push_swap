/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_9.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:28:15 by aibn-che          #+#    #+#             */
/*   Updated: 2024/01/17 15:11:39 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*last_node(t_list *top)
{
	if (!top)
		return (NULL);
	while (top->next)
	{
		top = top->next;
	}
	return (top);
}

int	stack_len(t_list *top)
{
	int	i;

	i = 0;
	while (top)
	{
		i++;
		top = top->next;
	}
	return (i);
}

t_list	*before_last(t_list *top)
{
	if (!top)
		return (NULL);
	while ((stack_len(top) >= 2) && top->next->next)
	{
		top = top->next;
	}
	return (top);
}
