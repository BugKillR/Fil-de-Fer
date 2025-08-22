#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>
#include <string.h> 

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*pixel;

	pixel = data->addr + (y * data->line_len) + (x * (data->bpp / 8));
	*(unsigned int *)pixel = color;
}

int	render(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	put_pixel(data, 105, 105, 0x00FFFFFF);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int main(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, 450, 300, "Test");
    data->img = mlx_new_image(data->mlx, 450, 300);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_len,
									&data->endian);
	mlx_loop_hook(data->mlx, render, data);
    mlx_loop(data->mlx);
    return (0);
}
