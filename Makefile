SERVER_SRCS	=	server.c
SERVER_OBJS	=	$(SERVER_SRCS:.c=.o)
SERVER_NAME	=	server

CLIENT_SRCS	=	client.c
CLIENT_OBJS	=	$(CLIENT_SRCS:.c=.o)
CLIENT_NAME	=	client

NAME		=	minitalk
RM		=	rm -f
CC		=	gcc
CFLAGS		=	-Wall -Wextra -Werror

$(NAME)		:	$(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME)	:	$(SERVER_OBJS)
			$(CC) $(CFLAGS) $^ -o $@

$(CLIENT_NAME)	:	$(CLIENT_OBJS)
			$(CC) $(CFLAGS) $^ -o $@

all		:	$(NAME)

clean		:
			$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)

fclean		:	clean
			$(RM) $(SERVER_NAME) $(CLIENT_NAME)

re		:	fclean all

bonus		:	$(NAME)

.PHONY		:	all clean fclean re bonus
