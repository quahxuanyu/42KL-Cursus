/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:46:01 by qtay              #+#    #+#             */
/*   Updated: 2024/05/28 20:02:03 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	assign_position(t_node **a, t_node **b)
{
	int		i;
	t_node	*temp_a;
	t_node	*temp_b;

	i = 0;
	temp_a = *a;
	temp_b = *b;
	while (temp_a)
	{
		temp_a->pos = i++;
		temp_a = temp_a->next;
	}
	i = 0;
	while (temp_b)
	{
		temp_b->pos = i++;
		temp_b = temp_b->next;
	}
}

int	find_cheapest_pos(t_node **b)
{
	int		cheapest;
	t_node	*temp;
	int		cost_a;
	int		cost_b;
	int		cheapest_pos;

	temp = *b;
	cheapest = INT_MAX;
	while (temp)
	{
		cost_a = temp->cost_a;
		if (cost_a < 0)
			cost_a = temp->cost_a * -1;
		cost_b = temp->cost_b;
		if (cost_b < 0)
			cost_b = temp->cost_b * -1;
		if (cheapest > (cost_a + cost_b))
		{
			cheapest = (cost_a + cost_b);
			cheapest_pos = temp->pos;
		}
		temp = temp->next;
	}
	return (cheapest_pos);
}

void	find_cost(t_node **a, t_node **b)
{
	t_node	*temp_b;
	int		size_a;
	int		size_b;
	int		target_pos;

	temp_b = *b;
	size_b = stack_size(*b);
	while (temp_b)
	{
		temp_b->cost_b = temp_b->pos;
		if (temp_b->cost_b > size_b / 2)
			temp_b->cost_b = (temp_b->pos - size_b);
		target_pos = find_target_node(*a, temp_b);
		size_a = stack_size(*a);
		if (target_pos > (size_a / 2))
			temp_b->cost_a = (temp_b->cost_a) - size_a;
		temp_b = temp_b->next;
	}
}
