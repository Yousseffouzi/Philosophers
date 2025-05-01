NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = philo.c ./src/args_verification.c ./src/ft_atoi.c ./src/extras.c ./src/philosophers_algo.c \
		./src/actions.c ./src/death_monitor.c ./src/init.c ./src/routine.c ./src/timestamp.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ) $(BONUS_OBJ)

fclean: clean
	@rm -rf $(NAME) $(BONUS_NAME)

re: fclean all