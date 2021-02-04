/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrlln.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 14:50:01 by sdarron           #+#    #+#             */
/*   Updated: 2020/08/16 17:04:32 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int g_i = 0;
int g_ii = 0;

static char	*putzeros(char *s, int z)
{
	while (z >= 0)
		s[z--] = '0';
	return (s);
}

static char	*putzrsg(char *s, int z, t_flags *f)
{
	while (z > 0)
		s[z--] = '0';
	g_ii == 1 ? s[z] = '-' : 0;
	f->plus == 1 && g_ii != 1 ? s[z] = '+' : 0;
	f->space == 1 && g_ii != 1 ? s[z] = ' ' : 0;
	f->zr == 1 && f->w > g_i ? s[0] = '0' : 0;
	return (s);
}

static int	dflags(t_flags *f)
{
	int z;

	g_ii == 1 || f->plus == 1 ? f->space = 0 : 0;
	f->tchn < 0 ? f->tchn_t = 0 : 0;
	f->tchn_t == 1 || f->min == 1 ? f->zr = 0 : 0;
	z = f->tchn < g_i ? g_i : f->tchn;
	(f->min == 1 && f->w < 0) ? f->w = -(f->w) : 0;
	g_ii == 1 || f->plus == 1 || f->space == 1 ? z++ : 0;
	return (z);
}

char		*putnbrn(char *s, t_flags *f)
{
	int		z;
	char	*tmp;
	char	c;

	z = f->tchn;
	c = f->zr == 1 ? '0' : ' ';
	z < g_i ? z = g_i : 0;
	g_ii == 1 || f->plus == 1 || f->space == 1 ? f->w-- : 0;
	tmp = (char *)malloc(sizeof(char) * (f->w - z + 1));
	tmp[(f->w-- - z)] = '\0';
	while ((f->w - z) >= 0)
		tmp[f->w-- - z] = c;
	s = f->min != 1 ? strjoinfree(tmp, s, 3) : strjoinfree(s, tmp, 3);
	(f->zr == 1 && g_ii == 1) ? s[0] = '-' : 0;
	(f->plus == 1 && g_ii != 1 && f->tchn_t != 1 &&\
		(!f->w || f->zr == 1)) ? s[0] = '+' : 0;
	(f->plus != 1 && f->min != 1 && f->space == 1) ? s[0] = ' ' : 0;
	return (s);
}

int			putnbrlln(long long int n, t_flags *f, int fd, int z)
{
	char	*s;

	f->tp == 'D' ? f->mod = 0 : 0;
	f->mod && !ft_strcmp(f->mod, "h") ? n = (short)n : 0;
	f->mod && !ft_strcmp(f->mod, "hh") ? n = (char)n : 0;
	f->mod && !ft_strcmp(f->mod, "ll") ? n = (long)n : 0;
	(!f->mod && f->tp != 'D') ||\
		(f->mod && !ft_strcmp(f->mod, "L")) ? n = (int)n : 0;
	g_ii = n < 0 ? 1 : 0;
	g_ii == 1 ? n = -n : 0;
	g_i = calcnbr(n);
	z = dflags(f);
	if (f->tchn_t == 1 && !f->tchn && n == 0 && !f->w && f->space != 1)
		return (0);
	s = ft_memalloc(1 + z--);
	while (n >= 10)
	{
		s[z--] = (n % 10 + '0');
		n = n / 10;
	}
	s[z--] = (f->tchn_t == 1 && !f->tchn && n == 0 && f->w) ? ' ' : n + '0';
	(g_ii != 1 && f->plus != 1 && f->space != 1) ? s = putzeros(s, z) : 0;
	(g_ii == 1 || f->plus == 1 || f->space == 1) ? s = putzrsg(s, z, f) : 0;
	(f->w > f->tchn && f->w > g_i) ? s = putnbrn(s, f) : 0;
	return (printnbr(s, fd));
}
