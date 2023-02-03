# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafael <rafael@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 17:54:56 by ramartin          #+#    #+#              #
#    Updated: 2023/02/03 17:30:57 by rafael           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT = ./libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
AR = ar -rcs
RM = /bin/rm -f

SRCS = ./src/so_long.c \
		./src/so_long_verify.c \
		./src/so_long_verify_2.c \
		./src/so_long_pathfinding.c \
		./src/so_long_pathfinding_2.c

OBJS = $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

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