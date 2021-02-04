/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 15:50:14 by sdarron           #+#    #+#             */
/*   Updated: 2020/08/16 21:16:47 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int g_d = 0;
int g_j = 0;
int g_w = 0;

static int	addzrstr(t_flags *f, char *ns, int min, int i)
{
	if (f->zr == 1 && min == 1 && f->w >= 0 && f->tp != 's' && f->tp != 'S')
	{
		ns[f->w + 1] = '0';
		while (f->w >= 0 && i++ >= 0)
			ns[f->w--] = (f->zr == 1 ? '0' : ' ');
		ns[0] = '-';
	}
	else if (((f->zr == 1 && f->plus == 1 && f->w >= 0)\
		|| (f->zr == 1 && f->space == 1 && f->w >= 0))\
		&& f->tp != 's' && f->tp != 'S')
	{
		ns[f->w + 1] = '0';
		while (f->w >= 0 && i++ >= 0)
			ns[f->w--] = (f->zr == 1 ? '0' : ' ');
		ns[0] = f->plus == 1 ? '+' : ' ';
	}
	else
		while (f->w >= 0 && i++ >= 0)
			ns[f->w--] = (f->zr == 1 ? '0' : ' ');
	ft_putstr_fd(ns, g_d);
	free(ns);
	return (i);
}

int			printnbr(char *s, int fd)
{
	int z;

	z = 0;
	while (s[z])
		ft_putchar_fd(s[z++], fd);
	free(s);
	return (z);
}

char		*fnull(char *str, t_flags *f)
{
	if (!str && f->tchn < 6 && f->tchn > 0)
		str = "";
	else if (!str)
		str = "(null)";
	return (str);
}

int			putsn(char *str, t_flags *f, int min, int fd)
{
	char	*ns;
	int		t;

	g_j = 0;
	g_d = fd;
	f->tp == 'S' ? f->mod = "l" : 0;
	str = fnull(str, f);
	(f->tp == 's' && f->tchn_t == 1 && f->tchn == 0) ? str = "" : 0;
	t = ft_strlen(str);
	if (f->tchn == 0 && f->w == 0 && f->tchn_t == 1)
		return (0);
	(f->tchn < 0 && -f->tchn >= t) ? f->tchn = t : 0;
	(f->min == 1 && f->w >= 0) ? f->w = -f->w : 0;
	g_w = f->w < 0 ? f->w : 0;
	((!f->w || f->w < f->tchn) && f->tchn <= t) ? f->w = f->tchn : 0;
	((!f->w && f->tchn > 0) ||\
		(f->w < t && (f->tchn > t || !f->tchn_t))) ? f->w = t : 0;
	ns = ft_memalloc((f->w--) + 1);
	(!f->tchn_t || f->tchn >= t) ? f->tchn = t : 0;
	while (str[g_j] && g_j < f->tchn)
		ns[f->w--] = str[(t - (t + 1 - f->tchn)) - g_j++];
	g_j = addzrstr(f, ns, min, g_j);
	while ((g_w + g_j++) < 0)
		ft_putchar_fd(' ', fd);
	return (g_j - 1);
}
