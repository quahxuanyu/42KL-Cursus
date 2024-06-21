/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:08:57 by xquah             #+#    #+#             */
/*   Updated: 2024/06/03 13:23:20 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack *second_last;
	t_stack *last;

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
	ft_printf("rra\n");
}

void	rrb(t_stack **stk_b)
{
	reverse_rotate(stk_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **stk_a, t_stack **stk_b)
{
	reverse_rotate(stk_a);
	reverse_rotate(stk_b);
	ft_printf("rrr\n");
}