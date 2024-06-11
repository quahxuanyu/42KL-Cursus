/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 21:02:00 by xquah             #+#    #+#             */
/*   Updated: 2024/06/11 18:25:27 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *find_smallest(t_stack **stk_a)
{
	t_stack *a;
	t_stack *smallest;

	a = *stk_a;
	smallest = *stk_a;
	while (a)
	{
		if (a->s_index < smallest->s_index)
			smallest = a;
		a = a->next;
	}
	return (smallest);
}

t_stack *find_target(t_stack **stk_a, int current_index)
{
	t_stack *a;
	t_stack *target;

	a = *stk_a;
	target = NULL;
	while (a)
	{
		if (target)
		{
			if (current_index < a->s_index && target->s_index > a->s_index)
				target = a;
		}
		else if (current_index < a->s_index)
			target = a;
		a = a->next;
	}
	if (!target)
		target = find_smallest(stk_a);
	return (target);
}

void find_cost(t_stack **stk_a, t_stack **stk_b)
{
	t_stack *b;
	t_stack *target;

	b = *stk_b;
	while (b)
	{
		target = find_target(stk_a, b->s_index);
		// ft_printf("Target of %i, is %i\n", b->data, target->data);
		// ft_printf("s_index of %i, is %i\n", b->s_index, target->s_index);
		if (target->pos > (stack_size(stk_a) / 2))
			b->cost_a = (stack_size(stk_a) - target->pos) * -1;
		else
			b->cost_a = target->pos;
		if (b->pos > (stack_size(stk_b) / 2))
			b->cost_b = (stack_size(stk_b) - b->pos) * -1;
		else
			b->cost_b = b->pos;
		b = b->next;
	}
}