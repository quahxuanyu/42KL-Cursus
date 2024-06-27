/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:59:19 by xquah             #+#    #+#             */
/*   Updated: 2024/06/27 13:53:22 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_clean_input(char *clean_input[], int input_len)
{
	while (--input_len > -1)
		free(clean_input[input_len]);
	free(clean_input);
}

int	count_words(char **clean_input)
{
	int	count;

	count = 0;
	while (clean_input[count])
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

int	has_chr(char *str)
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

int	validate_input(char *clean_input[], int **arr)
{
	int		i;
	int		input_len;
	long	num;

	i = -1;
	input_len = count_words(clean_input);
	*arr = malloc(sizeof(int) * input_len);
	while (clean_input[++i])
	{
		num = ft_long_atoi(clean_input[i]);
		if (num > 2147483647 || num < -2147483648 || has_chr(clean_input[i]))
		{
			clear_clean_input(clean_input, input_len);
			free(*arr);
			exit_error();
		}
		(*arr)[i] = (int) num;
	}
	clear_clean_input(clean_input, input_len);
	check_duplicate(*arr, input_len);
	return (input_len);
}
