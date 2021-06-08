/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:06:24 by avivien           #+#    #+#             */
/*   Updated: 2020/11/15 18:06:32 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_c(t_print *new, va_list ap)
{
	char		cont;
	int			len;

	len = 0;
	cont = va_arg(ap, int);
	if (new->flag == '-')
	{
		write(1, &cont, 1);
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
	write(1, &cont, 1);
	return (len + 1);
}

int		ft_print_s_2(t_print *new, char *cont)
{
	int len;
	int i;

	i = 0;
	len = (int)ft_strlen(cont);
	if (new->toch < len && new->toch >= 0)
		len = new->toch;
	else
		new->toch = len;
	if (len < new->shir)
		while (new->shir - len > 0)
		{
			len++;
			if (new->flag == '0')
				write(1, "0", 1);
			else
				write(1, " ", 1);
		}
	while ((new->toch - i) > 0 && cont[i])
		i++;
	write(1, cont, (int)i);
	return (len);
}

int		ft_print_s(t_print *new, va_list ap)
{
	char	*cont;
	int		len;

	cont = va_arg(ap, char*);
	if (cont == 0)
		cont = "(null)";
	len = ft_strlen(cont);
	if (new->flag == '-')
	{
		if (new->toch >= 0)
		{
			len = 0;
			while ((cont[len] && (new->toch - len > 0)))
				len++;
		}
		write(1, cont, (int)len);
		while (new->shir > len++)
			write(1, " ", 1);
		return (len - 1);
	}
	return (ft_print_s_2(new, cont));
}

int		ft_print_p_2(t_print *new, unsigned long cont, int len)
{
	int i;

	i = 0;
	if (cont == 0 && new->toch == 0)
		len--;
	if (new->toch <= -1 && new->flag == '0')
		write(1, "0x", 2);
	while (new->shir - 2 - i > new->toch && (new->shir - 2 > len))
	{
		len++;
		i++;
		if (new->flag == '0' && new->toch < 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
	if (new->toch > -1 || new->flag != '0')
		write(1, "0x", 2);
	if (cont == 0 && new->toch < 0)
		write(1, "0", 1);
	while ((len < new->shir - 2 || len < new->toch) && len++)
		write(1, "0", 1);
	if (new->toch > 0 || cont != 0)
		ft_putnbr_fdl(cont, 1);
	return (len + 2);
}

int		ft_print_p(t_print *new, va_list ap)
{
	unsigned long	cont;
	int				len;

	cont = va_arg(ap, unsigned long);
	len = ft_putnbr_razl(cont);
	if (new->flag == '-')
	{
		write(1, "0x", 2);
		while (len++ < new->toch && new->toch > 0)
			write(1, "0", 1);
		if (new->toch > 0 || cont != 0)
			ft_putnbr_fdl(cont, 1);
		if (new->toch == 0 && cont == 0)
			len--;
		if (cont == 0 && new->toch < 0)
			write(1, "0", 1);
		while (new->shir - 2 > len++ - 1)
			write(1, " ", 1);
		return (len);
	}
	return (ft_print_p_2(new, cont, len));
}
