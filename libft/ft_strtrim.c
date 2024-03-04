/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:49:29 by xquah             #+#    #+#             */
/*   Updated: 2024/03/04 17:15:43 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
static int	is_set(char c, char const *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	int		i;

	i = 0;
	start = 0;
	end = ft_strlen(s1);
	while (s1[i] && is_set(s1[i], set))
	{
		i++;
		start++;
	}
	i = ft_strlen(s1) - 1;
	while (start < end && is_set(s1[i], set))
	{
		i--;
		end--;
	}
	return (ft_substr(s1, start, end - start));
}
/*
printf("start: %zu\nend: %zu\n", start, end);
#include "libft.h"

static void	*gen_hash(int hash[128], char const *set)
{
	int		i;

	i = -1;
	while (++i < 128)
		hash[i] = 0;
	i = -1;
	while (set[++i])
		if (!hash[(int) set[i]])
			hash[(int) set[i]] = 1;
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		new_len;
	int		i;
	int		j;
	int		hash[128];
	char	*new_str;

	new_len = ft_strlen(s1);
	gen_hash(hash, set);
	j = 0;
	i = -1;
	while (s1[++i])
		if (hash[(int) s1[i]])
			new_len--;
	new_str = malloc(new_len + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (s1[++i])
		if (!hash[(int) s1[i]])
			new_str[j++] = s1[i];
	new_str[j] = '\0';
	return (new_str);
}*/