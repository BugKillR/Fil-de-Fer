#include "fdf.h"

int	keybinds(int keycode, void *maindata, void *rules)
{
	t_settings	*settings;
	t_data		*data;
	
	data = (t_data *)maindata;
	settings = (t_settings *)rules;
	if (keycode == KEY_ESC)
		free_and_exit(data);
	else if (keycode == KEY_W)
    {
		data->ordinate -= settings->ordinate;
		mlx_destroy_image(data->mlx, data->img);
		data->img = mlx_new_image(data->mlx, 450, 300);
    }
	else if (keycode == KEY_A)
	{
		data->abscissa -= settings->abscissa;
		mlx_destroy_image(data->mlx, data->img);
		data->img = mlx_new_image(data->mlx, 450, 300);
	}
	else if (keycode == KEY_S)
	{
		data->ordinate += settings->ordinate;
		mlx_destroy_image(data->mlx, data->img);
		data->img = mlx_new_image(data->mlx, 450, 300);
	}
	else if (keycode == KEY_D)
	{
		data->abscissa += settings->abscissa;
		mlx_destroy_image(data->mlx, data->img);
		data->img = mlx_new_image(data->mlx, 450, 300);
	}
	return (0);
}
