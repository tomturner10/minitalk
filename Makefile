
NAME = libft.a

CLIENT_SRCS = minitalk_client.c

SERVER_SRCS = minitalk_server.c

FLAGS = -Werror -Wextra -Wall

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) bonus -C ./libft
	$(MAKE) server client
	cp libft/libft.a $(NAME)

server:
	$(CC) $(FLAGS) -I libft libft/libft.a $(SERVER_SRCS) -o server

client:
	$(CC) $(FLAGS) -I libft libft/libft.a $(CLIENT_SRCS) -o client

clean:
	$(MAKE) clean -C ./libft
	rm -f client server

fclean:
	$(MAKE) fclean -C ./libft
	rm -f $(NAME) server client

re: fclean all

.PHONY: all clean fclean re