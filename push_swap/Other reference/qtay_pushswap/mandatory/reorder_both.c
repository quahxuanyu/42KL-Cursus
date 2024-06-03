/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reorder_both.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:09:49 by qtay              #+#    #+#             */
/*   Updated: 2024/05/28 19:58:32 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	reverse_rotate_both(t_node **a, t_node **b, int cost_a, int cost_b)
{
	while (cost_b < 0 && cost_a < 0)
	{
		reverse_rotate(a, " ", -1);
		reverse_rotate(b, " ", -1);
		write(1, "rrr\n", 4);
		cost_a++;
		cost_b++;
	}
	reverse_rotate(a, "rra", cost_a);
	reverse_rotate(b, "rrb", cost_b);
}

void	rotate_both(t_node **a, t_node **b, int cost_a, int cost_b)
{
	while (cost_b > 0 && cost_a > 0)
	{
		rotate(a, " ", 1);
		rotate(b, " ", 1);
		write(1, "rr\n", 3);
		cost_a--;
		cost_b--;
	}
	rotate(a, "ra", cost_a);
	rotate(b, "rb", cost_b);
}

void	reorder_a_and_b(int cheapest_pos, t_node **a, t_node **b)
{
	t_node	*temp;

	temp = *b;
	while (temp->pos != cheapest_pos)
		temp = temp->next;
	if ((temp->cost_a < 0) && (temp->cost_b < 0))
		reverse_rotate_both(a, b, temp->cost_a, temp->cost_b);
	else if ((temp->cost_a > 0) && (temp->cost_b > 0))
		rotate_both(a, b, temp->cost_a, temp->cost_b);
	else if (temp->cost_b >= 0 && temp->cost_a <= 0)
	{
		rotate(b, "rb", temp->cost_b);
		reverse_rotate(a, "rra", temp->cost_a);
	}
	else if (temp->cost_b <= 0 && temp->cost_a >= 0)
	{
		reverse_rotate(b, "rrb", temp->cost_b);
		rotate(a, "ra", temp->cost_a);
	}
}
