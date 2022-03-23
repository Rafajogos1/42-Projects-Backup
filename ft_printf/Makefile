# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramartin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 10:28:36 by ramartin          #+#    #+#              #
#    Updated: 2022/02/16 11:29:32 by ramartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = ./libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS = src/ft_printf.c \
		src/ft_printf_char.c \
		src/ft_printf_string.c \
		src/ft_printf_pointer.c \
		src/ft_printf_num.c \
		src/ft_printf_udec.c \
		src/ft_printf_hex.c

SRCS_OBJ = ft_printf.o \
			ft_printf_char.o \
			ft_printf_string.o \
			ft_printf_pointer.o \
			ft_printf_num.o \
			ft_printf_udec.o \
			ft_printf_hex.o

OBJS = $(SRCS:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
	$(MAKE) bonus -C./libft
	cp libft/libft.a $(NAME)
	$(CC) $(CFLAGS) $(SRCS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(SRCS_OBJ)
	$(RM) $(OBJS)

fclean:			clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			 all clean fclean re
