/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:49:29 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/14 13:59:51 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "ft_printf/ft_printf.h"

void	send_sig(char *buffer, int pid)
{
	int	i;

	i = 7;
	ft_printf("%d\n", pid);
	while (i >= 0)
	{
		if (buffer[i] == '1')
		{
			ft_printf("buffer : %c\n", buffer[i]);
			kill(pid, SIGUSR2);
		}
		else if (buffer[i] == '0')
		{
			ft_printf("buffer : %c\n", buffer[i]);
			kill(pid, SIGUSR1);
		}
		usleep(10);
		i--;
	}
}

void	conver_to_bin(int c, int pid)
{
	int	i;
	char	buffer[9];

	i = 0;
	buffer[8] = '\0';
	while (c > 0)
	{
		buffer[i] = c % 2 + '0';
		i++;
		c = c / 2;
	}
	while (i < 8)
		buffer[i++] = '0';
	send_sig(buffer, pid);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac < 3)
		return (0);
	pid = ft_atoi(av[1]);
	while (av[2][i])
	{
		conver_to_bin(av[2][i], pid);
		i++;
	}
	return (0);
}
