/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:59:19 by xquah             #+#    #+#             */
/*   Updated: 2024/06/13 15:21:38 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char **argv)
{
	int count;

	count = 0;
	while (argv[count])
		count++;
	return (count);
}

void	check_duplicate(int *arr, int len)
{
	int	i;
	int	j;

	i = -1;
	while (++i < len)
	{
		j = i;
		while (++j < len)
		{
			if (arr[i] == arr[j])
			{
				free(arr);
				exit_error();
			}
		}
	}
}

int	contains_characters(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (i == 0 && (str[i] == '+' || str[i] == '-') && str[i + 1])
			continue ;
		if ((str[i] >= '0' && str[i] <= '9'))
			continue ;
		else
			return (1);
	}
	return (0);
}

int	validate_input(char *argv[], int **arr)
{
	int		i;
	long	num;

	i = -1;
	*arr = malloc(sizeof(int) * count_words(argv));
	while (argv[++i])
	{
		num = ft_long_atoi(argv[i]);
		if (num > 2147483647 || num < -2147483648 || contains_characters(argv[i]))
		{
			free(*arr);
			exit_error();
		}
		(*arr)[i] = (int) num;
	}
	check_duplicate(*arr, count_words(argv));
	return (count_words(argv));
}