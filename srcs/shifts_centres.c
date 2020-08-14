#include "fdf.h"

void	calc_coords_centre_table(t_data *data)
{
	data->centre_x = (data->len_x * data->zoom) / 2;
	data->centre_y = (data->len_y * data->zoom) / 2;
}

void	calc_zoom_and_shift(t_data *data)
{
	int32_t	x_max_zoom;
	int32_t	y_max_zoom;

	if (WINDOW_X < data->len_x || WINDOW_Y < data->len_y)
	{
		write(1, "Size of window less than input data table\n", 42);
		free_data(data);
		exit(0);
	}
	x_max_zoom = (WINDOW_X * 0.8) / data->len_x;
	y_max_zoom = (WINDOW_Y * 0.8) / data->len_y;
	data->zoom = x_max_zoom <= y_max_zoom ? x_max_zoom : y_max_zoom;
	data->shift_x = WINDOW_X / 2 - (data->len_x * data->zoom) / 2;
	data->shift_y = WINDOW_Y / 2 - (data->len_y * data->zoom) / 2;
}

void	calc_new_centre_for_iso(t_data *data)
{
	int32_t	centre_x_with_zoom;
	int32_t	centre_y_with_zoom;

//	centre_x_with_zoom = data->centre_x * data->zoom;
//	centre_y_with_zoom = data->centre_y * data->zoom;
	centre_x_with_zoom = data->centre_x;
	centre_y_with_zoom = data->centre_y;
	convert_to_3d(&centre_x_with_zoom, &centre_y_with_zoom, 0);

//	data->shift_x += (data->centre_x * data->zoom - centre_x_with_zoom);
//	data->shift_y += (data->centre_y * data->zoom - centre_y_with_zoom);

	data->shift_x += (data->centre_x - centre_x_with_zoom);
	data->shift_y += (data->centre_y - centre_y_with_zoom);
}

void	set_projection(t_data *data)
{
	if (data->flagXD == 4)
		calc_new_centre_for_iso(data);
}
