CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a

NAME_SERVER = server
NAME_CLIENT = client

SRC_SERVER = server.c
SRC_CLIENT = client.c

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(SRC_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(SRC_SERVER) $(LIBFT)

$(NAME_CLIENT): $(SRC_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(SRC_CLIENT) $(LIBFT)

$(LIBFT):
	make -C ./libft

clean:
	rm -f *.o
	make -C ./libft clean

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	make -C ./libft fclean

re: fclean all
