/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 13:48:39 by sdarron           #+#    #+#             */
/*   Updated: 2020/08/17 05:17:00 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#define TP "cCsSpdDioOuUxXfF%"

int		g_fd = 0;
int		g_k = 0;

int			parstp(va_list ar, t_flags *f, int i, char *s)
{
	f->tp = s[i];
	s[i] == 'c' || s[i] == 'C' ?\
		f->l += putcharn((char)va_arg(ar, int), f, 0, g_fd) : 0;
	s[i] == 's' || s[i] == 'S' ?\
		f->l += putsn(va_arg(ar, char*), f, 0, g_fd) : 0;
	s[i] == 'p' ? f->l += ptrtype(va_arg(ar, long long int), f, g_fd) : 0;
	s[i] == 'd' || s[i] == 'i' || s[i] == 'D' ? f->l += decl(ar, f, g_fd) : 0;
	s[i] == 'o' || s[i] == 'O' ?\
		f->l += octal(va_arg(ar, long long int), f, 0, g_fd) : 0;
	s[i] == 'u' || s[i] == 'U' ?\
		f->l += unsig(va_arg(ar, long long int), f, 0, g_fd) : 0;
	s[i] == 'X' || s[i] == 'x' ?\
		f->l += hex(va_arg(ar, long long int), f, g_fd, 0) : 0;
	s[i] == 'f' || s[i] == 'F' ? f->l += ffloat(ar, f, g_fd) : 0;
	s[i] == '%' ? f->l += percent('%', f, g_fd) : 0;
	return (f->l);
}

static int	flagh(t_flags *f, int i, char *s, char c)
{
	if (s[i + 1] == c)
	{
		if (!f->mod || (!ft_strcmp(f->mod, "h") && !ft_strcmp(f->mod, "l")))
		{
			f->mod = c == 'h' ? "hh" : "ll";
			i++;
		}
	}
	else
		f->mod = c == 'h' ? "h" : "l";
	return (i);
}

static int	nonv(t_flags *f, int i, char *s)
{
	if (!ft_strrchr("*-+ #0123456789.hlL", s[i]))
	{
		f->non_v = s[i];
		return (0);
	}
	return (1);
}

int			parsflag(va_list ar, t_flags *f, int i, char *s)
{
	s[i] == '-' ? f->min = 1 : 0;
	s[i] == ' ' ? f->space = 1 : 0;
	s[i] == '+' ? f->plus = 1 : 0;
	s[i] == '#' ? f->resh = 1 : 0;
	s[i] == '0' && !ft_isdigit(s[i - 1]) ? f->zr = 1 : 0;
	if (s[i] == '*' && f->tchn_t != 1)
	{
		f->w = va_arg(ar, int);
		f->w < 0 ? f->min = 1 : 0;
	}
	s[i] > '0' && s[i] <= '9' ? i = width(s, f, i) : 0;
	s[i] == '.' ? i = precision(s, f, i) : 0;
	if (s[i - 1] == '.' && s[i] == '*' && f->tchn_t == 1)
	{
		f->tchn = va_arg(ar, int);
		(f->tchn < 0) ? f = nultchn(f) : 0;
	}
	s[i] == '#' ? f->resh = 1 : 0;
	(s[i] == 'h') ? i = flagh(f, i, s, 'h') : 0;
	(s[i] == 'l') ? i = flagh(f, i, s, 'l') : 0;
	s[i] == 'L' ? f->mod = "L" : 0;
	return (i);
}

int			pars(va_list ar, t_flags *f, char *s, int fd)
{
	g_k = 0;
	g_fd = fd;
	while (s[g_k])
	{
		f = obnulfl(f);
		s[g_k] != '%' && s[g_k] ? g_k = printtxt(s, f, g_k, fd) : 0;
		if (s[g_k] == '%')
		{
			g_k++;
			while (!ft_strrchr(TP, s[g_k]))
			{
				g_k = parsflag(ar, f, g_k, s);
				if (nonv(f, g_k, s) == 0)
					break ;
				(!ft_strrchr(TP, s[g_k])) ? g_k++ : 0;
			}
			s[g_k] && ft_strrchr(TP, s[g_k]) ?\
				f->l = parstp(ar, f, g_k++, s) : 0;
			(f->non_v != 0) ? f->l += putcharn(f->non_v, f, g_k++, fd) : 0;
		}
	}
	return (f->l);
}
