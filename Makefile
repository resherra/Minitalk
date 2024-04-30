# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: recherra <recherra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/28 16:33:38 by recherra          #+#    #+#              #
#    Updated: 2024/04/30 19:38:56 by recherra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS=-Wall -Wextra -Werror -fsanitize=address
SRC_CLIENT=client.c
SRC_SERVER=server.c
OBJS_CLIENT=$(SRC_CLIENT:.c=.o)
OBJS_SERVER=$(SRC_SERVER:.c=.o)
LIBFT=libft/libft.a
NAME=client
SERVER_NAME=server

all: $(NAME) $(SERVER_NAME)

$(NAME): $(LIBFT) $(OBJS_CLIENT) client.h
	cc  $(OBJS_CLIENT) -o $(NAME) $(CFLAGS) $(LIBFT)

$(SERVER_NAME): $(LIBFT) $(OBJS_SERVER) server.h
	cc $(OBJS_SERVER) -o $(SERVER_NAME) $(CFLAGS) $(LIBFT)

$(LIBFT):
	make -C libft/

clean:
	rm -rf $(OBJS_CLIENT) $(OBJS_SERVER)
	make -C libft/ clean

fclean: clean
	rm $(NAME) $(SERVER_NAME)
	make -C libft/ fclean
		
re: fclean all