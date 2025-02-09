/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 10:31:28 by aibn-che          #+#    #+#             */
/*   Updated: 2024/01/31 15:32:32 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*head;
	int		a;

	(void) argc;
	head = NULL;
	a = 1;
	while (argv[a])
	{
		if (check_input(argv[a], &head))
			(free_stack(&head), exit(EXIT_FAILURE));
		a++;
	}
	if (check_redundant(head))
		(write(2, "Error\n", 6), free_stack(&head));
	if (check_if_sorted(head))
		(free_stack(&head), exit(EXIT_SUCCESS));
	if (stack_len(head) == 2)
		sa(&head, NULL, 1);
	else if (stack_len(head) == 3)
		sort_three(&head);
	else if (stack_len(head) >= 4)
		quick_sort_chunks(&head);
	free_stack(&head);
}
