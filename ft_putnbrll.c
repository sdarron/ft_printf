/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrll.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 00:49:45 by sdarron           #+#    #+#             */
/*   Updated: 2020/08/16 16:55:09 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	putnbrll(long long int n, int i)
{
	unsigned long long int	nb;

	if (n < 0)
	{
		ft_putchar('-');
		i++;
		nb = -n;
	}
	else
		nb = n;
	if (nb >= 10)
	{
		i++;
		i = putnbrll(nb / 10, i);
		ft_putchar(nb % 10 + '0');
	}
	else
	{
		ft_putchar(nb + '0');
		i++;
	}
	return (i);
}
