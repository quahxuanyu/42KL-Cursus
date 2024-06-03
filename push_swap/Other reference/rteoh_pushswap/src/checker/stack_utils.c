/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_builing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:26:40 by rteoh             #+#    #+#             */
/*   Updated: 2024/03/07 20:26:40 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

t_stack *find_second_last(t_stack *stack)
{
	if (stack == NULL || stack->next == NULL)
		return NULL;
	while (stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack *move_ptr_last(t_stack *stack)
{
	if (stack == NULL)
		return NULL;
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	stack_add_bottom(t_stack **stack, t_stack *new)
{
	t_stack *tmp;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = move_ptr_last(*stack);
	tmp->next = new;
}

t_stack *new_node(int	value)
{
	t_stack	*new;

	new = malloc(sizeof *new);
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}
