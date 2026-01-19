#include "fractol.h"

static void	init_image(t_fractol *f)
{
	f->img.img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img.img)
		error_exit("Failed to create image");

	f->img.addr = mlx_get_data_addr(
			f->img.img,
			&f->img.bpp,
			&f->img.line_len,
			&f->img.endian
			);
	if (!f->img.addr)
		error_exit("Failed to get image address");
}

void	init_fractol(t_fractol *f)
{
	ft_bzero(f, sizeof(t_fractol));
	f->mlx = mlx_init();
	if (!f->mlx)
		error_exit("mlx_init failed");

	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fract-ol");
	if (!f->win)
		error_exit("mlx_new_window failed");

	init_image(f);

	f->zoom = 1.0;
	f->shift_x = 0.0;
	f->shift_y = 0.0;
	f->max_iter = 100;

	f->fractal = NULL;
}

