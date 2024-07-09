/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:22:57 by xquah             #+#    #+#             */
/*   Updated: 2024/07/09 11:39:21 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_btoa(int sig, siginfo_t *info, void *context)
{
	static int				bits;
	static unsigned char	chr;

	(void)context;
	chr |= (sig == SIGUSR2);
	bits++;
	if (bits == 8)
	{
		if (chr == 0)
		{
			kill(info->si_pid, SIGUSR2);
			ft_printf("\n");
		}
		else
			ft_printf("%c", chr);
		bits = 0;
		chr = 0;
	}
	else
		chr <<= 1;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = ft_btoa;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("%d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
