/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:29:01 by xquah             #+#    #+#             */
/*   Updated: 2024/06/27 13:54:19 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_long_atoi(const char *str)
{
	int		i;
	long	num;
	int		is_negative;

	i = -1;
	num = 0;
	is_negative = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
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

void	position_nodes(t_stack **stk)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = *stk;
	while (temp)
	{
		temp->pos = i++;
		temp = temp->next;
	}
}

int	is_sorted(t_stack **stk)
{
	t_stack	*temp;

	temp = *stk;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	stack_size(t_stack **stk)
{
	int		len;
	t_stack	*current;

	len = 0;
	current = *stk;
	while (current)
	{
		len++;
		current = current->next;
	}
	return (len);
}

void	free_stack(t_stack **stk)
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
