/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:49:03 by xquah             #+#    #+#             */
/*   Updated: 2024/04/01 17:33:25 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_base(uintptr_t ptr, char *base)
{
	if (ptr == 0)
		return (0);
	else
		return (print_base(ptr / 16, base) + write(1, &base[ptr % 16], 1));
}

int	ft_print_p(uintptr_t ptr)
{
	int		len;

	len = write(1, "0x", 2);
	if (!ptr)
	{
		write(1, "0", 1);
		return (3);
	}
	len += print_base(ptr, "0123456789abcdef");
	return (len);
}
