/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:12:18 by xquah             #+#    #+#             */
/*   Updated: 2024/02/23 15:55:12 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	initial_dest_length;

	initial_dest_length = ft_strlen(dest);
	if (size <= initial_dest_length)
	{
		return (size + ft_strlen(src));
	}
	j = -1;
	i = initial_dest_length;
	while (src[++j] != '\0' && j < (size - initial_dest_length - 1))
	{
		dest[i++] = src[j];
	}
	dest[i] = '\0';
	return (initial_dest_length + ft_strlen(src));
}
