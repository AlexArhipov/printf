/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:24:00 by avivien           #+#    #+#             */
/*   Updated: 2020/11/15 18:24:03 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_proc(t_print *new)
{
	int len;

	len = 0;
	if (new->flag == '-')
	{
		write(1, "%", 1);
		while (new->shir - 1 > len++)
			write(1, " ", 1);
		return (len);
	}
	while (new->shir-- > 1)
	{
		len++;
		if (new->flag == '0')
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
	write(1, "%", 1);
	return (len + 1);
}

int		ft_sdvig(const char *str, int i)
{
	int m;

	m = i;
	while (str[i] == '-' || str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '*')
		i++;
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] == '*')
			i++;
	}
	if (str[i] == 'c' || str[i] == 's' || str[i] == 'p' || str[i] == 'd' ||
		str[i] == 'i' || str[i] == 'u' || str[i] == 'x' || str[i] == 'X' ||
		str[i] == '%')
		i++;
	return (i - m);
}

int		ft_strlen(const char *str)
{
	int ch;

	ch = 0;
	while (*str++)
		ch++;
	return (ch);
}

int		ft_putnbr_razl(unsigned long n)
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

int		ft_putnbr_razu(unsigned int n)
{
	int ca;

	ca = 0;
	while (n / 10)
	{
		n /= 10;
		ca++;
	}
	return (ca + 1);
}
