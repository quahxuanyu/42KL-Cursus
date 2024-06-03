/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:55:38 by qtay              #+#    #+#             */
/*   Updated: 2024/05/28 19:59:09 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	assign_index(t_node **stack, int *sorted_array)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = *stack;
	while (temp)
	{
		if (sorted_array[i] == temp->data)
		{
			temp->s_index = i;
			temp = temp->next;
			i = 0;
		}
		else
			i++;
	}
}

static void	sort_int_array(int **tab, int size)
{
	int	i;
	int	temp;
	int	*new;

	new = *tab;
	i = 0;
	while (i < (size - 1))
	{
		if (new[i] > new[i + 1])
		{
			temp = new[i];
			new[i] = new[i + 1];
			new[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	*tab = new;
}

void	add_sorting_index(t_node **a)
{
	int		i;
	int		size;
	t_node	*temp;
	int		*sorted_array;

	size = stack_size(*a);
	sorted_array = malloc(sizeof(int) * size);
	if (!sorted_array)
		return ;
	i = 0;
	temp = *a;
	while (temp)
	{
		sorted_array[i++] = temp->data;
		temp = temp->next;
	}
	sort_int_array(&sorted_array, size);
	temp = *a;
	assign_index(&temp, sorted_array);
	*a = temp;
	free(sorted_array);
}
