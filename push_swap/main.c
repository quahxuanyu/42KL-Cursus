/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:31:36 by xquah             #+#    #+#             */
/*   Updated: 2024/05/27 19:28:39 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

t_stack	*init_stack(int len, char *nums[])
{
	int i;
	t_stack *stk;
	t_stack *current;

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

void print_stack(t_stack *stk)
{
	t_stack *current;

	current = stk;
	while (current != NULL)
	{
		ft_printf("%i ", current->data);
		current = current->next;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stk_a;
	t_stack	*stk_b;

	stk_a = init_stack(argc, argv);
	stk_b = init_stack(0, NULL);
	ft_printf("Stack A: ");
	print_stack(stk_a);
	ft_printf("\nStack B: ");
	print_stack(stk_b);
	ft_printf("\nHello World! main.c");
}