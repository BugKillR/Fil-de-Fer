NAME	= FdF.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= helper1.c
OBJS	= $(SRCS:.c=.o)

# ---- Libft ----
LIBFT_DIR	= ./Libft
LIBFT		= $(LIBFT_DIR)/libft.a

# ---- MiniLibX (Linux) ----

MLX_DIR		= ./minilibx-linux

UNAME		= $(shell uname)
NAME_UNAME	= libmlx_$(UNAME).a

MLX			= $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lz

all: $(NAME)
	$(CC) $(CFLAGS) $(MLX_FLAGS) main.c *.a -o fdf

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	ar rcs $(NAME) $(OBJS) $(LIBFT_DIR)/*.o $(MLX_DIR)/obj/*.o

$(LIBFT):
	make -C $(LIBFT_DIR) all

$(MLX):
	make -C $(MLX_DIR) all

clean:
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -rf $(MLX_DIR)/$(NAME_UNAME)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re