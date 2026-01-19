/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsevigen <bsevigen@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 19:57:44 by bsevigen          #+#    #+#             */
/*   Updated: 2026/01/19 19:57:44 by bsevigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	selecting_fractal(char *name, t_fractol *f)
{
	if (!name)
		error_exit("Usage: ./fractol mandelbrot | julia [re im]");
	if (ft_strncmp(name, "mandelbrot", 11) == 0)
		f->fractal = mandelbrot;
	else if (ft_strncmp(name, "julia", 5) == 0)
		f->fractal = julia;
	else
		error_exit("Invalid fractal type");
}

int	main(int argc, char **argv)
{
	t_fractol	f;

	if (argc < 2)
		error_exit("Usage: ./fractol mandelbrot | julia [re im]");
	ft_bzero(&f, sizeof(t_fractol));
	selecting_fractal(argv[1], &f);
	if (f.fractal == julia)
	{
		if (argc != 4)
			error_exit("Usage: ./fractol julia [re im]");
		if (!is_valid_double(argv[2]) || !is_valid_double(argv[3]))
			error_exit("Julia parameters must be valid numbers");
		f.julia_re = ft_atod(argv[2]);
		f.julia_im = ft_atod(argv[3]);
	}
	init_fractol(&f);
	render(&f);
	mlx_hook(f.win, 2, 1L << 0, handling_keyboard, &f);
	mlx_hook(f.win, 17, 0, handling_close_button, &f);
	mlx_mouse_hook(f.win, handling_mouse, &f);
	mlx_loop(f.mlx);
	return (0);
}
