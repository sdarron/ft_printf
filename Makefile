# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/05 16:25:55 by sdarron           #+#    #+#              #
#    Updated: 2020/08/16 17:34:19 by sdarron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	ft_printf.c ft_putnbrf.c\
		ft_putnbrll.c ft_putnbrlln.c ft_putstrn.c ft_retnbr_float.c\
		ft_putcharn.c ft_ptr.c ft_strjoinfree.c ft_octal.c ft_uitoa_base.c\
		ft_declima.c ft_float.c ft_pars.c ft_flags.c ft_percent.c ft_itoa_baseld.c


OBJ		=	$(SRC:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

LIBFTDIR	=	./libft

LIBFT	=	$(LIBFTDIR)/libft.a

all		: $(NAME)

$(NAME)	: $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJ)

$(LIBFT) :
	make -C libft

%.o		:	%.c	./ft_printf.h	./ft_convtab.h	./Makefile
	$(CC) $(CFLAGS) -o $@ -c $<

clean	:
	make -C $(LIBFTDIR) clean
	rm -f	$(OBJ)

fclean	: clean
	rm -f	$(NAME) $(LIBFT)

re		:	fclean all

.PHONY	:	all clean fclean re
