CC = CC
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
SRC = ft_split.c push.c push_swap.h rotate.c sort_5.c sort_arr.c utils_push_swap.c check.c linked_list.c \
		push_swap.c r_rotate.c sort_3.c sort_all.c swap.c utils_split.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re