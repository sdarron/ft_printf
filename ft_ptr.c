/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 00:49:14 by sdarron           #+#    #+#             */
/*   Updated: 2020/08/16 17:11:10 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_flags	*nultchn(t_flags *f)
{
	f->tchn = 0;
	f->tchn_t = 0;
	return (f);
}

char	*strtemp(int x, int i, char c)
{
	char *tmp2;

	tmp2 = ft_memalloc(x-- - i + 1);
	while (x - i >= 0)
		tmp2[x-- - i] = c;
	return (tmp2);
}

int		ptrtype(long long int d, t_flags *fl, int fd)
{
	int		i;
	char	*tmp;

	if (d == 0 && fl->tchn_t == 1 && fl->tchn == 0 && fl->w == 0)
		return (putsn("0x", obnulfl(fl), 0, fd));
	tmp = ft_strlowcase(ft_itoa_base(d, 16));
	(fl->min == 1) ? fl->zr = 0 : 0;
	if (fl->tchn > (i = ft_strlen(tmp)))
		tmp = strjoinfree(strtemp(fl->tchn, i, '0'), tmp, 3);
	if (fl->zr == 1 && !fl->tchn_t && fl->w > i + 2)
		tmp = strjoinfree(strtemp(fl->w, i + 2, '0'), tmp, 3);
	tmp = strjoinfree("0x", tmp, 2);
	i = ft_strlen(tmp);
	if (fl->w > i && fl->min != 1)
		tmp = strjoinfree(strtemp(fl->w, i, ' '), tmp, 3);
	i = putsn(tmp, nultchn(fl), 0, fd);
	free(tmp);
	return (i);
}
