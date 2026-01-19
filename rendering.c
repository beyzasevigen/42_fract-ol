#include "fractol.h"

static void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

static void	pixel_to_complex(int x, int y, t_fractol *f,
							double *re, double *im)
{
	*re = (x - WIDTH / 2.0) / (0.5 * f->zoom * WIDTH) + f->shift_x;
	*im = (y - HEIGHT / 2.0) / (0.5 * f->zoom * HEIGHT) + f->shift_y;
}

void	render(t_fractol *f)
{
	int		x;
	int		y;
	double	re;
	double	im;
	int		iter;

	y = 0;
	clear_image(&f->img);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel_to_complex(x, y, f, &re, &im);
			iter = f->fractal(re, im, f);
			put_pixel(&f->img, x, y, get_color(iter, f->max_iter));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
}
