/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avivien <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:16:03 by avivien           #+#    #+#             */
/*   Updated: 2020/11/15 18:16:14 by avivien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct		s_print
{
	unsigned char	flag;
	int				shir;
	int				toch;
	char			targ;
	struct s_print	*next;
}					t_print;

void				addnew(t_print	*new);
int					ft_raz(int n);
int					ft_abs(int n);
int					ft_print_c(t_print *new, va_list ap);
int					ft_print_s_2(t_print *new, char *cont);
int					ft_print_s(t_print *new, va_list ap);
int					ft_print_p_2(t_print *new, unsigned long cont, int len);
int					ft_print_p(t_print *new, va_list ap);
int					ft_print_di_2(t_print *new, int cont, int len);
int					ft_print_di(t_print *new, va_list ap);
int					ft_print_u_2(t_print *new, unsigned int cont, int len);
int					ft_print_u(t_print *new, va_list ap);
int					ft_print_xx_2(t_print *new, unsigned int cont, int len);
int					ft_print_xx(t_print *new, va_list ap);
int					ft_print_proc(t_print *new);
int					ft_printcontent(t_print *new, va_list ap);
int					parser(const char *str, va_list ap, int i);
int					ft_sdvig(const char *str, int i);
int					ft_printf(const char *str, ...);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr_16fd(unsigned int n, int fd, char fl);
void				ft_putnbr_fdl(unsigned long n, int fd);
int					ft_putnbr_16raz(unsigned int n);
void				ft_putnbr_fdu(unsigned int n, int fd);
int					ft_putnbr_razu(unsigned int n);
int					ft_putnbr_razl(unsigned long n);
void				ft_lstadd_back(t_print **lst, t_print *new);
int					ft_strlen(const char *str);
void				addnew1(t_print *new, int temp);
int					parser_2(const char *s, t_print *new, va_list ap, int i);

#endif
