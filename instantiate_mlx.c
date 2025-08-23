#include "fdf.h"

void    instantiate(void *param, int width, int height, char *title)
{
    t_data  *data;

    data = (t_data *)param;
    data->settings = (t_settings *)malloc(sizeof(t_settings));
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, width, height, title);
    data->img = mlx_new_image(data->mlx, width, height);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_len,
									&data->endian);
}