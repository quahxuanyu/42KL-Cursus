/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:31:36 by xquah             #+#    #+#             */
/*   Updated: 2024/05/30 17:12:54 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(int len, char *nums[])
{
	int		i;
	t_stack	*stk;
	t_stack	*current;

	i = 0;
	stk = malloc(sizeof(t_stack));
	current = stk;
	while (++i < len)
	{
		current->data = ft_atoi(nums[i]);
		if (i + 1 < len)
		{
			current->next = malloc(sizeof(t_stack));
			current = current->next;
		}
		else
			current->next = NULL;
	}
	return (stk);
}

void	print_stack(t_stack *stk)
{
	t_stack	*current;

	current = stk;
	while (current != NULL)
	{
		ft_printf("%i ", current->data);
		current = current->next;
	}
}

void	display_stack(t_stack *stk_a, t_stack *stk_b)
{
	ft_printf("Stack A: ");
	print_stack(stk_a);
	ft_printf("\nStack B: ");
	print_stack(stk_b);
	ft_printf("\n");
}

int	main(int argc, char *argv[])
{
	t_stack	*stk_a;
	t_stack	*stk_b;

	stk_a = init_stack(argc, argv);
	stk_b = NULL;

	ft_printf("------Initialize Stack------\n");
	display_stack(stk_a, stk_b);

	ft_printf("------Actions------\n");
	pb(&stk_a, &stk_b);
	display_stack(stk_a, stk_b);
	
	pb(&stk_a, &stk_b);
	display_stack(stk_a, stk_b);
}
