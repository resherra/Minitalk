# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: recherra <recherra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/28 16:33:38 by recherra          #+#    #+#              #
#    Updated: 2024/05/01 16:15:02 by recherra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS=-Wall -Wextra -Werror
SRC_CLIENT=client.c
SRC_SERVER=server.c
OBJS_CLIENT=$(SRC_CLIENT:.c=.o)
OBJS_SERVER=$(SRC_SERVER:.c=.o)
LIBFT=libft/libft.a
FT_PRINTF=ft_printf/libftprintf.a
NAME=client
SERVER_NAME=server

all: $(NAME) $(SERVER_NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJS_CLIENT) client.h
	cc  $(OBJS_CLIENT) -o $(NAME) $(CFLAGS) $(LIBFT) $(FT_PRINTF)

$(SERVER_NAME): $(LIBFT) $(FT_PRINTF) $(OBJS_SERVER) server.h
	cc $(OBJS_SERVER) -o $(SERVER_NAME) $(CFLAGS) $(LIBFT) $(FT_PRINTF)

$(LIBFT):
	make -C libft/

$(FT_PRINTF):
	make -C ft_printf/

clean:
	rm -rf $(OBJS_CLIENT) $(OBJS_SERVER)
	make -C libft/ clean
	make -C ft_printf/ clean


fclean: clean
	rm $(NAME) $(SERVER_NAME)
	make -C libft/ fclean
	make -C ft_printf/ fclean

		
re: fclean all