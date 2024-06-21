/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 22:17:03 by xquah             #+#    #+#             */
/*   Updated: 2024/06/21 23:51:03 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_last_node(t_stack **stk)
{
	t_stack	*temp;
	
	temp = *stk;
	while (temp)
	{
		if (!temp->next)
			break ;
		temp = temp->next;
	}
	return (temp);
}

int	get_percentile(t_stack **stk, int percentile)
{
	t_stack	*temp;
	int		total;
	
	if (!(*stk))
		return (INT_MAX);
	total = 0;
	temp = *stk;
	while (temp)
	{
		total += temp->data;
		temp = temp->next;
	}
	return (total * (percentile / 100));
}

void	push_to_b(t_stack **stk_a, t_stack **stk_b)
{
	t_stack	*temp;
	int		len_to_push;
	int		margin;

	len_to_push = stack_size(stk_a) - 3;
	while (len_to_push--)
	{
		temp = *stk_a;
		margin = get_percentile(stk_b, 25);
		if (temp->next->data < margin)
			ra(stk_a);
		else if (get_last_node(stk_a)->data < margin)
			rra(stk_a);
		pb(stk_a, stk_b);
		if ((*stk_b) < get_percentile(stk_b, 12))
			rb(stk_b);
	}
}