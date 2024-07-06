/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:22:55 by xquah             #+#    #+#             */
/*   Updated: 2024/07/05 21:04:18 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// void	print_bits(char c)
// {
// 	int	bits;

// 	bits = 8;
// 	while (bits--)
// 	{
// 		ft_printf("%i", c >> bits & 1);
// 	}
// 	ft_printf("\n");
// }

void	send_str(int pid, char *str)
{
	int	i;
	int	bits;

	i = -1;
	while (str[++i])
	{
		bits = 8;
		while (bits--)
		{
			if (str[i] >> bits & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(50);
		}
	}
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*str;
	
	
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		send_str(pid, str);
	}
}