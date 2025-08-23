#include "fdf.h"

void	options(void *param, int ordinate, int abscissa)
{
	t_data		*data;

	if (!param)
		return ;
	data = (t_data*)param;
	data->settings->abscissa = abscissa;
	data->settings->ordinate = ordinate;
}