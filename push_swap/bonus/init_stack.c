/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:01:16 by xquah             #+#    #+#             */
/*   Updated: 2024/06/27 14:03:44 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

t_stack	*init_stack(int *nums, int len)
{
	int		i;
	t_stack	*stk;
	t_stack	*current;

	i = -1;
	stk = malloc(sizeof(t_stack));
	if (!stk)
		return (NULL);
	current = stk;
	while (++i < len)
	{
		current->data = nums[i];
		if (i + 1 < len)
		{
			current->next = malloc(sizeof(t_stack));
			current = current->next;
		}
		else
			current->next = NULL;
	}
	return (stk);
}

char	**arg_to_str(char **av)
{
	int		i;
	char	**str_arr;
	char	*container;

	i = 1;
	container = NULL;
	while (av[i])
	{
		if (!av[i][0])
		{
			free(container);
			exit_error();
		}
		container = ft_strjoin(container, av[i++]);
		container = ft_strjoin(container, " ");
	}
	str_arr = ft_split(container, ' ');
	free(container);
	return (str_arr);
}
