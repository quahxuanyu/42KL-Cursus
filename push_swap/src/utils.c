/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:29:01 by xquah             #+#    #+#             */
/*   Updated: 2024/06/03 15:00:03 by xquah            ###   ########.fr       */
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
	while (*str == '\n' || *str == '\t' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == ' ')
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

void	free_stack(t_stack stk)
{

}

void	exit_error(t_stack **stk_a, t_stack **stk_b)
{
	ft_printf("Error\n");
	exit(1);
}