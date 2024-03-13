/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:09:46 by xquah             #+#    #+#             */
/*   Updated: 2024/03/13 15:28:58 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*left_over;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer || BUFFER_SIZE < 1)
	{
		free(buffer);
		return (NULL);
	}
	fill_buffer(fd, buffer, left_over);
	write(1, left_over, 24);
	set_line(line, left_over);
	free(buffer);
	return (line);
}

void	set_line(char *line, char *left_over)
{
	char	*temp;

	temp = left_over;
	line = malloc((line_len(left_over) + 1) * sizeof(char));
	write(1, "\nfinish malloc\n", 10);
	while (*left_over != '\n' && !*left_over)
		*line++ = *left_over++;
	*line = *left_over;
	left_over = ft_strdup(left_over + 1);
	free(temp);
}

void	fill_buffer(int fd, char *buffer, char *left_over)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
		//write(1, buffer, 42);
		temp = left_over;
		left_over = ft_strjoin(left_over, buffer);
		free(temp);
	}
}
