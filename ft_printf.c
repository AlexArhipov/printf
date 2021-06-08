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
#include <stdio.h>

int		ft_printcontent(t_print *new, va_list ap)
{
	if (new->targ == 'c')
		return (ft_print_c(new, ap));
	if (new->targ == 's')
		return (ft_print_s(new, ap));
	if (new->targ == 'p')
		return (ft_print_p(new, ap));
	if (new->targ == 'u')
		return (ft_print_u(new, ap));
	if (new->targ == '%')
		return (ft_print_proc(new));
	if (new->targ == 'd' || new->targ == 'i')
		return (ft_print_di(new, ap));
	if (new->targ == 'x' || new->targ == 'X')
		return (ft_print_xx(new, ap));
	return (-1);
}

int		parser_2(const char *s, t_print *new, va_list ap, int i)
{
	if (s[i] == '.')
	{
		i++;
		new->toch = 0;
		while (s[i] >= '0' && s[i] <= '9')
			new->toch = new->toch * 10 + (s[i++] - '0');
		if (s[i] == '*')
		{
			new->toch = va_arg(ap, int);
			i++;
		}
	}
	if (s[i] == 'c' || s[i] == 's' || s[i] == 'p' || s[i] == 'd' ||
		s[i] == 'i' || s[i] == 'u' || s[i] == 'x' || s[i] == 'X' || s[i] == '%')
		new->targ = s[i++];
	return (i);
}

void	addnew(t_print *new)
{
	new->flag = '!';
	new->shir = 0;
	new->toch = -1;
}

int		parser(const char *s, va_list ap, int i)
{
	t_print	*new;
	int		temp;
	int		ret;

	if (!(new = malloc(sizeof(t_print))))
		return (-1);
	addnew(new);
	while (s[i] == '-' || s[i] == '0')
		if (s[i++] && new->flag != '-')
			new->flag = (unsigned char)s[i - 1];
	while (s[i] >= '0' && s[i] <= '9')
		new->shir = new->shir * 10 + (s[i++] - '0');
	if (s[i] == '*')
	{
		temp = va_arg(ap, int);
		new->shir = temp;
		if (temp < 0)
			addnew1(new, temp);
		i++;
	}
	i = parser_2(s, new, ap, i);
	ret = ft_printcontent(new, ap);
	free(new);
	return (ret);
}

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	int		ret;
	int		i;
	int		m;

	i = 0;
	m = 0;
	ret = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ret += parser(str, ap, ++i);
			i += ft_sdvig(str, i);
		}
		else
		{
			write(1, &str[i++], 1);
			m++;
		}
	}
	va_end(ap);
	return (ret + m);
}
