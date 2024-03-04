/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:56:54 by xquah             #+#    #+#             */
/*   Updated: 2024/02/23 16:32:53 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	printf("ft: %c\n", ft_toupper(argv[1][0]));
	printf("original: %c\n", toupper(argv[1][0]));
}*/