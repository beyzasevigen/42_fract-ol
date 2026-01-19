#include "fractol.h"

static void	zoom_at_point(t_fractol *f, int x, int y, double factor)
{
	double	before_re;
	double	before_im;
	double	after_re;
	double	after_im;

	/* zoom öncesi complex */
	before_re = (x - WIDTH / 2.0) / (0.5 * f->zoom * WIDTH) + f->shift_x;
	before_im = (y - HEIGHT / 2.0) / (0.5 * f->zoom * HEIGHT) + f->shift_y;

	f->zoom *= factor;

	/* zoom sonrası complex */
	after_re = (x - WIDTH / 2.0) / (0.5 * f->zoom * WIDTH) + f->shift_x;
	after_im = (y - HEIGHT / 2.0) / (0.5 * f->zoom * HEIGHT) + f->shift_y;

	/* farkı shift'e ekle */
	f->shift_x += before_re - after_re;
	f->shift_y += before_im - after_im;
}

int	handling_keyboard(int keycode, t_fractol *f)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(f->mlx, f->img.img);
		mlx_destroy_window(f->mlx, f->win);
		exit(0);
	}
	return (0);
}

int	handling_close_button(t_fractol *f)
{
	mlx_destroy_image(f->mlx, f->img.img);
	mlx_destroy_window(f->mlx, f->win);
	exit(0);
	return (0);
}

int	handling_mouse(int button, int x, int y, t_fractol *f)
{
	if (button == 4)
		zoom_at_point(f, x, y, 1.2);
	else if (button == 5)
		zoom_at_point(f, x, y, 0.8);

	render(f);
	return (0);
}

