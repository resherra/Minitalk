# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: recherra <recherra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/09 11:21:31 by recherra          #+#    #+#              #
#    Updated: 2024/05/01 17:03:30 by recherra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c ft_strlen.c ft_putendl_fd.c

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJ = ${SRC:.c=.o}
NAME = libft.a

all: ${NAME}

${NAME}: ${OBJ}
	ar -rcs ${NAME} ${OBJ}

clean:
	rm -rf ${OBJ} ${OBONUS}

fclean: clean
	rm -rf ${NAME}

re: fclean all
