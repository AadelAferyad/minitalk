/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:32:15 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/14 15:15:05 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sigusr1_handler(char *byte)
{
	*byte = *byte << 1;
}

void	sigusr2_handler(char *byte)
{
	*byte = *byte << 1;
	*byte = *byte | 1;
}

void	my_sig_handler(int signum, siginfo_t *info, void *context)
{
	static int	counter;
	static pid_t	pid;
	static char	byte;

	if (!pid)
		pid = info->si_pid;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		_putchar('\n');
		byte = 0;
		counter = 0;
	}
	if (signum == SIGUSR1)
		sigusr1_handler(&byte);
	else if (signum == SIGUSR2)
		sigusr2_handler(&byte);
	counter++;
	if (counter == 8)
	{
		_putchar(byte);
		byte = 0;
		counter = 0;
	}
}

int	main(void)
{
	struct sigaction	usr1;
	struct sigaction	usr2;
	pid_t	pid;

	pid = getpid();
	print_nbr(pid);
	_putchar('\n');
	usr1.sa_sigaction = my_sig_handler;
	usr1.sa_flags = SA_SIGINFO;
	sigemptyset(&usr1.sa_mask);
	sigaction(SIGUSR1, &usr1, NULL);
	usr2.sa_sigaction = my_sig_handler;
	usr2.sa_flags = SA_SIGINFO;
	sigemptyset(&usr2.sa_mask);
	sigaction(SIGUSR2, &usr2, NULL);
	while (1)
	{
		;
	}
	return (0);
} 
