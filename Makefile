CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = server client
SRCS =  server.c client.c utils.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
        ar rsc $(NAME) $(OBJS)

clean :
        rm -f $(OBJS)

fclean : clean
        rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re