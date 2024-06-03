/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:30:21 by qtay              #+#    #+#             */
/*   Updated: 2024/05/29 14:03:11 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_node
{
	int				data;
	int				pos;
	int				cost_a;
	int				cost_b;
	int				s_index;
	struct s_node	*next;
}	t_node;

/* BUILD STACK */
void	create_stack(char **container, t_node **a);

/* OPERATIONS */
void	swap(t_node **stack, char *str);
int		do_both(t_node **a, t_node **b, char *ins);
void	rotate(t_node **stack, char *str, int cost);
void	push(t_node **stack_1, t_node **stack_2, char *str);
void	reverse_rotate(t_node **stack, char *str, int cost);
void	swap_both(t_node **a, t_node **b, int cost_a, int cost_b);
void	rotate_both(t_node **a, t_node **b, int cost_a, int cost_b);
void	reverse_rotate_both(t_node **a, t_node **b, int cost_a, int cost_b);

/* UTILITIES */
void	error_exit(void);
t_node	*lstlast(t_node *lst);
void	free_array(char ***str);
void	free_linked_list(t_node **stack);

/* VALIDATOR */
long	ft_atol(const char *nptr);
int		no_duplicates(char **container);
int		is_valid_input(char	**container);

#endif