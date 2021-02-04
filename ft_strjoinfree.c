/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 20:50:48 by sdarron           #+#    #+#             */
/*   Updated: 2020/08/16 16:57:42 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*strjoinfree(char const *s1, char const *s2, int n)
{
	char *str;

	str = ft_strjoin(s1, s2);
	if (n == 1)
		free((void*)s1);
	if (n == 2)
		free((void*)s2);
	if (n == 3)
	{
		free((void*)s1);
		free((void*)s2);
	}
	return (str);
}

t_flags	*obnulfl(t_flags *fl)
{
	fl->w = 0;
	fl->tchn = 0;
	fl->zr = 0;
	fl->min = 0;
	fl->space = 0;
	fl->plus = 0;
	fl->tchn_t = 0;
	fl->percent = 0;
	fl->resh = 0;
	fl->mod = 0;
	fl->non_v = 0;
	return (fl);
}
