/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:19:49 by xquah             #+#    #+#             */
/*   Updated: 2024/02/26 14:47:55 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*p_dest;
	char	*p_src;

	if (!dst && !src)
		return (dst);
	p_dest = (char *) dst;
	p_src = (char *) src;
	i = -1;
	while (++i < n)
		p_dest[i] = p_src[i];
	return (dst);
}
/*
#include <string.h>
#include <stdio.h>

void printArray(int arr[], int n) 
{ 
   for (int i=0; i<n; i++) 
      printf("%d ", arr[i]); 
	printf("\n");
} 

int	main(void)
{
	int n = 9;
	char dest[] = "hello world";
	char src[] = "def";

	int dest2[6] = {1, 2, 3, 4, 5, 6};
	int	src2[3] = {23, 35, 45};
	//puts(ft_memcpy(dest2, src2, 3));
	printArray(ft_memcpy(dest2, src2, n), 6);
	printArray(memcpy(dest2, src2, n), 6);
    //puts("str1 after memcpy ");
	//puts(dest);
	//printArray(dest2, 6);
 
    return 0;
}*/