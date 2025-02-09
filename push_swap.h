/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibn-che <aibn-che@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:53:40 by aibn-che          #+#    #+#             */
/*   Updated: 2024/01/31 16:34:23 by aibn-che         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>

typedef struct StackNode
{
	int					data;
	int					index;
	int					above;
	int					push_cost;
	struct StackNode	*target_node;
	struct StackNode	*next;
}	t_list;

//sort_three.c
t_list	*max_node(t_list *top);
void	sort_three(t_list **top);
t_list	*min_node(t_list *top);

void	pb(t_list **a, t_list **b, int ind);
void	pa(t_list **b, t_list **a, int ind);
void	sb(t_list **b, t_list **null, int ind);
void	sa(t_list **top, t_list **null, int ind);
void	ss(t_list **a, t_list **b, int ind);
void	ra(t_list **top, t_list **null, int ind);
void	rb(t_list **b, t_list **null, int ind);
void	rr(t_list **a, t_list **b, int ind);
void	rra(t_list **top, t_list **null, int ind);
void	rrb(t_list **b, t_list **null, int ind);
void	rrr(t_list **a, t_list **b, int ind);

//quick_sort_chuncks.c
void	quick_sort_chunks(t_list **a);

//utils_1.c
char	**ft_split(char const *s, char c);
char	*free_arr(char **arr, int i);

//utils_2.c
long	ft_atoi(const char *str);
int		ft_isdigit(int c);
int		is_space(char c);

//utils_3.c
void	push(t_list **top, int data);
void	push_top(t_list **top, t_list *new_node);

//utils_4.c
int		check_num(char *num);
int		valid_num(char *s);
int		mult_format(char *s);
int		quote_format(char *argv, t_list **head);
int		regular_format(char *argv, t_list **head);

//utils_5.c
int		check_redundant(t_list *top);
int		check_if_sorted(t_list *top);
void	free_stack(t_list **head);
int		check_input(char *argv, t_list **head);

//utils_6.c
void	index_each_node(t_list *a);
void	divide_stack(t_list *b);
int		node_index(t_list *top, t_list *current_node);
void	min_node_to_top(t_list **a);
void	set_target_node_b(t_list *b, t_list *a);

//utils_7.c
void	measure_push_cost(t_list *a, t_list *b);
void	update_stacks_b(t_list **a, t_list *b);
int		str_l(char *str);
int		is_spac(char c);

//utils_8.c
t_list	*match_index_b(t_list *a, int index);
t_list	*cheaper_cost(t_list *top);

//utils_9.c
t_list	*last_node(t_list *top);
int		stack_len(t_list *top);
t_list	*before_last(t_list *top);

#endif
