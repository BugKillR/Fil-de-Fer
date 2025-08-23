#include "fdf.h"

void	options(void *param, int ordinate, int abscissa)
{
	t_settings	*settings;

	if (!param)
		return ;
	settings = (t_settings *)param;
	settings->abscissa = abscissa;
	settings->ordinate = ordinate;
}