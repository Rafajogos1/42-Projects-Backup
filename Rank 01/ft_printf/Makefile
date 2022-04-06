# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 10:28:36 by ramartin          #+#    #+#              #
#    Updated: 2022/03/29 10:45:46 by ramartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = ./libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = /bin/rm -f

SRCS = ./src/ft_printf.c \
		./src/ft_printf_char.c \
		./src/ft_printf_string.c \
		./src/ft_printf_pointer.c \
		./src/ft_printf_num.c \
		./src/ft_printf_udec.c \
		./src/ft_printf_hex.c

OBJS = $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
			$(AR) $(NAME) $(OBJS)

$(LIBFT):
			make -C ./libft
			cp ./libft/libft.a $(NAME)

clean:
			make clean -C ./libft
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C ./libft
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
