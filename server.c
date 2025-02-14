/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:32:15 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/14 13:59:49 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "ft_printf/ft_printf.h"

char	byte;

int	_puts(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

void	sigusr1_handler()
{
	byte = byte << 1;
}

void	sigusr2_handler()
{
	byte = byte << 1;
	byte = byte | 1;
}
void	my_sig_handler(int signum, siginfo_t *info, void *context)
{
	static int	counter;
	static pid_t	pid;

	if (signum == SIGUSR1)
		sigusr1_handler();
	else if (signum == SIGUSR2)
		sigusr2_handler();
	counter++;
	if (counter == 8)
	{
		ft_printf("%c", byte);
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
	byte = 0;
	ft_printf("%d\n", pid);
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
