/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 16:25:09 by sdarron           #+#    #+#             */
/*   Updated: 2020/08/16 23:26:54 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include "libft/libft.h"

typedef struct		s_flags
{
	int				l;
	int				min;
	int				plus;
	int				space;
	int				resh;
	int				zr;
	int				percent;
	long long int	w;
	long long int	tchn;
	int				tchn_t;
	char			*mod;
	char			tp;
	char			non_v;
}					t_flags;

int					ft_printf(char *fmt, ...);
int					fdprintf(int fd, char *fmt, ...);
int					nbpass(char *s, int i);
int					printtxt(char *s, t_flags *f, int i, int fd);
int					printnbr(char *s, int fd);
int					precision(char *s, t_flags *f, int i);
int					width(char *s, t_flags *f, int i);
int					pars(va_list ar, t_flags *f, char *s, int fd);
int					parstp(va_list ar, t_flags *f, int i, char *s);
int					putsn(char *str, t_flags *f, int min, int fd);
int					putcharn(char c, t_flags *f, int i, int fd);
int					putnbrll(long long int n, int i);
int					putnbrlln(long long int n, t_flags *f, int fd, int z);
int					putnbrf(va_list ar, t_flags *f, int z, int fd);
int					calcnbr(long long int d);
int					ptrtype(long long int d, t_flags *f, int fd);
int					decl(va_list ar, t_flags *f, int fd);
int					percent(char c, t_flags *f, int fd);
int					octal(long long int d, t_flags *f, int i, int fd);
int					unsig(long long int d, t_flags *f, int i, int fd);
int					hex(long long int d, t_flags *f, int fd, int i);
int					ffloat(va_list ar, t_flags *f, int fd);
char				*strjoinfree(char const *s1, char const *s2, int n);
char				*strtemp(int x, int i, char c);
char				*uitoabase(unsigned long long int value, int base);
char				*itoabaseld(long double value, int base);
t_flags				*obnulfl(t_flags *flags);
t_flags				*nultchn(t_flags *f);

#endif
