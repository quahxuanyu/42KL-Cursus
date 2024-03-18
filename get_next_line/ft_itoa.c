/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:45:16 by xquah             #+#    #+#             */
/*   Updated: 2024/03/18 15:08:16 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_intlen(int nbr)
{
	int	len;

	len = 1;
	if (nbr < 0)
	{
		nbr /= 10;
		len++;
		nbr = -nbr;
		if (nbr > 0)
			len++;
	}
	while (nbr >= 10)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		intlen;

	intlen = ft_intlen(n);
	str = (char *)malloc(sizeof(char) * intlen + 1);
	if (!str)
		return (NULL);
	str[intlen] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		str[--intlen] = '0' - (n % 10);
		n /= 10;
		n = -n;
	}
	while (n > 0)
	{
		str[--intlen] = '0' + (n % 10);
		n /= 10;
	}
	return (str);
}
