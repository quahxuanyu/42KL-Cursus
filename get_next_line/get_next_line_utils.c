/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:09:52 by xquah             #+#    #+#             */
/*   Updated: 2024/03/18 04:24:22 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

size_t ft_strlen(const char *s)
{
	size_t i;

	i = -1;
	while (s[++i])
		continue;
	return (i);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	int s1_len;
	int s2_len;
	int i;

	
	if (!s1)
		s1_len = 0;
	else
		s1_len = ft_strlen(s1);
	i = -1;
	s2_len = BUFFER_SIZE;
	str = (char *)malloc(s1_len + s2_len + 1);
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	i--;
	while (s2[++i - s1_len])
		str[i] = s1[i - s1_len];
	str[s1_len + s2_len] = '\0';
	return (str);
}

char *ft_strchr(const char *s, int c)
{
	char *temp;
	int len;
	int i;

	len = BUFFER_SIZE;
	temp = (char *)s;
	i = -1;
	while (++i <= len)
		if (temp[i] == (char)c)
			return (&temp[i]);
	return (NULL);
}

char *ft_strdup(const char *s1)
{
	int i;
	char *str;

	str = (char *)malloc(ft_strlen((char *)s1) + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}
// ISSUE IS HERE
int line_len(char *buffer)
{
	int len;

	len = 0;

	while (*buffer != '\n' && *buffer)
	{
		len++;
		buffer++;
	}
	return (len);
}
/*
int	total_lines(char *buffer)
{
	int	len;

	len = 1;
	if (*buffer == '\0')
		return (0);
	while (*buffer)
		if (*buffer++ == '\n')
			len++;
	return (len);
}

int	copy_line(int line_count, char *buffer, char *dst)
{
	while (line_count > 0 && *buffer)
		if (*buffer++ == '\n')
			line_count--;
	if (!*buffer)
		return (1);
	while (*buffer != '\n' && *buffer)
		*dst++ = *buffer++;
	*dst = *buffer;
	return (0);
}
*/
