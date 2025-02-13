/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:32:15 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/13 17:40:24 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"

char	*byte;

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

void	sigusr1_handler(int signum, siginfo_t *info, void *context)
{
	*byte = '0';
	byte++;
	ft_printf("caught sigusr1\n");
}

void	sigusr2_handler(int signum, siginfo_t *info, void *context)
{
	*byte = '1';
	byte++;
	ft_printf("caught sigusr2\n");
}

void	convert_and_print(char *buffer)
{
	int	i;
	int	j;
	int	letter;

	i = 0;
	letter = 0;
	while (buffer[i])
	{
		if (buffer[i] == '1')
		{
			j = (i * 2);
			if (!j)
				j = 1;
			letter = letter + (j);
			buffer[i] = '0';
		}
		i++;
	}
	ft_printf("%c", letter);
}

int	main(void)
{
	struct sigaction	usr1;
	struct sigaction	usr2;
	char	*holder;
	char	buffer[9];
	pid_t	pid;

	byte = buffer;
	holder = buffer;
	pid = getpid();
	ft_printf("%d", pid);
	usr1.sa_sigaction = sigusr1_handler;
	usr1.sa_flags = SA_SIGINFO;
	sigemptyset(&usr1.sa_mask);
	sigaction(SIGUSR1, &usr1, NULL);
	usr2.sa_sigaction = sigusr2_handler;
	usr2.sa_flags = SA_SIGINFO;
	sigemptyset(&usr2.sa_mask);
	sigaction(SIGUSR2, &usr2, NULL);
	while (1)
	{
		if (&buffer[7] == byte)
		{
			ft_printf("true\n");
			byte = holder;
			convert_and_print(byte);
		}
	}
	return (0);
} 
