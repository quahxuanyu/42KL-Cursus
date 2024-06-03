/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:20:12 by qtay              #+#    #+#             */
/*   Updated: 2024/05/30 12:27:12 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static char	*strip_leading(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' && (str[i + 1] == '0' || str[i + 1] == '\0'))
			i++;
		else if (str[i] == '+' || str[i] == '0')
			i++;
		else
			break ;
	}
	return (str + i);
}

static void	check_duplicates(char **split, char **container)
{
	int		i;
	int		j;
	char	*stripped_i;
	char	*stripped_j;

	i = 0;
	j = 0;
	while (split[i])
	{
		stripped_i = strip_leading(split[i]);
		j = i + 1;
		while (split[j])
		{
			stripped_j = strip_leading(split[j]);
			if (ft_strcmp(stripped_i, stripped_j) == 0)
			{
				free_array(&split);
				free(*container);
				error_exit();
			}
			j++;
		}
		i++;
	}
}

int	no_duplicates(char **container)
{
	char	**split;

	split = ft_split(*container, ' ');
	check_duplicates(split, container);
	free_array(&split);
	return (1);
}
