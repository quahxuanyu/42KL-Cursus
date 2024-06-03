/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:20:40 by rteoh             #+#    #+#             */
/*   Updated: 2024/03/01 16:20:40 by rteoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>

# define BUFF_SIZE (1)

typedef	struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack *next;
}	t_stack;

/*input checks + input checks utils*/
int	is_correct_input(char **av);
int	is_digit(char c);
int	is_sign(char c);
int	arg_cmp(char *s1, char *s2);
char	**make_input(char **av);
int		count_input(char **av);

/*utils*/
int		get_stack_size(t_stack *stack);
void	ft_putstr(char *str);
int		ft_atoi(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
void	free_stack(t_stack **s);
void	exit_error(t_stack **stack_a, t_stack **stack_b);

/*stack_values_initialization*/
t_stack *fill_stack_values(int ac, char **av);
void	assign_index(t_stack *stack_a, int stack_size);

/*stack_utils*/
t_stack *find_second_last(t_stack *stack);
t_stack *move_ptr_last(t_stack *stack);
t_stack *new_node(int	value);
void	stack_add_bottom(t_stack **stack, t_stack *new);
int		is_sorted(t_stack *stack);

/*tiny_sort*/
void	tiny_sort(t_stack **stack);

/*push*/
void	do_pa(t_stack **stack_a, t_stack **stack_b);
void	do_pb (t_stack **stack_a, t_stack **stack_b);

/*rotate*/
void	do_ra(t_stack **stack_a);
void	do_rb(t_stack **stack_b);
void	do_rr(t_stack **stack_a, t_stack **stack_b);

/*reverse rotate*/
void	do_rra(t_stack **stack_a);
void	do_rrb(t_stack **stack_b);
void	do_rrr(t_stack **stack_a, t_stack **stack_b);

/*swap*/
void	do_sa(t_stack **stack_a);
void	do_sb(t_stack **stack_b);
void	do_ss(t_stack **stack_a, t_stack **stack_b);

/*sort*/
void	sort(t_stack **stack_a, t_stack **stack_b);

/*sort_positions*/
void	get_target_position(t_stack **a, t_stack **b);
int		get_lowest_index_pos(t_stack **stack);

/*cost*/
void	calculate_cost(t_stack **stack_a, t_stack **stack_b);
void	do_optimal_move(t_stack **stack_a, t_stack **stack_b);

/*do_move*/
void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);

#endif
