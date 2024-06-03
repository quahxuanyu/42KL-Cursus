/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:33:19 by qtay              #+#    #+#             */
/*   Updated: 2024/05/28 19:52:36 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_array(char ***str)
{
	int	i;

	i = 0;
	while ((*str)[i])
		i++;
	while (i >= 0)
		free((*str)[i--]);
	free(*str);
}

t_node	*lstlast(t_node *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	free_linked_list(t_node **stack)
{
	t_node	*temp;
	t_node	*temp2;

	temp = (*stack);
	while (temp)
	{
		temp2 = temp;
		temp = temp->next;
		temp2->next = NULL;
		free(temp2);
	}
}
