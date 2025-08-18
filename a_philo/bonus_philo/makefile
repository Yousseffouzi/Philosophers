NAME = philo_bonus

CC = cc 
CFLAGS = -Wall -Wextra -Werror

SRC = eat.c  initialisation.c  main_bonus.c  start_process.c  start_process_utils.c  utils1_bonus.c  utils2_bonus.c  utils3_bonus.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : re clean fclean all