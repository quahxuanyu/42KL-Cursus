/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:41:25 by xquah             #+#    #+#             */
/*   Updated: 2024/06/25 14:44:18 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_cost(t_stack *node)
{
	int	cost;

	cost = 0;
	if (node->cost_a < 0)
		cost += node->cost_a * -1;
	else
		cost += node->cost_a;
	if (node->cost_b < 0)
		cost += node->cost_b * -1;
	else
		cost += node->cost_b;
	return (cost);
}

t_stack	*find_cheapest(t_stack **stk)
{
	t_stack	*current;
	t_stack	*cheapest_node;

	current = *stk;
	cheapest_node = NULL;
	while (current)
	{
		if (cheapest_node)
		{
			if (calculate_cost(cheapest_node) > calculate_cost(current))
				cheapest_node = current;
		}
		else
			cheapest_node = current;
		current = current->next;
	}
	return (cheapest_node);
}

void	rotate_both(t_stack *node_to_push, t_stack **stk_a, t_stack **stk_b)
{
	if (node_to_push->cost_a < 0 && node_to_push->cost_b < 0)
	{
		while (node_to_push->cost_a < 0 && node_to_push->cost_b < 0)
		{
			rrr(stk_a, stk_b);
			node_to_push->cost_a++;
			node_to_push->cost_b++;
		}
	}
	else if (node_to_push->cost_a > 0 && node_to_push->cost_b > 0)
	{
		while (node_to_push->cost_a && node_to_push->cost_b)
		{
			rr(stk_a, stk_b);
			node_to_push->cost_a--;
			node_to_push->cost_b--;
		}
	}
}

void	push_node(t_stack **stk_a, t_stack **stk_b)
{
	t_stack	*node_to_push;

	node_to_push = find_cheapest(stk_b);
	rotate_both(node_to_push, stk_a, stk_b);
	if (node_to_push->cost_a < 0)
		while (node_to_push->cost_a++ < 0)
			rra(stk_a);
	else
		while (node_to_push->cost_a-- > 0)
			ra(stk_a);
	if (node_to_push->cost_b < 0)
		while (node_to_push->cost_b++ < 0)
			rrb(stk_b);
	else
		while (node_to_push->cost_b-- > 0)
			rb(stk_b);
	pa(stk_a, stk_b);
}

void	turk_sort(t_stack **stk_a, t_stack **stk_b)
{
	int	len_to_push;

	push_to_b(stk_a, stk_b);
	sort_three(stk_a);
	len_to_push = stack_size(stk_b);
	while (len_to_push--)
	{
		position_nodes(stk_a);
		position_nodes(stk_b);
		find_cost(stk_a, stk_b);
		push_node(stk_a, stk_b);
	}
}
