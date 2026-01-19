#include "fractol.h"

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
