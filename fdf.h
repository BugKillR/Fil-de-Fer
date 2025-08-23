#ifndef FDF_H
# define FDF_H
# include "./minilibx-linux/mlx.h"
# include "./Libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <stdlib.h>
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

typedef struct s_settings
{
	int		abscissa;
	int		ordinate;
}				t_settings;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			line_len;
	int			endian;
	int			bpp;

	// Move image
	int			abscissa;
	int			ordinate;

	// Settings

	t_settings	*settings;
}				t_data;

//	----- Instantiate -----

void    instantiate(void *param, int width, int height, char *title);

//	----- Draw -----

void	put_pixel(t_data *data, int x, int y, int color);
void	draw(t_data *data);

//	----- Input -----

int	keybinds(int keycode, void *param);

//	----- Render -----

int		render(void *param);

//	----- Free -----

void	free_and_exit(void *param);

//	----- Settings -----

void	options(void *param, int ordinate, int abscissa);

#endif