/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:46:40 by xquah             #+#    #+#             */
/*   Updated: 2024/06/13 12:46:25 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stk_a)
{
	int	first;
	int	second;
	int third;

	first = (*stk_a)->s_index;
	second = (*stk_a)->next->s_index;
	third = (*stk_a)->next->next->s_index;
	if (is_sorted(stk_a))
		return ;
	if (first < second && first < third)
	{
		sa(stk_a);
		ra(stk_a);
	}
	else if (first > second && second > third)
	{
		sa(stk_a);
		rra(stk_a);
	}
	else if (first > second && first < third)
		sa(stk_a);
	else if (first < second && first > third)
		rra(stk_a);
	else
		ra(stk_a);
}