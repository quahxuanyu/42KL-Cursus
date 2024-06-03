/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   midpoint_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:00:23 by qtay              #+#    #+#             */
/*   Updated: 2024/06/02 13:03:39 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_midpt(t_node *a)
{
	int		i;
	int		sum;
	t_node	*temp;

	i = 0;
	sum = 0;
	temp = a;
	while (temp)
	{
		sum += temp->s_index;
		i++;
		temp = temp->next;
	}
	if (i % 2 == 0)
		return (sum / i);
	else
		return ((sum / i) + 1);
}

static void	push_to_b(t_node **a, t_node **b, int *runs, int *nodes_to_push)
{
	push(a, b, "pb");
	(*runs)--;
	(*nodes_to_push)--;
}

static void	find_next_node(t_node **a, int *max_iter)
{
	rotate(a, "ra", 1);
	(*max_iter)++;
}

static void	send_to_b(t_node **a, t_node **b, int *nodes_to_push, int midpt)
{
	int	runs;
	int	max_iter;

	max_iter = 0;
	runs = ((*nodes_to_push / 2) + 1);
	while (runs > 0)
	{
		if ((*a)->s_index <= midpt)
			push_to_b(a, b, &runs, nodes_to_push);
		else if ((*a)->next->s_index <= midpt)
		{
			rotate(a, "ra", 1);
			push_to_b(a, b, &runs, nodes_to_push);
		}
		else if (lstlast(*a)->s_index <= midpt)
		{
			reverse_rotate(a, "rra", -1);
			push_to_b(a, b, &runs, nodes_to_push);
		}
		else if (max_iter == 5)
			push_to_b(a, b, &runs, nodes_to_push);
		else
			find_next_node(a, &max_iter);
	}
}

void	midpoint_sort(t_node **a, t_node **b)
{
	int	midpt;
	int	nodes_to_push;

	nodes_to_push = stack_size(*a) - 3;
	while (nodes_to_push > 0)
	{
		midpt = find_midpt(*a);
		send_to_b(a, b, &nodes_to_push, midpt);
	}
}
