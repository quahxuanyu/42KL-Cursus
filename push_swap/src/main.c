/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:31:36 by xquah             #+#    #+#             */
/*   Updated: 2024/06/25 13:41:36 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(int *nums, int len)
{
	int		i;
	t_stack	*stk;
	t_stack	*current;

	i = -1;
	stk = malloc(sizeof(t_stack));
	if (!stk)
		return (NULL);
	current = stk;
	while (++i < len)
	{
		current->data = nums[i];
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

static char	**arg_to_str(char **av)
{
	int		i;
	char	**str_arr;
	char	*container;

	i = 1;
	container = NULL;
	while (av[i])
	{
		if (!av[i][0])
		{
			free(container);
			exit_error();
		}
		container = ft_strjoin(container, av[i++]);
		container = ft_strjoin(container, " ");
	}
	str_arr = ft_split(container, ' ');
	free(container);
	return (str_arr);
}

void	push_swap(t_stack **stk_a, t_stack **stk_b, int stack_size)
{
	if (is_sorted(stk_a))
		return ;
	else if (stack_size == 2)
		sa(stk_a);
	else if (stack_size == 3)
		sort_three(stk_a);
	else if (stack_size > 3)
		turk_sort(stk_a, stk_b);
}

int	main(int argc, char *argv[])
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	int		*arr;
	int		input_len;
	char	**clean_input;

	if (argc >= 2)
	{
		clean_input = arg_to_str(argv);
		input_len = validate_input(clean_input, &arr);
		stk_a = init_stack(arr, input_len);
		stk_b = NULL;
		sort_index(&stk_a);
		push_swap(&stk_a, &stk_b, input_len);
		order_stack_a(&stk_a);
		free_stack(&stk_a);
		while (--input_len > -1)
			free(clean_input[input_len]);
		free(clean_input);
		free(arr);
	}
	return (0);
}
