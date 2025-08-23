#include "fdf.h"

void	free_and_exit(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
    free(data->settings);
	free(data);
	exit (0);
}
