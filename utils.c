/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsevigen <bsevigen@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 20:40:08 by bsevigen          #+#    #+#             */
/*   Updated: 2026/01/19 20:40:28 by bsevigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid_double(const char *s)
{
	int	has_digit;
	int	has_dot;

	has_digit = 0;
	has_dot = 0;
	if (*s == '+' || *s == '-')
		s++;
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
			has_digit = 1;
		else if (*s == '.' && !has_dot)
			has_dot = 1;
		else
			return (0);
		s++;
	}
	return (has_digit);
}
