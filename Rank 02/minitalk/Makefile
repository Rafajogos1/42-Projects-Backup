NAME = minitalk
LIBFT = ./libft/libft.a

CLIENT = client
SERVER = server

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = /bin/rm -f

SRCS_S = ./src/server.c
SRCS_C = ./src/client.c 

OBJS_S = $(SRCS_S:.c=.o)
OBJS_C = $(SRCS_C:.c=.o)

all:		$(NAME)

$(NAME):	$(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT):
			make -C ./libft
			cp ./libft/libft.a $(NAME)

$(SERVER):	$(OBJS_S)
			$(CC) $(OBJS_S) $(LIBFT) -o $(SERVER)
			
$(CLIENT):	$(OBJS_C)
			$(CC) $(OBJS_C) $(LIBFT) -o $(CLIENT)

clean:
			make clean -C ./libft
			$(RM) $(OBJS_S) $(OBJS_C) $(SERVER) $(CLIENT)

fclean:		clean
			make fclean -C ./libft
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re