# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avivien <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/30 12:13:07 by avivien           #+#    #+#              #
#    Updated: 2020/11/03 14:35:41 by avivien          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	fd16add.c digit.c ft_printf.c ft_putnbr_fdpl.c strchr.c\
		fdadd2.c

OBJS	= ${SRCS:.c=.o}


NAME	= libftprintf.a

HEAD	= ft_printf.h

GCC				= gcc

RM				= rm -f

AR				= ar rc

CFLAGS	= -Wall -Werror -Wextra

.c.o:
		${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}
${NAME}:${OBJS} ${HEAD}
		${AR} ${NAME} ${OBJS}
		${AR} ${NAME} ${HEAD}
all:	${NAME}

clean:
						${RM} ${OBJS} 
fclean:			clean
						${RM} ${NAME}
re:				fclean all
