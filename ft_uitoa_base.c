/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 19:51:03 by sdarron           #+#    #+#             */
/*   Updated: 2020/08/16 17:01:03 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static size_t	ulen(unsigned long long value, int base)
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

char			*uitoabase(unsigned long long int value, int base)
{
	char					*str;
	size_t					len;
	unsigned long long int	nb;

	if (base < 2 || base > 16)
		return (NULL);
	nb = value;
	len = ulen(nb, base);
	str = ft_strnew(len + 1);
	while (nb >= (unsigned)base)
	{
		if ((nb % base) <= 10)
			str[(len--) - 1] = (nb % base) + 48;
		else
			str[(len--) - 1] = 'A' + ((nb % base) - 10);
		nb = nb / base;
	}
	if (nb >= 10)
		nb = nb - 10 - 48 + 'A';
	str[len - 1] = nb + 48;
	return (str);
}
