/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:13:06 by avivien           #+#    #+#             */
/*   Updated: 2020/11/15 18:13:09 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_raz(int n)
{
	int c;

	c = 1;
	while (n /= 10)
		c++;
	return (c);
}

int		ft_print_di_2(t_print *new, int cont, int len)
{
	int i;

	if ((cont < 0 && new->flag == '0' && new->toch < 0) || (cont == -2147483648
	&& new->flag == '0' && new->toch < 0))
		write(1, "-", 1);
	i = 0;
	((cont == 0 && new->toch == 0)) ? len-- : 0;
	if (new->shir > new->toch)
		while (new->shir - i > new->toch && (new->shir > len))
		{
			len++;
			i++;
			if (new->flag == '0' && new->toch < 0)
				write(1, "0", 1);
			else
				write(1, " ", 1);
		}
	if ((cont < 0 && (new->flag != '0' || new->toch >= 0)) ||
	(cont == -2147483648 && (new->flag != '0' || new->toch >= 0)))
		write(1, "-", 1);
	while ((len < new->shir || len < new->toch) && len++)
		write(1, "0", 1);
	if (new->toch != 0 || cont != 0)
		ft_putnbr_fd(cont, 1);
	return ((cont < 0) ? len + 1 : len);
}

int		ft_print_di(t_print *new, va_list ap)
{
	int cont;
	int len;

	cont = va_arg(ap, int);
	len = ft_raz(cont);
	if (cont < 0)
		new->shir--;
	if (new->flag == '-')
	{
		if (cont < 0 || cont == -2147483648)
			write(1, "-", 1);
		while (len++ < new->toch && new->toch != 0)
			write(1, "0", 1);
		if (new->toch != 0 || cont != 0)
			ft_putnbr_fd(cont, 1);
		else
			len--;
		while (new->shir > len++ - 1)
			write(1, " ", 1);
		return ((cont < 0) ? len - 1 : len - 2);
	}
	return (ft_print_di_2(new, cont, len));
}

int		ft_print_u_2(t_print *new, unsigned int cont, int len)
{
	int i;

	if (cont < 0 && new->flag == '0' && new->toch == 0)
		write(1, "-", 1);
	i = 0;
	if (new->toch == 0 && cont == 0)
		len--;
	if (new->shir > new->toch)
		while (new->shir - i > new->toch && (new->shir > len))
		{
			len++;
			i++;
			if (new->flag == '0' && new->toch < 0)
				write(1, "0", 1);
			else
				write(1, " ", 1);
		}
	while ((len < new->shir || len < new->toch) && len++)
		write(1, "0", 1);
	if (new->toch != 0 || cont != 0)
		ft_putnbr_fdu(cont, 1);
	return (len);
}

int		ft_print_u(t_print *new, va_list ap)
{
	unsigned int	cont;
	int				len;

	cont = va_arg(ap, unsigned int);
	len = ft_putnbr_razu(cont);
	if (new->flag == '-')
	{
		while (len++ < new->toch && new->toch != 0)
			write(1, "0", 1);
		if (new->toch != 0 || cont != 0)
			ft_putnbr_fdu(cont, 1);
		else
			len--;
		while (new->shir > len++ - 1)
			write(1, " ", 1);
		return (len - 2);
	}
	return (ft_print_u_2(new, cont, len));
}
