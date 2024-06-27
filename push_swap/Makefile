SRC_DIR = src

BONUS_DIR = bonus

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

BONUS_SRC = checker.c \
			push.c \
			reverse_rotate.c \
			rotate.c \
			swap.c \
			validate_input.c \
			bonus_utils.c \
			init_stack.c

FILES = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
BONUS_FILES = $(addprefix $(BONUS_DIR)/, $(BONUS_SRC))

NAME = push_swap
B_NAME = checker

OBJS = $(FILES:.c=.o)
B_OBJS = $(BONUS_FILES:.c=.o)

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
	
$(B_NAME):	$(LIBFT) $(B_OBJS)
	cc $(FLAGS) $(B_OBJS) $(LIBFT) -o $(B_NAME)

bonus:		$(B_NAME)

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME) $(B_NAME)

re: fclean all

.PHONY: all clean fclean re libft
