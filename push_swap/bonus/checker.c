/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:45:39 by xquah             #+#    #+#             */
/*   Updated: 2024/06/27 14:01:34 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	do_both(t_stack **a, t_stack **b, char *ins)
{
	if (ft_strcmp(ins, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(ins, "rrr\n") == 0)
		rrr(a, b);
	else if (ft_strcmp(ins, "ss\n") == 0)
		ss(a, b);
	else
		return (0);
	return (1);
}

static void	check_and_do_ins(t_stack **a, t_stack **b, char *ins)
{
	if (ft_strcmp(ins, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(ins, "sb\n") == 0)
		sb(b);
	else if (ft_strcmp(ins, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(ins, "pb\n") == 0)
		pb(a, b);
	else if (ft_strcmp(ins, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(ins, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(ins, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(ins, "rrb\n") == 0)
		rrb(b);
	else if (do_both(a, b, ins))
		return ;
	else
		exit_error();
}

void	checker(t_stack **a, t_stack **b)
{
	char	*steps;

	steps = malloc(sizeof(char));
	while (steps)
	{
		free(steps);
		steps = get_next_line(0);
		if (steps)
			check_and_do_ins(a, b, steps);
	}
	if (is_sorted(a) && !(*b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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
		checker(&stk_a, &stk_b);
		free_stack(&stk_a);
		free(arr);
	}
}
