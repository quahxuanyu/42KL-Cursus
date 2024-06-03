/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:38:53 by rteoh             #+#    #+#             */
/*   Updated: 2024/04/18 19:38:53 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	exe_com(const char *line, t_stack **stack_a, t_stack **stack_b)
{
	if (!(ft_strncmp(line, "sa", 2)))
	{
		do_sa(stack_a);
		return (0);
	}
	if (!(ft_strncmp(line, "sb", 2)))
	{
		do_sb(stack_b);
		return (0);
	}
	if (!(ft_strncmp(line, "ss", 2)))
	{
		do_ss(stack_a, stack_b);
		return (0);
	}
	if (!(ft_strncmp(line, "pa", 2)))
	{
		do_pa(stack_a, stack_b);
		return (0);
	}
	if (!(ft_strncmp(line, "pb", 2)))
	{
		do_pb(stack_a, stack_b);
		return (0);
	}
	if (!(ft_strncmp(line, "ra", 2)))
	{
		do_ra(stack_a);
		return (0);
	}
	if (!(ft_strncmp(line, "rb", 2)))
	{
		do_rb(stack_b);
		return (0);
	}
	if (!(ft_strncmp(line, "rr\n", 3)))
	{
		do_rr(stack_a, stack_b);
		return (0);
	}
	if (!(ft_strncmp(line, "rra", 3)))
	{
		do_rra(stack_a);
		return (0);
	}
	if (!(ft_strncmp(line, "rrb", 3)))
	{
		do_rrb(stack_b);
		return (0);
	}
	if (!(ft_strncmp(line, "rrr", 3)))
	{
		do_rrr(stack_a, stack_b);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;
	int		len;

	if (ac < 2)
		return (0);
	else if (ac == 2)
	{
		av = make_input(av);
		ac = count_input(av);
	}
	if (is_correct_input(av))
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = fill_stack_values(ac, av);
	len = get_stack_size(stack_a);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		exe_com(line, &stack_a, &stack_b);
		line = get_next_line(STDIN_FILENO);
	}
	if (!is_sorted(stack_a) && get_stack_size(stack_a) == len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
