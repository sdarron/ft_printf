/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_declima.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 00:47:26 by sdarron           #+#    #+#             */
/*   Updated: 2020/08/16 17:17:53 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	decl(va_list ar, t_flags *f, int fd)
{
	int				i;
	long long int	d;
	char			*s;

	d = va_arg(ar, long long int);
	if ((unsigned long long)d == 9223372036854775808U)
	{
		ft_putstr("-9223372036854775808");
		return (ft_strlen("-9223372036854775808"));
	}
	if (f->w == 0 && f->tchn_t == 1 && f->tchn == 0 && f->space == 1 && d == 0)
	{
		s = ft_memalloc(2);
		s[0] = ' ';
		return (printnbr(s, fd));
	}
	if (f->w == 0 && f->tchn_t == 1 && f->tchn == 0 && f->plus == 1 && d == 0)
	{
		s = ft_memalloc(2);
		s[0] = '+';
		return (printnbr(s, fd));
	}
	i = putnbrlln(d, f, fd, 0);
	return (i);
}
