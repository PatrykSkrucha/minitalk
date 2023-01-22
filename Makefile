SERVER = server.c

OSERVER = $(SERVER:.c=.o)
OCLIENT = $(CLIENT:.c=.o)

NSERVER = server

LIBFT = libft/libft.a

CFLAGS = -Wall -Wextra -Werror

headers = libft.h

RM = rm -f

all: $(NSERVER)

$(NSERVER): $(OSERVER) $(LIBFT)
	cc $(CFLAGS) $(SERVER) $(LIBFT) -o $(NSERVER)

%.c: %.c
	cc $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

clean:
	$(RM) $(OSERVER)
	make clean -C libft

fclean: clean
	$(RM) $(NSERVER)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean