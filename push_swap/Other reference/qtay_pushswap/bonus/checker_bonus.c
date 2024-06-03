/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:28:36 by qtay              #+#    #+#             */
/*   Updated: 2024/06/02 13:30:04 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

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

static void	check_and_do_ins(t_node **a, t_node **b, char *ins)
{
	if (ft_strcmp(ins, "sa\n") == 0)
		swap(a, " ");
	else if (ft_strcmp(ins, "sb\n") == 0)
		swap(b, " ");
	else if (ft_strcmp(ins, "pa\n") == 0)
		push(b, a, " ");
	else if (ft_strcmp(ins, "pb\n") == 0)
		push(a, b, " ");
	else if (ft_strcmp(ins, "ra\n") == 0)
		rotate(a, " ", 1);
	else if (ft_strcmp(ins, "rb\n") == 0)
		rotate(b, " ", 1);
	else if (ft_strcmp(ins, "rra\n") == 0)
		reverse_rotate(a, " ", -1);
	else if (ft_strcmp(ins, "rrb\n") == 0)
		reverse_rotate(b, " ", -1);
	else if (do_both(a, b, ins))
		return ;
	else
		error_exit();
}

static void	checker(t_node **a, t_node **b)
{
	char	*instructions;

	instructions = malloc(sizeof(char));
	while (instructions)
	{
		free(instructions);
		instructions = get_next_line(0);
		if (instructions)
			check_and_do_ins(a, b, instructions);
	}
	if (is_sorted(*a) && !(*b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	char	*container;

	if (ac >= 2)
	{
		container = NULL;
		container = arg_to_str(av, &container);
		if (!is_valid_input(&container) || !no_duplicates(&container))
			error_exit();
		a = NULL;
		b = NULL;
		create_stack(&container, &a);
		checker(&a, &b);
		free_linked_list(&a);
	}
	return (0);
}
