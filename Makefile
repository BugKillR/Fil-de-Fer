# ---------- Targets ----------
NAME        = FdF.a
EXE         = fdf

# ---------- Toolchain ----------
CC          = cc
CFLAGS      = -Wall -Wextra -Werror \
              -I$(LIBFT_DIR) -I$(MLX_DIR)

# ---------- Sources ----------
SRCS        = instantiate_mlx.c \
				settings.c \
				render.c \
				input.c \
				draw.c \
				free.c
MAIN        = main.c
OBJS        = $(SRCS:.c=.o)

# ---------- Libft ----------
LIBFT_DIR   = ./Libft
LIBFT       = $(LIBFT_DIR)/libft.a

# ---------- GNL ----------

GNL_DIR		= ./get_next_line
GNL			= $(GNL_DIR)/get_next_line.a

# ---------- MiniLibX (Linux) ----------
MLX_DIR     = ./minilibx-linux
MLX			= $(MLX_DIR)/libmlx_Linux.a

# X11 / zlib / math
SYS_LIBS    = -lXext -lX11 -lm -lz

# --------------------------------------

all: $(EXE)

$(EXE): $(MAIN:.c=.o) $(NAME) $(MLX)
	$(CC) $(CFLAGS) $^ $(SYS_LIBS) -o $@

$(NAME): $(OBJS) $(LIBFT) $(GNL)
	ar rcs $@ $(OBJS) $(LIBFT_DIR)/*.o $(GNL_DIR)/*.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) all

$(MLX):
	make -C $(MLX_DIR) all

$(GNL):
	make -C $(GNL_DIR) all

clean:
	make -C $(GNL_DIR) clean
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	rm -f $(OBJS) $(MAIN:.c=.o)

fclean: clean
	make -C $(GNL_DIR) fclean
	make -C $(LIBFT_DIR) fclean
	rm -f $(EXE) $(NAME)
	rm -f $(MLX) $(MLX_DIR)/libmlx_*.a

re: fclean all

.PHONY: all clean fclean re