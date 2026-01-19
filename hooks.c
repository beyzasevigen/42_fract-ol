/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsevigen <bsevigen@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 20:07:32 by bsevigen          #+#    #+#             */
/*   Updated: 2026/01/19 20:07:32 by bsevigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handling_keyboard(int keycode, t_fractol *f)
{
	if (keycode == ESC)
	{
		cleanup(f);
		exit(0);
	}
	return (0);
}

int	handling_close_button(t_fractol *f)
{
	cleanup(f);
	exit(0);
}

int	handling_mouse(int button, int x, int y, t_fractol *f)
{
	(void)x;
	(void)y;
	if (button == 4)
		f->zoom *= 1.2;
	else if (button == 5)
		f->zoom *= 0.8;
	render(f);
	return (0);
}
