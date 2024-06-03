/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_stack_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:15:52 by qtay              #+#    #+#             */
/*   Updated: 2024/05/29 15:23:10 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack_a(t_node **stack)
{
	int		moves;
	int		size;
	t_node	*temp;

	moves = 0;
	temp = *stack;
	size = stack_size(temp);
	while ((temp)->s_index != 0)
	{
		moves++;
		temp = temp->next;
	}
	if (moves > (size / 2))
		moves -= size;
	while (moves > 0)
	{
		rotate(stack, "ra", 1);
		moves--;
	}
	while (moves < 0)
	{
		reverse_rotate(stack, "rra", -1);
		moves++;
	}
}
