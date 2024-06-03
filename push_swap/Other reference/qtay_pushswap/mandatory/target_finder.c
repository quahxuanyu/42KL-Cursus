/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_finder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:19:13 by qtay              #+#    #+#             */
/*   Updated: 2024/05/28 20:00:40 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	find_target_index(t_node *a, t_node *b, int *target_pos)
{
	int	target_index;

	target_index = INT_MAX;
	while (a)
	{
		if (a->s_index > b->s_index && a->s_index < target_index)
		{
			target_index = a->s_index;
			*target_pos = a->pos;
		}
		a = a->next;
	}
}

static void	find_min(t_node *a, int *a_min_pos)
{
	int	a_min;

	a_min = INT_MAX;
	while (a)
	{
		if (a_min > a->s_index)
		{
			a_min = a->s_index;
			*a_min_pos = a->pos;
		}
		a = a->next;
	}
}

int	find_target_node(t_node *a, t_node *b)
{
	int	a_min_pos;
	int	target_pos;

	a_min_pos = a->pos;
	find_min(a, &a_min_pos);
	target_pos = INT_MAX;
	find_target_index(a, b, &target_pos);
	if (target_pos == INT_MAX)
	{
		b->cost_a = a_min_pos;
		return (a_min_pos);
	}
	else
	{
		b->cost_a = target_pos;
		return (target_pos);
	}
}
