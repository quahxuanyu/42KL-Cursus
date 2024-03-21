/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:09:46 by xquah             #+#    #+#             */
/*   Updated: 2024/03/21 19:32:04 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*left_over;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		left_over = NULL;
		buffer = NULL;
		return (NULL);
	}
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	fill_buffer(fd, buffer, &left_over);
	free(buffer);
	buffer = NULL;
	line = set_line(&left_over);
	if (!line)
	{
		free(left_over);
		free(line);
		return (NULL);
	}
	return (line);
}

char	*copy_line(char *left_over)
{
	char	*line;
	int		i;

	i = 0;
	line = malloc((line_len(left_over) + 1) * sizeof(char));
	if (!line)
	{
		free(line);
		return (NULL);
	}
	while ((left_over)[i] != '\n' && (left_over)[i])
	{
		line[i] = (left_over)[i];
		i++;
	}
	line[i] = (left_over)[i];
	if ((left_over)[i] != '\0')
		line[i + 1] = '\0';
	if (line_len(left_over) == 0 && !ft_strchr(left_over, '\n'))
		line = NULL;
	return (line);
}

char	*set_line(char **left_over)
{
	char	*line;
	char	*temp;
	int		i;

	if (!*left_over)
		return (NULL);
	i = 0;
	temp = *left_over;
	line = copy_line(*left_over);
	*left_over = ft_strdup(*left_over + line_len(*left_over));
	if (!**left_over)
	{
		free(*left_over);
		*left_over = NULL;
	}
	free(temp);
	return (line);
}

void	fill_buffer(int fd, char *buffer, char **left_over)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(left_over);
			return ;
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = *left_over;
		*left_over = ft_strjoin(temp, buffer, bytes_read);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
}
