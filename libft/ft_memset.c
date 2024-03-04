/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:14:29 by xquah             #+#    #+#             */
/*   Updated: 2024/02/23 12:05:44 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = b;
	while (len-- > 0)
		*(p++) = (unsigned char)c;
	return (b);
}
/*
#include <stdio.h>
#include <string.h>

void printArray(int arr[], int n) 
{ 
   for (int i=0; i<n; i++) 
      printf("%d ", arr[i]); 
} 
  
int main() 
{
    int n = 10; 
    int arr[n]; 
  
    // Fill whole array with 0. 
    ft_memset(arr, 0, n*sizeof(arr[0])); 
	printf("%lu\n", sizeof(arr[0]));
    printf("Array after memset()\n"); 
    printArray(arr, n); 

//Test for strings
    char str[50] = "GeeksForGeeks is for programming geeks."; 
    printf("\nBefore memset(): %s\n", str); 
  
    // Fill 8 characters starting from str[13] with '.' 
    memset(str + 13, '.', 8*sizeof(char)); 
  
    printf("After memset():  %s", str);
    return 0;
}*/