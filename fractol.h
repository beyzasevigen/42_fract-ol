#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>

# define WIDTH 800
# define HEIGHT 800

# define ESC 65307

/* 🔑 BURASI ÇOK ÖNEMLİ */
struct s_fractol;

/* artık struct biliniyor */
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

/* prototypes */
void    init_fractol(t_fractol *f);
void    render(t_fractol *f);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
double	ft_atod(const char *s);
int     handling_keyboard(int keycode, t_fractol *f);
int     handling_close_button(t_fractol *f);
int     handling_mouse(int button, int x, int y, t_fractol *f);
int     get_color(int iter, int max_iter);
int     mandelbrot(double x, double y, t_fractol *f);
int     julia(double x, double y, t_fractol *f);
void	clear_image(t_img *img);
void    error_exit(char *msg);
void	cleanup(t_fractol *f);

#endif
