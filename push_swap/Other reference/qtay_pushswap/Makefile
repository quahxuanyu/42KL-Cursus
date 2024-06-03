NAME        = push_swap
B_NAME      = checker

SRC_FILES   = build_stack.c cost_algo.c main.c midpoint_algo.c operations.c \
				order_stack_a.c reorder_both.c sort_three_algo.c \
				sorting_index.c target_finder.c utilities.c validator.c \
				validator2.c
B_SRC_FILES = build_stack_bonus.c checker_bonus.c do_both_bonus.c \
				operations_bonus.c utilities_bonus.c validator_bonus.c \
				validator2_bonus.c

SRC         = $(addprefix mandatory/, $(SRC_FILES))
B_SRC       = $(addprefix bonus/, $(B_SRC_FILES))

PATH_OBJS   = objs

OBJ         = $(patsubst mandatory/%.c, $(PATH_OBJS)/%.o, $(SRC))
B_OBJ       = $(patsubst bonus/%.c, $(PATH_OBJS)/%.o, $(B_SRC))

PATH_LIBFT  = libft/
LIBFT       = $(PATH_LIBFT)libft.a

CC          = cc
FLAGS       = -Wall -Wextra -Werror

RM          = rm -fr

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJ)
			$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(PATH_OBJS)/%.o: mandatory/%.c
			mkdir -p $(PATH_OBJS)
			$(CC) $(FLAGS) -I includes/ -c $< -o $@

$(PATH_OBJS)/%.o: bonus/%.c
			mkdir -p $(PATH_OBJS)
			$(CC) $(FLAGS) -I includes/ -c $< -o $@

$(B_NAME):	$(LIBFT) $(B_OBJ)
			$(CC) $(FLAGS) $(B_OBJ) $(LIBFT) -o $(B_NAME)

$(LIBFT):
			make -C $(PATH_LIBFT)

bonus:		$(B_NAME)

clean:
			make -C $(PATH_LIBFT) clean
			$(RM) $(PATH_OBJS)

fclean:		clean
			make -C $(PATH_LIBFT) fclean
			$(RM) $(NAME) $(B_NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
