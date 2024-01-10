NAME := fractol
SRC := hooks.c \
	julia.c \
	main.c \
	mandelbrot.c \
	utils.c
CC := cc
CFLAGS := -Wall -Wextra -Werror -fsanitize=address

LIBFT_PATH := libft
LIBFT := $(LIBFT_PATH)/libft.a
LIBFT_LINK := -I$(LIBFT_PATH) -L$(LIBFT_PATH) -lft

LIBMLX_PATH := libmlx
LIBMLX := $(LIBMLX_PATH)/libmlx.a
LIBMLX_LINK := -I$(LIBMLX_PATH) -L$(LIBMLX_PATH) -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRC) $(LIBFT) $(LIBMLX)
	$(CC) $(CFLAGS) $(SRC) -lm $(LIBFT_LINK) $(LIBMLX_LINK) -o $@

$(LIBFT):
	make -C $(LIBFT_PATH)

$(LIBMLX):
	make -C $(LIBMLX_PATH)

clean:
	make clean -C $(LIBMLX_PATH)
	make clean -C $(LIBFT_PATH)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
