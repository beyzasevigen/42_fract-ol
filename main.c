#include "fractol.h"

static void selecting_fractal(char *name, t_fractol *f)
{
    if (!name)
        error_exit("Usage: ./fractol mandelbrot | julia [re im]");
    if (!strcmp(name, "mandelbrot"))
        f->fractal = mandelbrot;
    else if (!strcmp(name, "julia"))
        f->fractal = julia;
    else
        error_exit("Invalid fractal type");
}

int main(int argc, char **argv)
{
    t_fractol f;

    if (argc < 2)
        error_exit("Usage: ./fractol mandelbrot | julia [re im]");

    selecting_fractal(argv[1], &f);

    if (f.fractal == julia && argc == 4)
    {
        f.julia_re = atof(argv[2]);
        f.julia_im = atof(argv[3]);
    }

    init_fractol(&f);
    render(&f);

    mlx_hook(f.win, 2, 1L << 0, handling_keyboard, &f);
    mlx_hook(f.win, 17, 0, handling_close_button, &f);
    mlx_mouse_hook(f.win, handling_mouse, &f);

    mlx_loop(f.mlx);
    return (0);
}
