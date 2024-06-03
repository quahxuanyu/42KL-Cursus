/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:51:21 by qtay              #+#    #+#             */
/*   Updated: 2024/06/03 12:48:55 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_node
{
	int				pos;
	int				data;
	int				cost_a;
	int				cost_b;
	int				s_index;
	struct s_node	*next;
}	t_node;

/* BUILD STACK */
void	create_stack(char **container, t_node **a);

/* MIDPOINT ALGORITHM */
void	midpoint_sort(t_node **a, t_node **b);

/* OPERATIONS */
void	swap(t_node **stack, char *str);
void	rotate(t_node **stack, char *str, int cost);
void	reverse_rotate(t_node **stack, char *str, int cost);
void	push(t_node **stack_1, t_node **stack_2, char *str);
void	rotate_both(t_node **a, t_node **b, int cost_a, int cost_b);
void	reverse_rotate_both(t_node **a, t_node **b, int cost_a, int cost_b);

/* TURK ALGORITHM & COST CALCULATION */
void	sort_three(t_node **stack);
void	sort_stack_a(t_node **stack);
int		find_cheapest_pos(t_node **b);
void	find_cost(t_node **a, t_node **b);
int		find_target_node(t_node *a, t_node *b);
void	assign_position(t_node **a, t_node **b);
void	reorder_a_and_b(int cheapest_pos, t_node **a, t_node **b);

/* INITIAL SORTING: BUBBLE SORT */
void	add_sorting_index(t_node **a);

/* UTILITIES */
void	error_exit(void);
t_node	*lstlast(t_node *lst);
void	free_array(char ***str);
int		stack_size(t_node *stack);
void	free_linked_list(t_node **stack);

/* VALIDATOR */
long	ft_atol(const char *nptr);
int		no_duplicates(char **container);
int		is_valid_input(char	**container);

#endif