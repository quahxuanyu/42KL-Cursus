SRC_DIR = src

SRC_FILES = push.c \
		rotate.c \
		sort.c \
		swap.c \
		utils.c

FILES = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

NAME = push_swap.a

OBJS = $(FILES:.c=.o)

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

.c.o:
	cc $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)
	cc src/main.c $(NAME) -o push_swap

$(LIBFT):
	make -C $(LIBFT_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME) push_swap

re: fclean all

.PHONY: all clean fclean re libft