/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_baseld.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 15:48:00 by sdarron           #+#    #+#             */
/*   Updated: 2020/08/16 16:45:53 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static size_t	flen(long double value, int base)
{
	size_t len;

	len = 1;
	while (value >= (unsigned)base)
	{
		value = value / base;
		len++;
	}
	return (len);
}

char			*itoabaseld(long double value, int base)
{
	char					*str;
	size_t					len;
	unsigned long long		nb;

	if (base < 2 || base > 16)
		return (NULL);
	nb = (unsigned long long)value;
	if (value < 0 && base != 10)
		nb = -value;
	len = flen(nb, base);
	str = ft_strnew(len + 1);
	while ((unsigned long long)nb >= (unsigned)base)
	{
		if (((unsigned long long)nb % base) < 10)
			str[(len--) - 1] = ((unsigned long long)nb % base) + 48;
		else
			str[(len--) - 1] = 'A' + (((unsigned long long)nb % base) - 10);
		nb = (unsigned long long)nb / base;
	}
	if (nb >= 10)
		nb = nb - 10 - 48 + 'A';
	str[len - 1] = nb + 48;
	return (str);
}
