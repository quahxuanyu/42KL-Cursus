/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:08:57 by xquah             #+#    #+#             */
/*   Updated: 2024/06/26 22:30:49 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*second_last;
	t_stack	*last;

	if (!stack || !(*stack) || !((*stack)->next))
		return;
	last = *stack;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **stk_a)
{
	reverse_rotate(stk_a);
}

void	rrb(t_stack **stk_b)
{
	reverse_rotate(stk_b);
}

void	rrr(t_stack **stk_a, t_stack **stk_b)
{
	reverse_rotate(stk_a);
	reverse_rotate(stk_b);
}
