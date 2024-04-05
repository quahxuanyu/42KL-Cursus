/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:05:26 by xquah             #+#    #+#             */
/*   Updated: 2024/04/04 13:35:08 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

int		ft_print_c(char c);
int		ft_printf(const char *str, ...);
int		ft_print_s(char *str);
int		ft_print_p(uintptr_t ptr);
int		ft_print_d(int num);
int		ft_print_u(unsigned int num);
int		ft_print_x(unsigned int num, char c);
#endif