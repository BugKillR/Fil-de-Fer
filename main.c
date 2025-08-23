#include "fdf.h"

int main(void)
{
	t_settings	*settings;
	t_data		*data;
	
	data = (t_data *)malloc(sizeof(t_data));
	settings = (t_settings *)malloc(sizeof(t_settings));
	instantiate(data, 450, 300, "Test");
	options(settings, 10, 10);
	mlx_loop_hook(data->mlx, render, data);
	mlx_key_hook(data->win, keybinds, data);
    mlx_loop(data->mlx);
    return (0);
}
