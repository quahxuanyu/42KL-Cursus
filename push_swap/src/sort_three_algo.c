/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:46:40 by xquah             #+#    #+#             */
/*   Updated: 2024/06/04 18:03:30 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stk_a)
{
	int	first;
	int	second;

	first = (*stk_a)->s_index;
	second = (*stk_a)->next->s_index;
	if (first == 1 && second == 0)
		sa(stk_a);
	else if (first == 2 && second == 1)
	{
		sa(stk_a);
		rra(stk_a);
	}
	else if (first == 2 && second == 0)
		ra(stk_a);
	else if (first == 0 && second == 2)
	{
		sa(stk_a);
		ra(stk_a);
	}
	else if (first == 1 && second == 3)
		rra(stk_a);
}