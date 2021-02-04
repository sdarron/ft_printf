/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 00:47:36 by sdarron           #+#    #+#             */
/*   Updated: 2020/08/16 17:22:31 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	printtxt(char *s, t_flags *f, int i, int fd)
{
	while (s[i] != '%' && s[i])
	{
		ft_putchar_fd(s[i++], fd);
		f->l++;
	}
	return (i);
}

int	precision(char *s, t_flags *f, int i)
{
	f->tchn_t = 1;
	f->tchn = ft_isdigit(s[++i]) ? ft_atoi(&s[i]) : 0;
	i = nbpass(s, i);
	return (i);
}

int	nbpass(char *s, int i)
{
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	return (i - 1);
}

int	width(char *s, t_flags *f, int i)
{
	f->w = ft_atoi(&s[i]);
	i = nbpass(s, i);
	return (i);
}
