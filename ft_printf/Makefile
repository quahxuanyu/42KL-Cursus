FILES = ft_printf_func.c \
		ft_printf.c \
		ft_printf_p_xX.c \
		ft_printf_u.c

NAME = libftprintf.a

OBJS = $(FILES:.c=.o)

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

.c.o:
	cc $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

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