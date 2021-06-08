/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:58:34 by avivien           #+#    #+#             */
/*   Updated: 2020/11/02 20:32:56 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, int fd)
{
	int sum;

	if (n == -2147483648)
	{
		write(fd, "2147483648", 10);
		return ;
	}
	if (n < 0)
		n *= -1;
	if (n <= 9)
	{
		sum = n + '0';
		write(fd, &sum, 1);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

void	ft_putnbr_16fd(unsigned int n, int fd, char fl)
{
	unsigned int	sum;
	unsigned int	i;
	unsigned int	nn;
	int				xx;

	i = 1;
	nn = n;
	xx = (fl == 'x') ? 22 : -10;
	while (nn / 16)
	{
		nn /= 16;
		i *= 16;
	}
	while (i)
	{
		sum = (n / i >= 10) ? n / i + 'A' + xx : n / i + 48;
		write(fd, &sum, 1);
		n %= i;
		i /= 16;
	}
}

void	ft_putnbr_fdl(unsigned long n, int fd)
{
	unsigned long sum;
	unsigned long i;
	unsigned long nn;

	i = 1;
	nn = n;
	while (nn / 16)
	{
		nn /= 16;
		i *= 16;
	}
	while (i)
	{
		sum = (n / i >= 10) ? n / i + 'A' + 22 : n / i + 48;
		write(fd, &sum, 1);
		n %= i;
		i /= 16;
	}
}

void	ft_putnbr_fdu(unsigned int n, int fd)
{
	unsigned int sum;

	if (n <= 9)
	{
		sum = n + '0';
		write(fd, &sum, 1);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}

int		ft_putnbr_16raz(unsigned int n)
{
	int ca;

	ca = 0;
	while (n / 16)
	{
		n /= 16;
		ca++;
	}
	return (ca + 1);
}
