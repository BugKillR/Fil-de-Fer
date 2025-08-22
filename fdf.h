#ifndef FDF_H
# define FDF_H
# include "./minilibx-linux/mlx.h"
# include <math.h>

# define KEY_ESC      65307
# define KEY_LEFT     65361
# define KEY_UP       65362
# define KEY_RIGHT    65363
# define KEY_DOWN     65364
# define KEY_W        119
# define KEY_A        97
# define KEY_S        115
# define KEY_D        100

typedef struct	s_data {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		line_len;
	int		endian;
	int		bpp;
}				t_data;

#endif