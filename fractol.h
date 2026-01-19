#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>

# define WIDTH 800
# define HEIGHT 800

# define ESC 65307   

typedef int (*t_fractal_fn)(double x, double y, struct s_fractol *f);

typedef struct s_img
{
    void    *img;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
}   t_img;

typedef struct s_fractol
{
    void            *mlx;
    void            *win;

    t_img           img;

    double          zoom;
    double          shift_x;
    double          shift_y;

    int             max_iter;

    double          julia_re;
    double          julia_im;

    t_fractal_fn    fractal;
}   t_fractol;

void    init_fractol(t_fractol *f);

void    render(t_fractol *f);

int     handle_key(int keycode, t_fractol *f);
int     handle_close(t_fractol *f);
int	handling_mouse(int button, int x, int y, t_fractol *f);
int     mandelbrot(double x, double y, t_fractol *f);
int     julia(double x, double y, t_fractol *f);

void    error_exit(char *msg);

#endif
