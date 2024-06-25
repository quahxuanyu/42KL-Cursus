/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:14:31 by xquah             #+#    #+#             */
/*   Updated: 2024/06/25 14:45:36 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	label_stack_index(t_stack **stk, int *arr)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = *stk;
	while (temp)
	{
		if (temp->data == arr[i])
		{
			temp->s_index = i;
			temp = temp->next;
			i = 0;
		}
		else
			i++;
	}
}

int	get_stack_size(t_stack **stk)
{
	t_stack	*cur;
	int		count;

	count = 0;
	cur = *stk;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return (count);
}

void	bubble_sort(int *lst, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < (size - 1))
	{
		if (lst[i] > lst[i + 1])
		{
			temp = lst[i];
			lst[i] = lst[i + 1];
			lst[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

void	sort_index(t_stack **stk)
{
	int		*sorted_arr;
	int		size;
	int		i;
	t_stack	*temp;

	size = get_stack_size(stk);
	sorted_arr = malloc(sizeof(int) * size);
	temp = *stk;
	i = -1;
	while (++i < size)
	{
		sorted_arr[i] = temp->data;
		temp = temp->next;
	}
	bubble_sort(sorted_arr, size);
	label_stack_index(stk, sorted_arr);
	free(sorted_arr);
}
