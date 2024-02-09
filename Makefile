NAME = fractol
NAME_BONUS = fractol_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
RM = rm -f
SRC = mandatory/fractol.c mandatory/mlx_events.c mandatory/utilities.c
BONUS =	bonus/fractol_bonus.c bonus/mlx_events_bonus.c \
    bonus/utilities_bonus.c bonus/utilities2_bonus.c
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
SRC_OBJ = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(SRC_OBJ)
	$(CC) $(CFLAGS) $(SRC_OBJ) $(MLX_FLAGS) -o $(NAME)

$(NAME_BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(MLX_FLAGS) -o $(NAME_BONUS)

%.o: %.c fractol.h bonus/fractol_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(SRC_OBJ) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: clean