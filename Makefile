NAME := fractol
SRC := julia.c \
	main.c \
	mandelbrot.c
CC := cc
CFLAGS := -Wall -Wextra -Werror

LIBFT_PATH := libft
LIBFT := $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(SRC) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
	make -C $(LIBFT_PATH)

clean:
	make clean -C $(LIBFT_PATH)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
