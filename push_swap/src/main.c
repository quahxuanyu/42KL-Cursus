/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:31:36 by xquah             #+#    #+#             */
/*   Updated: 2024/06/11 19:19:38 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *init_stack(int len, char *nums[])
{
	int i;
	long number;
	t_stack *stk;
	t_stack *current;

	i = 0;
	stk = malloc(sizeof(t_stack));
	current = stk;
	while (++i < len)
	{
		number = ft_long_atoi(nums[i]);
		if (number > 2147483647 || number < INT_MIN)
			exit_error(&stk, NULL);
		current->data = (int)number;
		if (i + 1 < len)
		{
			current->next = malloc(sizeof(t_stack));
			current = current->next;
		}
		else
			current->next = NULL;
	}
	return (stk);
}

void push_swap(t_stack **stk_a, t_stack **stk_b, int stack_size)
{
	if (is_sorted(stk_a))
		exit(0);
	else if (stack_size == 2)
		sa(stk_a);
	else if (stack_size == 3)
		sort_three(stk_a);
	else if (stack_size > 3)
		turk_sort(stk_a, stk_b);
}

int main(int argc, char *argv[])
{
	t_stack *stk_a;
	t_stack *stk_b;

	// Check input: if all are integers & no duplicates
	stk_a = init_stack(argc, argv);
	stk_b = NULL;

	sort_index(&stk_a);
	push_swap(&stk_a, &stk_b, argc - 1);
	order_stack_a(&stk_a);

	//display_both_stack(&stk_a, &stk_b);
	//ft_printf("Stack A sorted status: %i\n", is_sorted(&stk_a));
}

/*
	ft_printf("------Initialize Stack------\n");
	display_stack(stk_a, stk_b);

	ft_printf("------Actions------\n");
	pb(&stk_a, &stk_b);
	display_stack(stk_a, stk_b);

	pb(&stk_a, &stk_b);
	display_stack(stk_a, stk_b);

	rrr(&stk_a, &stk_b);
	display_stack(stk_a, stk_b);

	ss(&stk_a, &stk_b);
	display_stack(stk_a, stk_b);

	rr(&stk_a, &stk_b);
	display_stack(stk_a, stk_b);
*/