/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:09:46 by xquah             #+#    #+#             */
/*   Updated: 2024/03/19 17:46:38 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 3
#endif

char *get_next_line(int fd)
{
	char *buffer;
	char *line;
	static char *left_over;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer || BUFFER_SIZE < 1)
	{
		free(buffer);
		return (NULL);
	}
	fill_buffer(fd, buffer, &left_over);
	line = set_line(&left_over);
	free(buffer);
	return (line);
}

char *set_line(char **left_over)
{
	char *line;
	int i;

	ft_putstr("\n\n=====Phase 2=====\nSet Line function\n");
	if (!*left_over)
		return (NULL);
	i = 0;
	line = malloc((line_len(*left_over) + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_putstr("\nLine lenth: ");
	ft_putstr(ft_itoa(line_len(*left_over)));
	ft_putstr("\n");
	while ((*left_over)[i] != '\n' && (*left_over)[i])
	{
		line[i] = (*left_over)[i];
		i++;
	}
	line[i] = (*left_over)[i];
	if (line_len(*left_over) == 0 && !ft_strchr(*left_over, '\n'))
		line = NULL;
	*left_over = ft_strdup(&(*left_over)[i + 1]);
	return (line);
}

void fill_buffer(int fd, char *buffer, char **left_over)
{
	int bytes_read;
	char *temp;

	ft_putstr("\n=====Phase 1=====\nFill Buffer\n");
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		ft_putstr("Bytes Read: ");
		ft_putstr(ft_itoa(bytes_read));
		if (bytes_read == 0)
			break;
		buffer[BUFFER_SIZE] = '\0';
		ft_putstr("\nNew Buffer: ");
		ft_putstr(buffer);
		ft_putstr("\n");
		temp = *left_over;
		*left_over = ft_strjoin(*left_over, buffer, bytes_read);
		free(temp);
		if (ft_strchr(buffer, '\n') != NULL)
			break;
		ft_putstr("---------------\n\n");
	}
}
