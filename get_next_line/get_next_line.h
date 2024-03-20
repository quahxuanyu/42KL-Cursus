/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:09:49 by xquah             #+#    #+#             */
/*   Updated: 2024/03/20 10:30:22 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
#endif
char	*get_next_line(int fd);
int		line_len(char *buffer);
char	*set_line(char **left_over);
char 	*ft_strjoin(char const *s1, char const *s2, int bytes_read);
char 	*ft_strchr(const char *s, int c);
size_t	ft_strlen_c(const char *s, char c);
char	*ft_strdup(const char *s1);
void	fill_buffer(int fd, char *buffer, char **left_over);
void	ft_putstr(char *str);
//char	*ft_itoa(int n);
#endif