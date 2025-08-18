NAME = philo

SRC =   initialisation.c  main.c  start_threads.c  start_threads_utils.c  utils1.c  utils2.c  utils3.c cleanup.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: re clean flcean NAME all
