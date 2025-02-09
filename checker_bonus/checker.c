/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 19:49:28 by aibn-che          #+#    #+#             */
/*   Updated: 2024/01/31 16:42:40 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "get_next_line.h"
#include "checker.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]) && i < n)
		i++;
	return (s1[i] - s2[i]);
}

int	check_if_valid(t_instr *func, t_list **head, t_list **b)
{
	char	*str;
	int		ind;
	int		size;

	str = get_next_line(0);
	while (str)
	{
		ind = 0;
		size = 11;
		while (size-- && !ind)
		{
			if (!ft_strncmp(str, func[size].ins, str_len(func[size].ins) - 1)
				&& str_len(str) - 1 == str_len(func[size].ins))
			{
				ind++;
				func[size].myfun(func[size].h1, func[size].h2, func[size].ind);
			}
		}
		if (!ind)
			return ((free_stack(head),
					free_stack(b), write(1, "Error\n", 6)), free(str), 1);
		free(str);
		str = get_next_line(0);
	}
	return (free(str), 0);
}

int	check_instructions(t_list **head, t_list **b)
{
	t_instr	func[11];

	func[0] = (t_instr){"sa", sa, head, NULL, 0};
	func[1] = (t_instr){"sb", sb, b, NULL, 0};
	func[2] = (t_instr){"ss", ss, head, b, 0};
	func[3] = (t_instr){"pa", pa, b, head, 0};
	func[4] = (t_instr){"pb", pb, head, b, 0};
	func[5] = (t_instr){"ra", ra, head, NULL, 0};
	func[6] = (t_instr){"rr", rr, head, b, 0};
	func[7] = (t_instr){"rra", rra, head, NULL, 0};
	func[8] = (t_instr){"rrb", rrb, b, NULL, 0};
	func[9] = (t_instr){"rrr", rrr, head, b, 0};
	func[10] = (t_instr){"rb", rb, b, NULL, 0};
	if (check_if_valid(func, head, b))
		return (1);
	return (0);
}

int	check_if_sorte_d(t_list *top)
{
	int		len;
	t_list	*following;
	int		i;

	i = 0;
	len = stack_len(top);
	if (len == 1)
		return (1);
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

int	main(int argc, char *argv[])
{
	t_list	*head;
	int		a;
	t_list	*b;
	int		len;

	head = NULL;
	b = NULL;
	a = 0;
	if (argc >= 2)
	{
		while (argv[++a])
			if (check_input(argv[a], &head))
				return (free_stack(&head), 1);
		if (check_redundant(head))
			return (write(2, "Error\n", 8), free_stack(&head), 1);
		len = stack_len(head);
		if (check_instructions(&head, &b))
			return (1);
		if (check_if_sorte_d(head) && (stack_len(head) == len))
			return (free_stack(&head), free_stack(&b), write(1, "OK\n", 3), 0);
		else
			return (free_stack(&head),
				free_stack(&b), write(2, "KO\n", 3), 1);
	}
}
