/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsevigen <bsevigen@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 20:01:37 by bsevigen          #+#    #+#             */
/*   Updated: 2026/01/19 20:01:37 by bsevigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "minilibx-linux/mlx.h"

# define WIDTH 800
# define HEIGHT 800

# define ESC 65307

struct		s_fractol;

typedef int	(*t_fractal_fn)(double x, double y, struct s_fractol *f);

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_fractol
{
	void			*mlx;
	void			*win;
	double			zoom;
	double			shift_x;
	double			shift_y;
	double			julia_re;
	double			julia_im;
	int				max_iter;
	t_img			img;
	t_fractal_fn	fractal;
}	t_fractol;

void	init_fractol(t_fractol *f);
void	render(t_fractol *f);
void	ft_bzero(void *s, size_t n);
void	clear_image(t_img *img);
void	error_exit(char *msg);
void	cleanup(t_fractol *f);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		is_valid_double(const char *s);
int		handling_keyboard(int keycode, t_fractol *f);
int		handling_close_button(t_fractol *f);
int		handling_mouse(int button, int x, int y, t_fractol *f);
int		get_color(int iter, int max_iter);
int		mandelbrot(double x, double y, t_fractol *f);
int		julia(double x, double y, t_fractol *f);
double	ft_atod(const char *s);
size_t	ft_strlen(const char *s);

#endif
