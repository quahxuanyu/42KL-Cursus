/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xquah <xquah@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:22:57 by xquah             #+#    #+#             */
/*   Updated: 2024/07/06 01:45:20 by xquah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handle_signal(int sig)
{
	static int				bits;
	static unsigned	char	chr;
	
	bits++;
	chr |= (sig == 12);
	if (bits == 8)
	{
		ft_printf("%c", chr);
		bits = 0;
		chr = 0;
	}
	else
		chr <<= 1;
}

int main()
{
	// Set up the signal handler
	struct sigaction	sa;
	sa.sa_handler = handle_signal;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);

	// Handle SIGUSR1 and SIGUSR2 signals
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		perror("Error setting up signal handler for SIGUSR1");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		perror("Error setting up signal handler for SIGUSR2");
		exit(EXIT_FAILURE);
	}

	// Print server's PID so the client can send signals to it
	printf("Server PID: %d\n", getpid());

	// Keep the server running to wait for signals
	while (1)
	{
		pause(); // Wait for signals
	}

	return 0;
}

// int main(void)
// {
// 	int pid;

// 	pid = getpid();
// 	ft_printf("%i", pid);
	
// }