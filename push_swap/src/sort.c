/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:14:31 by xquah             #+#    #+#             */
/*   Updated: 2024/06/03 17:48:17 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	get_stack_size(t_stack **stk)
{
	t_stack	*cur;
	int	count;

	count = 0;
	cur = *stk;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return (count);
}

void bubble_sort(int **lst)
{

}

void	sort_index(t_stack **stk)
{
	int	*sorted_arr;
	int	size;
	int i;
	t_stack *temp;

	size = get_stack_size(stk);
	sorted_arr = malloc(sizeof(int) * get_stack_size(stk));
	temp = *stk;
	i = -1;
	while (i++ < size)
	{
		sorted_arr[i] = temp->data;
		temp = temp->next;
	}
	bubble_sort(sorted_arr);
}