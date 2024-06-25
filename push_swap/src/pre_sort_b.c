/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 22:17:03 by xquah             #+#    #+#             */
/*   Updated: 2024/06/25 13:42:56 by xquah            ###   ########.fr       */
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

t_stack	*get_second_last_node(t_stack **stk)
{
	t_stack	*temp;

	temp = *stk;
	while (temp)
	{
		if (!temp->next->next)
			break ;
		temp = temp->next;
	}
	return (temp);
}

void	push_to_b(t_stack **stk_a, t_stack **stk_b)
{
	t_stack	*temp;
	int		len_to_push;
	int		mid;
	int		i;

	mid = stack_size(stk_a) / 2;
	len_to_push = stack_size(stk_a) - 3;
	i = 0;
	while (i < len_to_push / 2)
	{
		temp = *stk_a;
		if (temp->s_index < mid)
		{
			pb(stk_a, stk_b);
			i++;
		}
		else
			ra(stk_a);
	}
	while (i++ < len_to_push)
		pb(stk_a, stk_b);
}
