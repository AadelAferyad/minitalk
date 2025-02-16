/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaferyad <aaferyad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:43:42 by aaferyad          #+#    #+#             */
/*   Updated: 2025/02/14 15:10:35 by aaferyad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	_putchar(char c)
{
	return (write(1, &c, 1));
}

int	_puts(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		_putchar(s[i++]);
	return (i);
}

void	print_nbr(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
		print_nbr(nb / 10);
	_putchar(nb % 10 + 48);
}

static int	ft_check_escape(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (0);
		i++;
	}
	return (1);
}

int	_atoi(const char *nptr)
{
	int	n;
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	n = 0;
	while (!ft_check_escape(" \n\t\v\f\r", nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = (nptr[i] - '0') + n * 10;
		i++;
	}
	return (n * sign);
}
