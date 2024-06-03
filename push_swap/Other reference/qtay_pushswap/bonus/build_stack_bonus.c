/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:48:06 by qtay              #+#    #+#             */
/*   Updated: 2024/05/28 19:42:09 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	create_stack(char **container, t_node **a)
{
	int		i;
	int		n;
	t_node	*node;
	char	**split;

	i = 0;
	split = ft_split(*container, ' ');
	free(*container);
	while (split[i])
	{
		node = malloc(sizeof(t_node));
		n = ft_atol(split[i]);
		node->data = n;
		node->next = NULL;
		node->s_index = 0;
		if (!*a)
			*a = node;
		else
			lstlast(*a)->next = node;
		i++;
	}
	free_array(&split);
}
