CC      = cc
CFLAGS  = -Wall -Wextra -Werror
NAME1	= client
NAME2	= server
SRC_1   = client.c utils.c
SRC_2   = server.c utils.c
OBJ_1	= $(SRC_1:.c=.o)
OBJ_2	= $(SRC_2:.c=.o)


all: $(NAME1) $(NAME2)

client: $(OBJ_1)
	$(CC) $(CFLAGS) $(OBJ_1)  -o $(NAME1)

server: $(OBJ_2)
	$(CC) $(CFLAGS) $(OBJ_2)  -o $(NAME2)

clean:
	rm -f $(OBJ_1) $(OBJ_2)

fclean: clean
	rm -f $(NAME1) $(NAME2)

re: fclean all

.PHONY: all clean fclean re
