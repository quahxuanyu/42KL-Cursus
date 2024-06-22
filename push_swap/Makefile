SRC_DIR = src

SRC_FILES = push.c \
		rotate.c \
		sort_three_algo.c \
		sort_index.c \
		push_swap_algo.c \
		swap.c \
		utils.c \
		reverse_rotate.c \
		cost_algo.c \
		order_stack_a.c \
		main.c \
		validate_input.c \
		pre_sort_b.c

FILES = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

NAME = push_swap

OBJS = $(FILES:.c=.o)

FLAGS = -Wall -Wextra -Werror

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

.c.o:
	cc $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	cc $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
