#include "fdf.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*pixel;

	pixel = data->addr + ((y + data->ordinate) * data->line_len) + ((x + data->abscissa) * (data->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	draw(t_data *data)
{
	int	x;
	int	y;

	x = 10;
	y = 10;
	while (x < 210)
		put_pixel(data, x++, y++, 0x00FFFFFF);
}
