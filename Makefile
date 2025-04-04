# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yofouzi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/04 13:25:47 by yofouzi           #+#    #+#              #
#    Updated: 2025/04/04 13:25:51 by yofouzi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = cc
CFLAGS  = -Wall -Wextra -Werror
SRC     = client.c server.c utils.c
BONUS_SRC = client_bonus.c server_bonus.c
TARGETS = client server
BTARGETS = client_bonus server_bonus
BDIR    = bonus

all: $(TARGETS)

client: client.o utils.o
	$(CC) $(CFLAGS) utils.o $< -o $@

server: server.o utils.o
	$(CC) $(CFLAGS) utils.o $< -o $@

bonus: $(BTARGETS)

client_bonus: client_bonus.o
	$(CC) $(CFLAGS) utils.o $< -o $@

server_bonus: server_bonus.o
	$(CC) $(CFLAGS) utils.o $< -o $@

clean:
	rm -f client.o server.o utils.o client_bonus.o server_bonus.o

fclean: clean
	rm -f $(TARGETS) $(BTARGETS) clean

re: fclean all

.PHONY: all clean fclean re bonus
