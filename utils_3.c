/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:14:47 by aibn-che          #+#    #+#             */
/*   Updated: 2024/01/17 14:46:09 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_new_node(int data)
{
	t_list	*new;

	new = malloc(sizeof(t_list) + 1);
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

void	push(t_list **top, int data)
{
	t_list	*new_node;

	new_node = create_new_node(data);
	if (last_node(*top))
		last_node(*top)->next = new_node;
	else
		*top = new_node;
}

void	push_top(t_list **top, t_list *new_node)
{
	if (!new_node)
		return ;
	if (*top)
		new_node->next = *top;
	else
		new_node->next = NULL;
	*top = new_node;
}
