#include "fdf.h"

int	render(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	draw(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, data->abscissa, data->ordinate);
	return (0);
}
