# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 14:09:53 by vgroux            #+#    #+#              #
#    Updated: 2022/10/18 19:05:44 by vgroux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =         gcc
CFLAGS =     -Wall -Wextra -Werror
RM =         rm -f

LIBFT =	libft/libft.a

SRCS =		ft_printf.c
OBJS =		${SRCS:.c=.o}

NAME =     libftprintf.a

${NAME}: ${OBJS}
	cd libft && make


	ar rcs ${NAME} ${OBJS}

all: ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} 

clean:
	cd libft && make clean
	${RM} ${OBJS}

fclean: clean
	${RM} ${LIBFT}
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
