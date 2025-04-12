

#include <stdio.h>

typedef struct s_complex
{
    double real;
    double i;
}              t_complex;

int main()
{
    t_complex   z;
    t_complex   c;
    double   tmp_r;
    int         i;

    z.real = 0;
    z.i = 0;

    c.real = 0.25;
    c.i = 0.4;

    i = 0;
    while(i < 100)
    {
        tmp_r = (z.real * z.real) - (z.i * z.i);
        z.i = 2 * z.i * z.real;
        z.real = tmp_r;
        z.i += c.i;
        z.real += c.real;
        printf("iteration n -> %d real %f imaginary %f\n", i, z.real, z.i);
        i++;
    }
}