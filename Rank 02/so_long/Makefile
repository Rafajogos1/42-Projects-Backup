# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafael <rafael@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 17:54:56 by ramartin          #+#    #+#              #
#    Updated: 2023/02/09 21:54:26 by rafael           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
LIBFT = ./libft/libft.a
MLX = ./mlx/libmlx.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = /bin/rm -f

SRCS = ./src/so_long.c \
		./src/so_long_verify.c \
		./src/so_long_verify_2.c \
		./src/so_long_pathfinding.c \
		./src/so_long_pathfinding_2.c \
		./src/so_long_utils.c \
		./src/so_long_hooks.c

OBJS = $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT) $(MLX)
			$(CC) $(CFLAGS) $(OBJS) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz $(LIBFT) $(MLX) -o $(NAME)

$(LIBFT):
			make -C ./libft
			cp ./libft/libft.a $(NAME)

$(MLX):
			make -C ./mlx
			cp ./mlx/libmlx.a $(NAME)

clean:
			make clean -C ./libft
			make clean -C ./mlx
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C ./libft
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re