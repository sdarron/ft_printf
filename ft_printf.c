/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 12:49:04 by sdarron           #+#    #+#             */
/*   Updated: 2020/08/16 17:01:31 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_printf(char *fmt, ...)
{
	int					i;
	char				*s;
	t_flags				*f;
	va_list				ar;

	va_start(ar, fmt);
	f = (t_flags*)malloc(sizeof(t_flags));
	s = fmt;
	f->l = 0;
	f->l = pars(ar, f, s, 1);
	va_end(ar);
	i = f->l;
	free(f);
	return (i);
}

int			fdprintf(int fd, char *fmt, ...)
{
	int					i;
	char				*s;
	t_flags				*f;
	va_list				ar;

	va_start(ar, fmt);
	f = (t_flags*)malloc(sizeof(t_flags));
	s = fmt;
	f->l = 0;
	f->l = pars(ar, f, s, fd);
	va_end(ar);
	i = f->l;
	free(f);
	return (i);
}
