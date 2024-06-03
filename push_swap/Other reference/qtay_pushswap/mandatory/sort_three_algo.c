/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:20:21 by qtay              #+#    #+#             */
/*   Updated: 2024/05/28 18:13:13 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_node **stack)
{
	int		first;
	int		second;
	int		third;

	first = (*stack)->s_index;
	second = (*stack)->next->s_index;
	third = (*stack)->next->next->s_index;
	if ((first < second) && (second < third))
		return ;
	else if ((first < second) && (first < third))
	{
		swap(stack, "sa");
		rotate(stack, "ra", 1);
	}
	else if ((first > second) && (second > third))
	{
		swap(stack, "sa");
		reverse_rotate(stack, "rra", -1);
	}
	else if ((first > second) && (first < third))
		swap(stack, "sa");
	else if ((first < second) && (first > third))
		reverse_rotate(stack, "rra", -1);
	else
		rotate(stack, "ra", 1);
}
