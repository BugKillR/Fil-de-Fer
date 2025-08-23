#include "fdf.h"

int	keybinds(int keycode, void *param)
{
	t_data		*data;
	
	data = (t_data *)param;
	if (keycode == KEY_ESC)
		free_and_exit(data);
	else if (keycode == KEY_W)
    {
		data->ordinate -= data->settings->ordinate;
		mlx_destroy_image(data->mlx, data->img);
		data->img = mlx_new_image(data->mlx, 450, 300);
    }
	else if (keycode == KEY_A)
	{
		data->abscissa -= data->settings->abscissa;
		mlx_destroy_image(data->mlx, data->img);
		data->img = mlx_new_image(data->mlx, 450, 300);
	}
	else if (keycode == KEY_S)
	{
		data->ordinate += data->settings->ordinate;
		mlx_destroy_image(data->mlx, data->img);
		data->img = mlx_new_image(data->mlx, 450, 300);
	}
	else if (keycode == KEY_D)
	{
		data->abscissa += data->settings->abscissa;
		mlx_destroy_image(data->mlx, data->img);
		data->img = mlx_new_image(data->mlx, 450, 300);
	}
	return (0);
}
