/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:00:00 by xquah             #+#    #+#             */
/*   Updated: 2024/04/01 17:32:45 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_specifier(va_list arg, const char c)
{
	if (c == 'c')
		return (ft_print_c((char) va_arg(arg, int)));
	if (c == 's')
		return (ft_print_s(va_arg(arg, char *)));
	if (c == 'p')
		return (ft_print_p((uintptr_t) va_arg(arg, void *)));
	if (c == 'd' || c == 'i')
		return (ft_print_d(va_arg(arg, int)));
	if (c == 'u')
		return (ft_print_u(va_arg(arg, unsigned int)));
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	arg;

	len = 0;
	i = -1;
	va_start(arg, str);
	while (str[++i])
	{
		if (str[i] == '%')
		{
			len += process_specifier(arg, str[++i]);
		}
		else
			len += ft_print_c(str[i]);
	}
	va_end(arg);
	return (len);
}
