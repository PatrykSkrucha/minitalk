SERVER = server.c
CLIENT = client.c

OSERVER = $(SERVER:.c=.o)
OCLIENT = $(CLIENT:.c=.o)

NSERVER = server
NCLIENT = client

LIBFT = libft/libft.a

CFLAGS = -Wall -Wextra -Werror

headers = libft.h

RM = rm -f
COLORSTART = \033[92m
COLOREND = \033[0m

all: $(NSERVER) $(NCLIENT)

$(NSERVER): $(OSERVER) $(LIBFT)
	cc $(CFLAGS) $(SERVER) $(LIBFT) -o $(NSERVER)

$(NCLIENT): $(OCLIENT) $(LIBFT)
	cc $(CFLAGS) $(CLIENT) $(LIBFT) -o $(NCLIENT)

$(LIBFT):
	make -C libft

clean:
	$(RM) $(OSERVER) $(OCLIENT)
	make clean -C libft

fclean: clean
	$(RM) $(NSERVER) $(NCLIENT)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean