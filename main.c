#include "fdf.h"

int main(void)
{
	t_data		*data;
	
	data = (t_data *)malloc(sizeof(t_data));
	instantiate(data, 450, 300, "Test");
	options(data, 10, 10);
	mlx_loop_hook(data->mlx, render, data);
	mlx_key_hook(data->win, keybinds, data);
    mlx_loop(data->mlx);
    return (0);
}
