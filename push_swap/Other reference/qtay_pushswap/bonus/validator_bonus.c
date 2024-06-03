/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:42:59 by qtay              #+#    #+#             */
/*   Updated: 2024/05/28 20:20:33 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

long	ft_atol(const char *nptr)
{
	int		i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] != '\0' && (nptr[i] == ' '
			|| (nptr[i] >= 9 && nptr[i] <= 13)))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
		result = (result * 10) + (nptr[i++] - '0');
	if (nptr[i] != '\0' && !(nptr[i] >= '0' && nptr[i] <= '9'))
		return (0);
	return (sign * result);
}

static int	check_if_not_int(char *str)
{
	long	n;

	if (str[0] == '0' && str[1] == '\0')
		return (0);
	else
	{
		n = ft_atol(str);
		if (n == 0 || n > INT_MAX || n < INT_MIN)
			return (1);
		return (0);
	}
}

int	is_valid_input(char	**container)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(*container, ' ');
	while (split[i])
	{
		if (check_if_not_int((split)[i++]) == 1)
		{
			free_array(&split);
			free(*container);
			error_exit();
		}
	}
	free_array(&split);
	return (1);
}
