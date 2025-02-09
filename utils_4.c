/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:33:16 by aibn-che          #+#    #+#             */
/*   Updated: 2024/01/31 16:33:31 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_num(char *num)
{
	int	i;
	int	ind;

	i = 0;
	ind = 0;
	while (is_spac(num[i]))
		i++;
	while (num[i] && (num[i] == '-' || num[i] == '+'))
	{
		i++;
		ind++;
	}
	if (ind >= 2 || (ind == 1 && num[i] == '\0'))
		return (0);
	while (num[i])
	{
		if ((num[i] == '-' || num[i] == '+') || !ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

int	valid_num(char *s)
{
	int		i;
	char	**nums;

	i = 0;
	nums = ft_split(s, ' ');
	while (nums[i])
	{
		if (!check_num(nums[i]))
			return (free_arr(nums, i), 0);
		i++;
	}
	return (free_arr(nums, i), 1);
}

int	mult_format(char *s)
{
	int	i;
	int	in;

	in = 0;
	i = 0;
	while (s[i])
	{
		if ((ft_isdigit(s[i + 1]) && is_space(s[i])) || (ft_isdigit(s[i])
				&& is_space(s[i + 1])))
			in++;
		i++;
	}
	if (in >= 1)
		return (1);
	return (0);
}

int	quote_format(char *argv, t_list **head)
{
	int		i;
	char	**mult;
	long	n;

	i = 0;
	mult = NULL;
	if (!valid_num(argv))
		return (free_arr(mult, i), write(2, "Error\n", 6), 1);
	mult = ft_split(argv, ' ');
	while (mult && mult[i])
	{
		n = ft_atoi(mult[i++]);
		if (n > INT_MAX || n < INT_MIN)
			return (free_arr(mult, i), write(2, "Error\n", 6), 1);
		push(head, n);
	}
	free_arr(mult, i);
	return (0);
}

int	regular_format(char *argv, t_list **head)
{
	long	n;

	if (argv[0] == '\0' || !check_num(argv))
		return (write(2, "Error\n", 6), 1);
	n = ft_atoi(argv);
	if (n > INT_MAX || n < INT_MIN)
		return (write(2, "Error\n", 6), 1);
	push(head, n);
	return (0);
}
