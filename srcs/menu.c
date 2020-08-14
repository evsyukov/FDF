#include "fdf.h"

void output_menu(t_data *data)
{
	int32_t	y = 0;

	mlx_string_put(data->mlx_ptr, data->win_ptr, 65, y += 20, WHITE, "How to Use");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 35, WHITE, "Zoom: Scroll or +/-");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 30, WHITE, "Move: Arrows");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 30, WHITE, "Flatten: </>");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 30, WHITE, "Rotate: Press & Move");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 30, WHITE, "Rotate:");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 57, y += 25, WHITE, "X-Axis - 2/8");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 57, y += 25, WHITE, "Y-Axis - 4/6");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 57, y += 25, WHITE, "Z-Axis - 1(3)/7(9)");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 15, y += 30, WHITE, "Projection");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 57, y += 25, WHITE, "ISO: I Key");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 57, y += 25, WHITE, "Parallel: P Key");
}
