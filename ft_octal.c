/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 00:48:15 by sdarron           #+#    #+#             */
/*   Updated: 2020/08/16 18:26:51 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char *g_s = 0;

static char	*srtfinall(char *s, t_flags *f, int i, int d)
{
	char	*tmp;

	tmp = f->zr == 1 ? strtemp(f->w, i, '0') : strtemp(f->w, i, ' ');
	s = f->min == 1 ? strjoinfree(s, tmp, 3) : strjoinfree(tmp, s, 3);
	if (f->tp == 'x' || f->tp == 'X')
		f->resh == 1 && d != 0 && f->zr == 1 ? s[1] = 'X' : 0;
	if (f->tp == 'o' || f->tp == 'O')
		f->resh == 1 && d != 0 && f->zr == 1 ? s[0] = '0' : 0;
	return (s);
}

static char	*strprecis(char *s, t_flags *f, int i, int d)
{
	char	*tmp;

	(f->tchn_t == 1 || f->min == 1) ? f->zr = 0 : 0;
	(f->tchn_t == 1 && f->tchn > i) ? tmp = strtemp(f->tchn, i, '0') : 0;
	(f->tchn_t == 1 && f->tchn > i) ? s = strjoinfree(tmp, s, 3) : 0;
	f->resh == 1 && d != 0 && !f->zr ? s = strjoinfree("0X", s, 2) : 0;
	(f->min == 1 && f->w < 0) ? f->w = -f->w : 0;
	return (s);
}

int			octal(long long int d, t_flags *f, int i, int fd)
{
	f->mod && !ft_strcmp(f->mod, "h") && f->tp != 'O' ?\
		d = (unsigned short)d : 0;
	f->mod && !ft_strcmp(f->mod, "hh") && f->tp != 'O' ?\
		d = (unsigned char)d : 0;
	!f->mod && f->tp != 'O' ? d = (unsigned)d : 0;
	f->mod && !ft_strcmp(f->mod, "z") ? d = (size_t)d : 0;
	f->mod && !ft_strcmp(f->mod, "j") ? d = (uintmax_t)d : 0;
	f->mod && !ft_strcmp(f->mod, "l") ? d = (unsigned long)d : 0;
	f->mod && !ft_strcmp(f->mod, "ll") ? d = (unsigned long long)d : 0;
	f->mod && !ft_strcmp(f->mod, "L") ? d = (unsigned int)d : 0;
	g_s = uitoabase(d, 8);
	(f->tchn_t == 1 && !f->tchn && d == 0 && f->w) ? g_s[0] = ' ' : 0;
	i = ft_strlen(g_s);
	(f->tchn_t == 1 || f->min == 1) ? f->zr = 0 : 0;
	(f->tchn_t == 1 && f->tchn > i) ? f->resh = 0 : 0;
	(f->tchn_t == 1 && f->tchn > i) ?\
		g_s = strjoinfree(strtemp(f->tchn, i, '0'), g_s, 3) : 0;
	f->resh == 1 && !f->zr && f->tchn_t < i && d ?\
		g_s = strjoinfree("0", g_s, 2) : 0;
	(f->min == 1 && f->w < 0) ? f->w = -f->w : 0;
	if (f->tchn_t == 1 && !f->tchn && d == 0 && !f->w && !f->resh)
		return (0);
	i = ft_strlen(g_s);
	f->w > i ? g_s = srtfinall(g_s, f, i, d) : 0;
	return (printnbr(g_s, fd));
}

int			unsig(long long int d, t_flags *f, int i, int fd)
{
	char	*s;

	f->tp == 'U' ? f->mod = 0 : 0;
	f->mod && !ft_strcmp(f->mod, "h") ? d = (unsigned short)d : 0;
	f->mod && !ft_strcmp(f->mod, "hh") ? d = (unsigned char)d : 0;
	f->mod && !ft_strcmp(f->mod, "l") ? d = (unsigned long)d : 0;
	f->mod && !ft_strcmp(f->mod, "L") ? d = (unsigned int)d : 0;
	(f->mod && !ft_strcmp(f->mod, "ll")) || f->tp == 'U' ?\
		d = (unsigned long long)d : 0;
	!f->mod && f->tp != 'U' ? d = (unsigned)d : 0;
	s = uitoabase(d, 10);
	(f->tchn_t == 1 && !f->tchn && d == 0 && f->w) ? s[0] = ' ' : 0;
	if (f->tchn_t == 1 && !f->tchn && d == 0 && !f->w)
		return (0);
	i = ft_strlen(s);
	(f->tchn_t == 1 || f->min == 1) ? f->zr = 0 : 0;
	(f->tchn_t == 1 && f->tchn > i) ?\
		s = strjoinfree(strtemp(f->tchn, i, '0'), s, 3) : 0;
	(f->min == 1 && f->w < 0) ? f->w = -f->w : 0;
	i = ft_strlen(s);
	f->w > i ? s = srtfinall(s, f, i, d) : 0;
	return (printnbr(s, fd));
}

int			hex(long long int d, t_flags *f, int fd, int i)
{
	d = (unsigned long long)d;
	f->mod && !ft_strcmp(f->mod, "h") ? d = (unsigned short)d : 0;
	f->mod && !ft_strcmp(f->mod, "hh") ? d = (unsigned char)d : 0;
	!f->mod || (f->mod && !ft_strcmp(f->mod, "L")) ? d = (unsigned int)d : 0;
	f->mod && !ft_strcmp(f->mod, "l") ? d = (unsigned long)d : 0;
	f->mod && !ft_strcmp(f->mod, "ll") ? d = (unsigned long long)d : 0;
	if (f->tchn_t == 1 && !f->tchn && d == 0 && !f->w)
		return (0);
	if (d < 0 && !f->mod)
		g_s = uitoabase(d, 16);
	else if ((d < 0 && f->mod && \
		(!ft_strcmp(f->mod, "ll") || !ft_strcmp(f->mod, "l"))))
		g_s = uitoabase(d, 16);
	else
		g_s = ft_itoa_base(d, 16);
	(f->tchn_t == 1 && !f->tchn && d == 0 && f->w) ? g_s[0] = ' ' : 0;
	g_s = strprecis(g_s, f, ft_strlen(g_s), d);
	i = ft_strlen(g_s);
	(f->w > i) ? g_s = srtfinall(g_s, f, i, d) : 0;
	return (printnbr(f->tp == 'X' ? g_s : ft_strlowcase(g_s), fd));
}
