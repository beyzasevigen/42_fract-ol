#include "fractol.h"

int	julia(double x, double y, t_fractol *f)
{
	double	z_re;
	double	z_im;
	double	tmp;
	int		i;

	z_re = x;
	z_im = y;
	i = 0;
	while (i < f->max_iter)
	{
		tmp = z_re * z_re - z_im * z_im + f->julia_re;
		z_im = 2.0 * z_re * z_im + f->julia_im;
		z_re = tmp;
		if (z_re * z_re + z_im * z_im > 4.0)
			break;
		i++;
	}
	return (i);
}
