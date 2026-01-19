#include "fractol.h"

void error_exit(char *msg)
{
    write(2, msg, ft_strlen(msg));
    write(2, "\n", 1);
    exit(EXIT_FAILURE);
}
