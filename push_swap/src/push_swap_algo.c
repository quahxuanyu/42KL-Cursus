/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 15:41:25 by xquah             #+#    #+#             */
/*   Updated: 2024/06/11 18:54:32 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void position_nodes(t_stack **stk)
{
	int i;
	t_stack *temp;

	i = 0;
	temp = *stk;
	while (temp)
	{
		temp->pos = i++;
		temp = temp->next;
	}
}

int calculate_cost(t_stack *node)
{
	int cost;

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

t_stack *find_cheapest(t_stack **stk)
{
	t_stack *current;
	t_stack *cheapest_node;

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

void push_node(t_stack **stk_a, t_stack **stk_b)
{
	t_stack *node_to_push;

	node_to_push = find_cheapest(stk_b);
	if (node_to_push->cost_a < 0 && node_to_push->cost_b < 0)
		while (node_to_push->cost_a < 0 && node_to_push->cost_b < 0)
		{
			rrr(stk_a, stk_b);
			node_to_push->cost_a++;
			node_to_push->cost_b++;
		}
	else if (node_to_push->cost_a > 0 && node_to_push->cost_b > 0)
		while (node_to_push->cost_a && node_to_push->cost_b)
		{
			rr(stk_a, stk_b);
			node_to_push->cost_a--;
			node_to_push->cost_b--;
		}
	//ft_printf("A to rotate: %i     B to rotate: %i\n", node_to_push->cost_a, node_to_push->cost_b);
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

void turk_sort(t_stack **stk_a, t_stack **stk_b)
{
	int len_to_push;
	int current_biggest;

	len_to_push = stack_size(stk_a) - 3;
	while (len_to_push--)
	{
		pb(stk_a, stk_b);
	}
	sort_three(stk_a);
	len_to_push = stack_size(stk_b);
	while (len_to_push--)
	{
		// ft_printf("Lenght of Stack B: %i\n", len_to_push);
		position_nodes(stk_a);
		position_nodes(stk_b);
		find_cost(stk_a, stk_b);
		push_node(stk_a, stk_b);
		// print_stack(stk_a);
		// ft_printf("\n");
		// print_s_index(stk_a);
		// display_both_stack(stk_a, stk_b);
	}
	// display_both_stack(stk_a, stk_b);
}

// void print_positions(t_stack **stk)
// {
// 	t_stack *current;

// 	current = *stk;
// 	while (current != NULL)
// 	{
// 		ft_printf("POSITIONS: ");
// 		ft_printf("%i ", current->pos);
// 		current = current->next;
// 	}
// }

// ft_printf("Stack A length: %i\n", get_stack_len(stk_a));
// t_stack	*current;
// current = *stk_a;
// while (current)
// {
// 	ft_printf("%i ", current->pos);
// 	current = current->next;
// }

/*int	ra_or_rra(int pos, int stack_size)
{
	if (pos <= stack_size / 2)
		return (pos);
	else
		return (pos)
}

int	find_pos_max(t_stack *b)
{
	int b_max;
	int max_pos;

	b_max = INT_MIN;
	while (b)
	{
		if (b_max < b->s_index)
		{
			b_max = b->s_index;
			max_pos = b->pos;
		}
		b = b->next;
	}
	return (max_pos);
}

void	assign_value(t_stack *a, t_stack *b, int sz_a, int sz_b)
{

}

void	find_cost(t_stack **stk_a, t_stack **stk_b)
{
	t_stack	*a;
	t_stack	*b;
	int		size_a;
	int		size_b;
	int		current_closest;

	a = *stk_a;
	b = *stk_b;
	size_a = get_stack_len(stk_a);
	size_b = get_stack_len(stk_b);
	if (!b)
		return ;
	while (a)
	{
		current_closest = INT_MAX;
		while (b)
		{
			if ((a->s_index - b->s_index) < current_closest)
			{
				//check if its ra or rra
				if (a->pos <= size_a / 2)
					a->cost_a = a->pos;
				else
					a->cost_a = (size_a - a->pos) * -1;
				if (b->pos <= size_b / 2)
					a->cost_b = b->pos;
				else
					a->cost_b = (size_b - b->pos) * -1;
			}
			if (!b->next && current_closest == INT_MAX)
			{
				a->cost_b =
			}
			b = b->next;
		}

	}
}*/