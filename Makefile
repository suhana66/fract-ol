NAME := fractol
CC := cc
CFLAGS := -Wall -Wextra -Werror

SRC := mandatory/fractal_utils.c \
	mandatory/hooks.c \
	mandatory/main.c \
	mandatory/math_utils.c
OBJ := $(SRC:.c=.o)

SRC_BONUS_DIR := bonus
SRC_BONUS := bonus/fractal_utils_bonus.c \
	bonus/hooks_bonus.c \
	bonus/main_bonus.c \
	bonus/math_utils_bonus.c
OBJ_BONUS := $(SRC_BONUS:.c=.o)

LIBFT_PATH := libft
LIBFT := $(LIBFT_PATH)/libft.a
LIBFT_LINK := -L$(LIBFT_PATH) -lft

LIBMLX_PATH := libmlx
LIBMLX := $(LIBMLX_PATH)/libmlx.a
LIBMLX_LINK := -L$(LIBMLX_PATH) -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(LIBMLX)
	$(CC) $(CFLAGS) $(OBJ) -lm $(LIBFT_LINK) $(LIBMLX_LINK) -o $@

bonus: $(OBJ_BONUS) $(LIBFT) $(LIBMLX)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -lm $(LIBFT_LINK) $(LIBMLX_LINK) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBMLX_PATH) -I$(LIBFT_PATH) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_PATH)

$(LIBMLX):
	make -C $(LIBMLX_PATH)

clean:
	make clean -C $(LIBFT_PATH)
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)

fclean: clean
	make clean -C $(LIBMLX_PATH)
	make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean bonus re
