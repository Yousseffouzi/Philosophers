# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yofouzi <yofouzi@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/24 13:24:51 by yofouzi           #+#    #+#              #
#    Updated: 2025/08/24 13:34:41 by yofouzi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := philo
CC      := cc
CFLAGS  := -Wall -Wextra -Werror

SRC     := data_init.c dinner.c get_set.c main.c monitor.c parse_input.c synchronization.c time.c utils.c write_clean.c
OBJ     := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -pthread

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SECONDARY: $(OBJ)
