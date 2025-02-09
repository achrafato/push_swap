/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:13:42 by aibn-che          #+#    #+#             */
/*   Updated: 2024/01/17 14:44:11 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

///****************ft_atoi********************

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

long	ft_atoi(const char *str)
{
	int			i;
	long int	res;
	long int	rs;
	int			sign;

	i = 0;
	sign = 1;
	rs = 0;
	while (is_space(str[i]))
		i++;
	res = 0;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	while (ft_isdigit(str[i]))
	{
		if ((res * (long)sign) > INT_MAX || INT_MIN > (res * (long)sign))
			return (2147483648);
		res = (10 * res) + (str[i] - '0');
		i++;
		rs = res;
	}
	return (res * (long)sign);
}
