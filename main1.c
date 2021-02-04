/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 17:58:06 by sdarron           #+#    #+#             */
/*   Updated: 2020/08/18 00:50:36 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int main()
{
    float f = 0.0;
    int d = 5;
    char c = 'c';
    int l = 0;
    int x = 200;
    char *str = "lalalal";

    f = 5.0 / 3.0;

    l = ft_printf("%d nana %c nana %s nana %p \n", d, c, str, &d);
    ft_printf("%i", l);
    ft_printf("\n");

    l = printf("%d nana %c nana %s nana %p \n", d, c, str, &d);
    printf("%i", l);
    printf("\n");

    ft_printf("============\n");
    
    l = ft_printf("%0.40f \n", f);
    ft_printf("%i", l);
    ft_printf("\n");

    l = printf("%0.20f \n", f);
    printf("%i", l);
    printf("\n");

    ft_printf("============\n");
    
    l = ft_printf("%#x %X %u %o \n", x, x, x, x);    
    ft_printf("%i", l);
    ft_printf("\n");

    l = printf("%#x %X %u %o \n", x, x, x, x);    
    printf("%i", l);
    printf("\n");

    ft_printf("============\n");
    
    l = ft_printf("%-10d %10c %.3s \n", d, c, str);    
    ft_printf("%i", l);
    ft_printf("\n");

    l = printf("%-10d %10c %.3s \n", d, c, str);    
    printf("%i", l);
    printf("\n");
    
    ft_printf("============\n");
    
    l = ft_printf("%d nana %c nana nana %f nana %x\n", 0, 0, 0.0, 0);
    ft_printf("%i", l);
    ft_printf("\n");

     l = printf("%d nana %c nana nana %f nana %x\n", 0, 0, 0.0, 0);
    printf("%i", l);
    printf("\n");
    
    ft_printf("============\n");
     
    l = ft_printf("%ld\n", 9999999999);
    ft_printf("%lld\n", 9999994444444449);
    ft_printf("%i", l);
    ft_printf("\n");

    l = printf("%ld\n", 9999999999);
    printf("%i", l);
    printf("\n");

    ft_printf("============\n");
    
    l = ft_printf("%*d%*c \n", 4, d, 4, c);    
    ft_printf("%i", l);
    ft_printf("\n");

    l = printf("%*d%*c \n", 4, d, 4, c);    
    printf("%i", l);
    printf("\n");

    return 0;
}
