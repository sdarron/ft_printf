/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 05:21:30 by sdarron           #+#    #+#             */
/*   Updated: 2020/08/14 05:21:33 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(unsigned long long value, int base)
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

char			*ft_itoa_base(long long int value, int base)
{
	char					*str;
	size_t					len;
	unsigned long long int	nb;

	if (base < 2 || base > 16)
		return (NULL);
	nb = value;
	if (value < 0 && base != 10)
		nb = -value;
	if (base == 10)
		return (ft_itoa(value));
	len = ft_len(nb, base);
	str = ft_strnew(len + 1);
	while (nb >= (unsigned)base)
	{
		if ((nb % base) < 10)
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
