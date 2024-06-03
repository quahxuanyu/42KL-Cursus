/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:53:26 by qtay              #+#    #+#             */
/*   Updated: 2024/06/03 16:57:23 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_sorted(t_node *a)
{
	t_node	*temp;

	temp = a;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

static void	push_to_a(t_node **a, t_node **b)
{
	int	cheapest_pos;

	while (*b)
	{
		assign_position(a, b);
		find_cost(a, b);
		cheapest_pos = find_cheapest_pos(b);
		reorder_a_and_b(cheapest_pos, a, b);
		push(b, a, "pa");
	}
}

static void	push_swap(t_node **a)
{
	t_node	*b;

	b = NULL;
	if (is_sorted(*a))
	{
		free_linked_list(a);
		exit(0);
	}
	else if (stack_size(*a) == 2)
		swap(a, "sa");
	else if (stack_size(*a) == 3)
		sort_three(a);
	else if (stack_size(*a) > 3)
	{
		midpoint_sort(a, &b);
		sort_three(a);
	}
	push_to_a(a, &b);
	sort_stack_a(a);
	free_linked_list(&b);
	return ;
}

static char	*arg_to_str(char **av, char **container)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!av[i][0])
		{
			free(*container);
			error_exit();
		}
		*container = ft_strjoin(*container, av[i++]);
		*container = ft_strjoin(*container, " ");
	}
	return (*container);
}

int	main(int ac, char *av[])
{
	t_node	*a;
	char	*container;

	if (ac >= 2)
	{
		container = NULL;
		container = arg_to_str(av, &container);
		if (!is_valid_input(&container) || !no_duplicates(&container))
			error_exit();
		a = NULL;
		create_stack(&container, &a);
		add_sorting_index(&a);
		push_swap(&a);
		free_linked_list(&a);
	}
	return (0);
}
