/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:29:01 by xquah             #+#    #+#             */
/*   Updated: 2024/06/15 15:11:45 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long ft_long_atoi(const char *str)
{
	int i;
	long num;
	int is_negative;

	i = -1;
	num = 0;
	is_negative = 0;
	while (*str == '\n' || *str == '\t' || *str == '\v' || *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		is_negative = (*str == '-');
		str++;
	}
	while (str[++i] >= '0' && str[i] <= '9')
		num = (num * 10) + str[i] - '0';
	if (is_negative)
		num = num * -1;
	return (num);
}

// TO BE REMOVED
void print_stack(t_stack **stk)
{
	t_stack *current;

	current = *stk;
	while (current != NULL)
	{
		ft_printf("%i ", current->data);
		current = current->next;
	}
}

void print_costs(t_stack **stk)
{
	t_stack *current;

	current = *stk;
	ft_printf("\nStack cost_a: ");
	while (current != NULL)
	{
		ft_printf("%i ", current->cost_a);
		current = current->next;
	}

	current = *stk;
	ft_printf("\nStack cost_b: ");
	while (current != NULL)
	{
		ft_printf("%i ", current->cost_b);
		current = current->next;
	}
}

void display_both_stack(t_stack **stk_a, t_stack **stk_b)
{
	ft_printf("Stack A: ");
	print_stack(stk_a);
	ft_printf("\nStack B: ");
	print_stack(stk_b);

	ft_printf("\nCOST Bs: ");
	print_costs(stk_b);
	ft_printf("\n");
}

void print_s_index(t_stack **stk)
{
	t_stack *current;

	current = *stk;
	while (current != NULL)
	{
		ft_printf("%i ", current->s_index);
		current = current->next;
	}
}

int is_sorted(t_stack **stk)
{
	t_stack *temp;

	temp = *stk;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int stack_size(t_stack **stk)
{
	int len;
	t_stack *current;

	len = 0;
	current = *stk;
	while (current)
	{
		len++;
		current = current->next;
	}
	return (len);
}

void free_stack(t_stack **stk)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = (*stk);
	while (temp)
	{
		temp2 = temp;
		temp = temp->next;
		temp2->next = NULL;
		free(temp2);
	}
}

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}