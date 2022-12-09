# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 10:28:36 by ramartin          #+#    #+#              #
#    Updated: 2022/04/06 11:18:16 by ramartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS = ft_atoi.c \
		  ft_bzero.c \
		  ft_calloc.c \
		  ft_isalnum.c \
		  ft_isalpha.c \
		  ft_isascii.c \
		  ft_isdigit.c \
		  ft_isprint.c \
		  ft_itoa.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_memcpy.c \
		  ft_memmove.c \
		  ft_memset.c \
		  ft_power.c \
		  ft_lstadd_back.c \
		  ft_lstadd_front.c \
		  ft_lstclear.c \
		  ft_lstdelone.c \
		  ft_lstiter.c \
		  ft_lstlast.c \
		  ft_lstmap.c \
		  ft_lstnew.c \
		  ft_lstsize.c \
		  ft_printf_char.c \
		  ft_printf_hex.c \
		  ft_printf_num.c \
		  ft_printf_pointer.c \
		  ft_printf_string.c \
		  ft_printf_udec.c \
		  ft_printf.c \
		  ft_putchar_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_putstr_fd.c \
		  ft_split.c \
		  ft_strchr.c \
		  ft_strdup.c \
		  ft_striteri.c \
		  ft_strjoin.c \
		  ft_strlcat.c \
		  ft_strlcpy.c \
		  ft_strlen.c \
		  ft_strmapi.c \
		  ft_strncmp.c \
		  ft_strnstr.c \
		  ft_strrchr.c \
		  ft_strtrim.c \
		  ft_substr.c \
		  ft_tolower.c \
		  ft_toupper.c	

OBJS = $(SRCS:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:			clean
	$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			 all clean fclean re
