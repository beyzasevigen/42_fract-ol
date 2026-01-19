/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsevigen <bsevigen@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 20:09:54 by bsevigen          #+#    #+#             */
/*   Updated: 2026/01/19 20:09:54 by bsevigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;

	temp = (unsigned char *) s;
	while (n > 0)
	{
		*temp = 0;
		temp++;
		n--;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	if (i < n)
	{
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

static double	parse_digits(const char **s)
{
	double	n;

	n = 0.0;
	while (**s >= '0' && **s <= '9')
	{
		n = n * 10.0 + (**s - '0');
		(*s)++;
	}
	return (n);
}

double	ft_atod(const char *s)
{
	double	result;
	double	frac;
	double	div;
	int		sign;

	result = 0.0;
	frac = 0.0;
	div = 1.0;
	sign = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	result = parse_digits(&s);
	if (*s == '.')
	{
		s++;
		frac = parse_digits(&s);
		while (frac >= div)
			div *= 10.0;
	}
	return (sign * (result + frac / div));
}
