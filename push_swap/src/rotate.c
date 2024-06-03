/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:49:31 by xquah             #+#    #+#             */
/*   Updated: 2024/06/03 12:56:10 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack *temp;
	t_stack *current;

	current = *stack;
	while (current->next)
		current = current->next;
	temp = *stack;
	(*stack) = (*stack)->next;
	temp->next = NULL;
	current->next = temp;
}

void	ra(t_stack **stk_a)
{
	rotate(stk_a);
	ft_printf("ra\n");
}

void	rb(t_stack **stk_b)
{
	rotate(stk_b);
	ft_printf("rb\n");
}

void	rr(t_stack **stk_a, t_stack **stk_b)
{
	rotate(stk_a);
	rotate(stk_b);
	ft_printf("rr\n");
}