#include "fractol.h"

int main(int ac, char **av)
{
    if((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)) ||
        (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
        //code;
    else
    {
        ft_putstr_fd("TODO");
        exit(1);
    }
}