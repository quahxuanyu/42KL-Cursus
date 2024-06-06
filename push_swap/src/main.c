/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:31:36 by xquah             #+#    #+#             */
/*   Updated: 2024/06/04 18:31:15 by xquah            ###   ########.fr       */
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
		if (number > 2147483647 || number < -2147483648)
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

int	is_sorted(t_stack **stk)
{
	t_stack	*temp;
	
	temp = *stk;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	push_swap(t_stack **stk_a, t_stack **stk_b, int stack_size)
{
	if (is_sorted(stk_a))
		exit(0);
	else if (stack_size == 2)
		sa(stk_a);
	else if (stack_size == 3)
		sort_three(stk_a);
	
}

void print_stack(t_stack *stk)
{
	t_stack *current;

	current = stk;
	while (current != NULL)
	{
		ft_printf("%i ", current->data);
		current = current->next;
	}
}

// void print_s_index(t_stack *stk)
// {
// 	t_stack *current;

// 	current = stk;
// 	while (current != NULL)
// 	{
// 		ft_printf("%i ", current->s_index);
// 		current = current->next;
// 	}
// }

void display_stack(t_stack *stk_a, t_stack *stk_b)
{
	ft_printf("Stack A: ");
	print_stack(stk_a);
	ft_printf("\nStack B: ");
	print_stack(stk_b);
	ft_printf("\n");
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
	
	ft_printf("Stack A sorted status: %i\n", is_sorted(&stk_a));
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