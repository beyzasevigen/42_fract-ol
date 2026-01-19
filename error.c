#include "fractol.h"

void error_exit(char *msg)
{
    write(2, msg, ft_strlen(msg));
    write(2, "\n", 1);
    exit(EXIT_FAILURE);
}
void	clear_image(t_img *img)
{
	ft_bzero(img->addr, HEIGHT * img->line_len);
}
void	cleanup(t_fractol *f)
{
	if (f->img.img)
		mlx_destroy_image(f->mlx, f->img.img);
	if (f->win)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
	{
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
}
