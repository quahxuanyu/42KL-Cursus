/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_stack_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:49:28 by xquah             #+#    #+#             */
/*   Updated: 2024/06/11 18:20:44 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_stack_a(t_stack **stk_a)
{
	t_stack	*current;
	int	times_to_rotate;
	
	position_nodes(stk_a);
	current = *stk_a;
	while (current)
	{
		if (current->s_index == 0)
			break ;
		current = current->next;
	}
	if (current->pos > (stack_size(stk_a) / 2))
	{
		times_to_rotate = (stack_size(stk_a) - current->pos);
		while (times_to_rotate--)
			rra(stk_a);
	}
	else
	{
		times_to_rotate = current->pos;
		while (times_to_rotate--)
			ra(stk_a);
	}
}