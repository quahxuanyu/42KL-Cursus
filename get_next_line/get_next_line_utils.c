/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:09:52 by xquah             #+#    #+#             */
/*   Updated: 2024/03/18 18:11:44 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_putstr(char *str)
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

char *ft_strjoin(char const *s1, char const *s2, int bytes_read)
{
	char *str;
	int s1_len;
	int i;
	
	if (!s1)
		s1_len = 0;
	else
		s1_len = ft_strlen(s1);
	ft_putstr("left over length: ");
	ft_putstr(ft_itoa(s1_len));
	ft_putstr("\n");
	i = -1;
	str = malloc((s1_len + bytes_read + 1) * sizeof(char));
	if (!str)
	{
		ft_putstr("Null malloc\n");
		return (NULL);
	}
	if (s1_len != 0)
	{
		ft_putstr("first loop\n");
		while (s1[++i])
		{
			str[i] = s1[i];
		}
		ft_putstr(str);
		ft_putstr("\n");
		i--;
	}
	ft_putstr("after first loop\n");
	while (++i - s1_len < bytes_read)
	{
		write(1, &s2[i - s1_len], 1);
		ft_putstr("\n");
		str[i] = s2[i - s1_len];
	}
	str[s1_len + bytes_read] = '\0';
	ft_putstr("Current leftover: ");
	ft_putstr((char *) str);
	ft_putstr("\n");
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
