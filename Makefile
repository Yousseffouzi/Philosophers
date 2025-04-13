NAME = fractol

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = fractal.c mandelbrot.c utile.c julia.c mlx_init.c Zoom.c utile_2.c ft_atof.c

OBJS = $(SRCS:.c=.o)

MLX_DIR = ./minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	@make clean -C $(MLX_DIR)

re: fclean all

$(OBJS): fractal.h

.PHONY: all clean fclean re

.SECONDARY : $(OBJS)
