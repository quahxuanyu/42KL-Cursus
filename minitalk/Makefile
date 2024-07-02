NAMEC = client
NAMES = server

C_SRC = client.c
S_FILE = server.c
SRC_DIR = src

C_FILE = src/client.c
S_FILE = src/server.c

C_OBJ = $(C_FILE:.c=.o)
S_OBJ = $(S_FILE:.c=.o)

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

FLAGS = -Wall -Wextra -Werror

all: $(NAMES) $(NAMEC)

.c.o:
	cc $(FLAGS) -c $< -o $@

$(NAMEC): $(C_OBJ) $(LIBFT)
	cc $(C_OBJ) $(LIBFT) -o client

$(NAMES): $(S_OBJ) $(LIBFT)
	cc $(S_OBJ) $(LIBFT) -o server

$(LIBFT):
	make -C $(LIBFT_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(S_OBJ) $(C_OBJ)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAMES) $(NAMEC)

re: fclean all

.PHONY: all clean fclean re libft