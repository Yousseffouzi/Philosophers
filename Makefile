CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = fractol
SRC = fractol.c ft_atof.c hook.c init_fractal.c julia.c mandelbrot.c utils.c zoom.c
OBJ = $(SRC:.c=.o)

MLX_PATH = ./minilibx-linux
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lX11 -lXext -lm

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C $(MLX_PATH)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

#$(MLX_LIB): 
#	@make -C $(MLX_PATH)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	@make -C $(MLX_PATH) clean

re: fclean all

.PHONY: all clean fclean re

.SECONDARY : $(OBJ)