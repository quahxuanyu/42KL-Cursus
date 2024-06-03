/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:25:31 by qtay              #+#    #+#             */
/*   Updated: 2024/05/29 14:02:51 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	swap(t_node **stack, char *str)
{
	t_node	*temp;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	if (ft_strcmp(str, "sa") == 0)
		write(1, "sa\n", 3);
	else if (ft_strcmp(str, "sb") == 0)
		write(1, "sb\n", 3);
}

void	rotate(t_node **stack, char *str, int cost)
{
	t_node	*last;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	while (cost--)
	{
		last = lstlast(*stack);
		last->next = *stack;
		*stack = (*stack)->next;
		last->next->next = NULL;
		if (ft_strcmp(str, "ra") == 0)
			write(1, "ra\n", 3);
		else if (ft_strcmp(str, "rb") == 0)
			write(1, "rb\n", 3);
	}
}

void	reverse_rotate(t_node **stack, char *str, int cost)
{
	t_node	*last;
	t_node	*temp;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	while (cost++)
	{
		temp = *stack;
		last = lstlast(*stack);
		while ((*stack)->next->next != NULL)
			*stack = (*stack)->next;
		(*stack)->next = NULL;
		last->next = temp;
		*stack = last;
		if (ft_strcmp(str, "rra") == 0)
			write(1, "rra\n", 4);
		else if (ft_strcmp(str, "rrb") == 0)
			write(1, "rrb\n", 4);
	}
}

void	push(t_node **stack_1, t_node **stack_2, char *str)
{
	t_node	*temp;

	if (!stack_1 || !(*stack_1) || !stack_2)
		return ;
	temp = *stack_1;
	*stack_1 = temp->next;
	temp->next = *stack_2;
	*stack_2 = temp;
	if (ft_strcmp(str, "pa") == 0)
		write(1, "pa\n", 3);
	else if (ft_strcmp(str, "pb") == 0)
		write(1, "pb\n", 3);
}

int	do_both(t_node **a, t_node **b, char *ins)
{
	if (ft_strcmp(ins, "rr\n") == 0)
		rotate_both(a, b, 1, 1);
	else if (ft_strcmp(ins, "rrr\n") == 0)
		reverse_rotate_both(a, b, -1, -1);
	else if (ft_strcmp(ins, "ss\n") == 0)
		swap_both(a, b, 1, 1);
	else
		return (0);
	return (1);
}
