/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:36:12 by aibn-che          #+#    #+#             */
/*   Updated: 2024/01/31 16:18:07 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_redundant(t_list *top)
{
	t_list	*current;
	t_list	*following;

	current = top;
	while (current)
	{
		following = current->next;
		while (following)
		{
			if (current->data == following->data)
				return (1);
			following = following->next;
		}
		current = current->next;
	}
	return (0);
}

int	check_if_sorted(t_list *top)
{
	int		len;
	t_list	*following;
	int		i;

	i = 0;
	len = stack_len(top);
	if (len == 1)
		return (0);
	if (top)
	{
		following = top->next;
		while (top && following)
		{
			if (top->data < following->data)
				i++;
			following = following->next;
			top = top->next;
		}
	}
	if (len - 1 == i)
		return (1);
	return (0);
}

void	free_stack(t_list **head)
{
	t_list	*to_free;

	while (*head)
	{
		to_free = *head;
		*head = (*head)->next;
		free(to_free);
	}
}

int	check_input(char *argv, t_list **head)
{
	if (mult_format(argv))
	{
		if (quote_format(argv, head))
			return (1);
	}
	else
	{
		if (regular_format(argv, head))
			return (1);
	}
	return (0);
}
