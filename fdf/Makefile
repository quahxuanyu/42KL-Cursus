# Directories
SRCDIR = src/
OBJDIR = objs/
SRC_FILES = main.c \
			init_map.c \
			helper.c \
			draw_line.c \
			draw_map.c \
			init_data.c \
			utils.c \
			color.c \
			free.c

SRCS = $(addprefix $(SRCDIR), $(SRC_FILES))
OBJS = $(addprefix $(OBJDIR), $(notdir $(SRCS:.c=.o)))

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

#FLAGS = -Wall -Wextra -Werror
FLAGS = -Wall -Wextra -Werror

FDF = fdf
NAME = $(FDF)

# Rules
all: $(OBJDIR) $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(FLAGS) -I/usr/include -I mlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	rm -rf $(OBJDIR)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft