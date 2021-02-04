/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 00:49:22 by sdarron           #+#    #+#             */
/*   Updated: 2020/08/17 03:17:08 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	putcharn(char c, t_flags *f, int i, int fd)
{
	int w;
	int z;

	i = 1;
	(f->min == 1 && f->w >= 0) ? f->w = -f->w : 0;
	w = f->w;
	z = f->zr;
	while (i < f->w)
	{
		z == 1 ? ft_putchar_fd('0', fd) : ft_putchar_fd(' ', fd);
		i++;
	}
	ft_putchar_fd(c, fd);
	while (w + i < 0)
	{
		ft_putchar_fd(' ', fd);
		i++;
	}
	return (i);
}
