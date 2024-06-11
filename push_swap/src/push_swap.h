/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:05:09 by xquah             #+#    #+#             */
/*   Updated: 2024/06/11 17:35:13 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "../libft/libft.h"

typedef struct s_stack
{
	int data;
	int pos;
	int s_index;
	int cost_a;
	int cost_b;
	struct s_stack *next;
} t_stack;

// swap.c
void swap(t_stack **stack);
void sa(t_stack **stack_a);
void sb(t_stack **stack_b);
void ss(t_stack **stack_a, t_stack **stack_b);

// push.c
void push(t_stack **dest, t_stack **src);
void pa(t_stack **stack_a, t_stack **stack_b);
void pb(t_stack **stack_a, t_stack **stack_b);

// rotate.c
void rotate(t_stack **stack);
void ra(t_stack **stk_a);
void rb(t_stack **stk_b);
void rr(t_stack **stk_a, t_stack **stk_b);

// reverse_rotate.c
void reverse_rotate(t_stack **stack);
void rra(t_stack **stk_a);
void rrb(t_stack **stk_b);
void rrr(t_stack **stk_a, t_stack **stk_b);

// utils
long ft_long_atoi(const char *str);
void exit_error(t_stack **stk_a, t_stack **stk_b);
void display_both_stack(t_stack **stk_a, t_stack **stk_b);
void print_stack(t_stack **stk);
int is_sorted(t_stack **stk);
int stack_size(t_stack **stk);
void print_s_index(t_stack **stk);

// sort.c
void sort_index(t_stack **stk);

// sort_three_algo.c
void sort_three(t_stack **stk_a);

// push_swap_algo.c
void turk_sort(t_stack **stk_a, t_stack **stk_b);

//cost_algo.c
void find_cost(t_stack **stk_a, t_stack **stk_b);
#endif