/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:00:04 by aibn-che          #+#    #+#             */
/*   Updated: 2024/01/28 16:13:53 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"

typedef struct Instruction
{
	char	*ins;
	void	(*myfun)(t_list **, t_list **, int);
	t_list	**h1;
	t_list	**h2;
	int		ind;
}	t_instr;

#endif
