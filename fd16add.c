/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   16add.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:08:57 by avivien           #+#    #+#             */
/*   Updated: 2020/11/15 18:09:00 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_xx_2(t_print *new, unsigned int cont, int len)
{
	int i;

	i = 0;
	if (cont == 0 && new->toch == 0)
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
	if (new->toch != 0 || ft_abs(cont) != 0)
		ft_putnbr_16fd(cont, 1, new->targ);
	return (len);
}

int		ft_print_xx(t_print *new, va_list ap)
{
	unsigned int	cont;
	int				len;

	cont = va_arg(ap, unsigned int);
	len = ft_putnbr_16raz(cont);
	if (new->flag == '-')
	{
		while (len++ < new->toch && new->toch != 0)
			write(1, "0", 1);
		if (new->toch != 0 || cont != 0)
			ft_putnbr_16fd(cont, 1, new->targ);
		else
			len--;
		while (new->shir > len++ - 1)
			write(1, " ", 1);
		return (len - 2);
	}
	return (ft_print_xx_2(new, cont, len));
}

int		ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	addnew1(t_print *new, int temp)
{
	new->shir = -temp;
	new->flag = '-';
}
