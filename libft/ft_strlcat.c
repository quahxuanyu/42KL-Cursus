/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:12:18 by xquah             #+#    #+#             */
/*   Updated: 2024/03/06 21:49:24 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, unsigned int size)
{
	size_t	i;
	size_t	j;
	size_t	initial_dest_length;

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
