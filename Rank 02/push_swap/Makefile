# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramartin <ramartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 17:54:56 by ramartin          #+#    #+#              #
#    Updated: 2023/01/19 18:40:18 by ramartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
LIBFT = ./libft/libft.a

PS = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = /bin/rm -f

SRCS = ./src/push_swap.c \
		./src/push_swap_cases.c \
		./src/push_swap_verify.c \
		./src/push_swap_instructions.c \
		./src/push_swap_instructions_2.c \
		./src/push_swap_instructions_3.c \
		./src/push_swap_utils.c \
		./src/push_swap_utils_2.c \
		./src/push_swap_utils_3.c \
		./src/push_swap_utils_4.c \
		./src/push_swap_utils_5.c 

OBJS = $(SRCS:.c=.o)

all:		$(NAME) $(PS)

$(NAME):	$(OBJS) $(LIBFT)
			$(AR) $(NAME) $(OBJS)

$(LIBFT):
			make -C ./libft
			cp ./libft/libft.a $(NAME)

$(PS):		$(OBJS) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(PS)

clean:
			make clean -C ./libft
			$(RM) $(OBJS)

fclean:		clean
			make fclean -C ./libft
			$(RM) $(NAME) $(PS)

re:			fclean $(NAME)

.PHONY:		all clean fclean re