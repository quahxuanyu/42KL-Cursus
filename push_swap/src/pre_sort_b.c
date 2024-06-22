/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 22:17:03 by xquah             #+#    #+#             */
/*   Updated: 2024/06/22 01:10:47 by xquah            ###   ########.fr       */
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

t_stack *get_second_last_node(t_stack **stk)
{
	t_stack *temp;

	temp = *stk;
	while (temp)
	{
		if (!temp->next->next)
			break;
		temp = temp->next;
	}
	return (temp);
}

int	get_percentile(t_stack **stk, float percentile)
{
	t_stack	*temp;
	int		total;
	
	if (!(*stk))
		return (INT_MIN);
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
		margin = get_percentile(stk_a, 25);
		//ft_printf("25th percentile: %i\n", margin);

		if (temp->next->data < temp->data && temp->next->data > margin)
			ra(stk_a);
		else if (get_last_node(stk_a)->data < temp->data)
			rra(stk_a);
		// if (temp->next->data < margin)
		// 	ra(stk_a);
		// else if (get_last_node(stk_a)->data < margin)
		// 	rra(stk_a);
		// else if (temp->next->next->data < margin)
		// {
		// 	ra(stk_a);
		// 	ra(stk_a);
		// }
		// else if (get_second_last_node(stk_a)->data < margin)
		// {
		// 	rra(stk_a);
		// 	rra(stk_a);
		// }
		pb(stk_a, stk_b);
		if ((*stk_b)->next && (*stk_b)->data < (*stk_b)->next->data)
			rb(stk_b);
	}
}