# ---------- Targets ----------
NAME        = FdF.a          # senin statik arşivin
EXE         = fdf            # çalıştırılabilir

# ---------- Toolchain ----------
CC          = cc
CFLAGS      = -Wall -Wextra -Werror \
              -I$(LIBFT_DIR) -I$(MLX_DIR)

# ---------- Sources ----------
SRCS        = helper1.c          # kendi kaynakların (main HARİÇ)
MAIN        = main.c
OBJS        = $(SRCS:.c=.o)

# ---------- Libft ----------
LIBFT_DIR   = ./Libft
LIBFT       = $(LIBFT_DIR)/libft.a

# ---------- MiniLibX (Linux) ----------
MLX_DIR     = ./minilibx-linux
MLX_LIB     = $(MLX_DIR)/libmlx_Linux.a

# X11 / zlib / math
SYS_LIBS    = -lXext -lX11 -lm -lz

# --------------------------------------

all: $(EXE)

$(EXE): $(MAIN:.c=.o) $(NAME) $(MLX_LIB)
	$(CC) $(CFLAGS) $^ $(SYS_LIBS) -o $@

$(NAME): $(OBJS) $(LIBFT)
	ar rcs $@ $(OBJS) $(LIBFT_DIR)/*.o

# Genel pattern rule (istersen bırakabilirsin; yoksa cc default pattern'i kullanır)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR) all

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS) $(MAIN:.c=.o)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(EXE) $(NAME)
	rm -f $(MLX_LIB) $(MLX_DIR)/libmlx_*.a

re: fclean all

.PHONY: all clean fclean re