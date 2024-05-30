/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:49:31 by xquah             #+#    #+#             */
/*   Updated: 2024/05/30 15:57:23 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack *temp;
	t_stack *current;

	current = *stack;
	temp = *stack;
	(*stack) = (*stack)->next;
	temp->next = NULL;
	while (current->next)
		current = current->next;
	current->next = temp;
	
	
}