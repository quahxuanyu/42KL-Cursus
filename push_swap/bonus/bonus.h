/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:05:09 by xquah             #+#    #+#             */
/*   Updated: 2024/06/27 14:03:34 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H
# include "../libft/libft.h"

typedef struct s_stack
{
	int				data;
	int				pos;
	int				s_index;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

// swap.c
void	swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

// push.c
void	push(t_stack **dest, t_stack **src);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

// rotate.c
void	rotate(t_stack **stack);
void	ra(t_stack **stk_a);
void	rb(t_stack **stk_b);
void	rr(t_stack **stk_a, t_stack **stk_b);

// reverse_rotate.c
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **stk_a);
void	rrb(t_stack **stk_b);
void	rrr(t_stack **stk_a, t_stack **stk_b);

// utils
long	ft_long_atoi(const char *str);
void	exit_error(void);
int		is_sorted(t_stack **stk);
int		stack_size(t_stack **stk);
void	free_stack(t_stack **stk);

//validate_input.c
int		validate_input(char *argv[], int **arr);

//init_stack.c
t_stack	*init_stack(int *nums, int len);
char	**arg_to_str(char **av);

#endif