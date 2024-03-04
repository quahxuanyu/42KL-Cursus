/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:11:09 by xquah             #+#    #+#             */
/*   Updated: 2024/02/23 16:33:08 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*p_dest;
	unsigned char	*p_src;

	p_dest = (unsigned char *) dst;
	p_src = (unsigned char *) src;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		p_dest += len;
		p_src += len;
		while (len--)
			*--p_dest = *--p_src;
	}
	else
		while (len--)
			*p_dest++ = *p_src++;
	return (dst);
}
/*
#include <memory.h>
#include <string.h>
#include <stdio.h>

int main( void )
{
	char str1[7] = "abcdef";
	char str2[7] = "abcdef";

	printf("\nFT_memmove( str1 + 3, str1 + 2, 3 ): \n");
    printf( "The string: %s\n", str1 );
    ft_memmove( str1 + 3, str1 + 2, 3 );
    printf( "New string: %s\n", str1 );

	printf("\nFT_memcpy( str1 + 3, str1 + 2, 3 ): \n");
	printf( "The string: %s\n", str2 );
    ft_memcpy( str2 + 3, str2 + 2, 3 );
    printf( "New string: %s\n\n", str2 );

	printf("\nORGINAL memmove( str1 + 3, str1 + 2, 3 ): \n");
    printf( "The string: %s\n", str1 );
    memmove( str1 + 3, str1 + 2, 3 );
    printf( "New string: %s\n", str1 );

	printf("\nORIGINAL memcpy( str1 + 3, str1 + 2, 3 ): \n");
	printf( "The string: %s\n", str2 );
    memcpy( str2 + 3, str2 + 2, 3 );
    printf( "New string: %s\n\n", str2 );
}*/