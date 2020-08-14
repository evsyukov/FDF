#include "fdf.h"

void		convert_to_3d(int32_t *x, int32_t *y, int32_t z)
{
	int32_t	prev_x;
	int32_t	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.5);
	*y = (prev_x + prev_y) * sin(0.5) - z;

//	*x = (*x - *y) * cos(0.8);
//	*y = (*x + *y) * sin(0.8) - z;
}

//static void rotate_around_x(int32_t *y, int32_t *z)
//{
//	int32_t	prev_y;
//
//	prev_y = *y;
//	*y = prev_y * cos(1.68) + *z * sin(1.68);
//	*z = *z * cos (1.68) - prev_y * sin(1.68);
//}

static void	swap_xy(int32_t *x0, int32_t *y0, int32_t *x1, int32_t *y1)
{
	size_t temp;

	temp = *x0;
	*x0 = *x1;
	*x1 = temp;
	temp = *y0;
	*y0 = *y1;
	*y1 = temp;
}

void 		put_pxl_to_img(t_data *data, int32_t x, int32_t y, int32_t color)
{
	int32_t	offset;

	if (x >= 0 && x < WINDOW_X && y >= 0 && y < WINDOW_Y)
	{
		offset = (y * data->sizl) + (x * data->bpp / 8);
		(data->img)[offset] = color;
		(data->img)[++offset] = color >> 8;
		(data->img)[++offset] = color >> 16;
	}
}

static void	draw_line(int32_t x0, int32_t y0,
					int32_t x1, int32_t y1, t_data *data)
{
	int32_t	delta_x;
	int32_t	delta_y;
	int32_t	error;
	int32_t	delta_error;
	int32_t	y;
	int32_t	x;
	int32_t	z0;
	int32_t	z1;
	int32_t	dir_y;
	int32_t	dir_x;

	z0 = data->coords[y0][x0];
	z1 = data->coords[y1][x1];
	x0 *= data->zoom;
	y0 *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
//	z0 *= data->zoom;
//	z1 *= data->zoom;
	data->color = (z0 || z1) ? BROWN : WHITE;

//	rotate_around_x(&y0, &z0);
//	rotate_around_x(&y1, &z1);
	if (data->flagXD == 4)
	{
		convert_to_3d(&x0, &y0, z0);
		convert_to_3d(&x1, &y1, z1);
	}
	x0 += data->shift_x;
	y0 += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;

	delta_x = abs(x1 - x0);
	delta_y = abs(y1 - y0);
	error = 0;
	if (delta_x >= delta_y)
	{
		if (x0 > x1)
			swap_xy(&x0, &y0, &x1, &y1);
		delta_error = delta_y + 1;
		y = y0;
		dir_y = y1 - y0;
		if (dir_y > 0)
			dir_y = 1;
		if (dir_y < 0)
			dir_y = -1;
		x = x0;
		while (x <= x1)
		{
			put_pxl_to_img(data, x, y, data->color);
			error = error + delta_error;
			if (error >= delta_x + 1)
			{
				y += dir_y;
				error -= delta_x + 1;
			}
			++x;
		}
	}
	else
	{
		if (y0 > y1)
			swap_xy(&x0, &y0, &x1, &y1);
		delta_error = delta_x + 1;
		x = x0;
		dir_x = x1 - x0;
		if (dir_x > 0)
			dir_x = 1;
		if (dir_x < 0)
			dir_x = -1;
//		y = delta_x == 0 ? y0 + 1 : y0;
		y = y0;
		while (y <= y1)
		{
			put_pxl_to_img(data, x, y, data->color);
			error = error + delta_error;
			if (error >= delta_y + 1)
			{
				x += dir_x;
				error -= delta_y + 1;
			}
			++y;
		}
	}
}

void 		draw_first_sector(t_data *data)
{
	size_t	index_x;
	int32_t	index_y;

	index_y = data->centre_y - 1;
	while (index_y >= 0)
	{
		index_x = data->centre_x;
		while (index_x < data->len_x)
		{
			if (index_x != data->len_x - 1)
				draw_line(index_x, index_y, index_x + 1, index_y, data);
			draw_line(index_x, index_y, index_x, index_y + 1, data);
			++index_x;
		}
		--index_y;
	}
}

void 		draw_second_sector(t_data *data)
{
	size_t	index_x;
	size_t	index_y;

	index_y = data->centre_y;
	while (index_y < data->len_y)
	{
		index_x = data->centre_x;
		while (index_x < data->len_x)
		{
			if (index_x != data->len_x - 1)
				draw_line(index_x, index_y, index_x + 1, index_y, data);
			if (index_y != data->len_y - 1)
				draw_line(index_x, index_y, index_x, index_y + 1, data);
			++index_x;
		}
		++index_y;
	}
}

void 		draw_third_sector(t_data *data)
{
	int32_t	index_x;
	size_t	index_y;

	index_y = data->centre_y;
	while (index_y < data->len_y)
	{
		index_x = data->centre_x;
		while (index_x >= 0)
		{
			if (index_x != 0)
				draw_line(index_x, index_y, index_x - 1, index_y, data);
			if (index_y != data->len_y - 1)
				draw_line(index_x, index_y, index_x, index_y + 1, data);
			--index_x;
		}
		++index_y;
	}
}

void 		draw_fourth_sector(t_data *data)
{
	int32_t	index_x;
	int32_t	index_y;

	index_y = data->centre_y - 1;
	while (index_y >= 0)
	{
		index_x = data->centre_x;
		while (index_x >= 0)
		{
			if (index_x != 0)
				draw_line(index_x, index_y, index_x - 1, index_y, data);
			draw_line(index_x, index_y, index_x, index_y + 1, data);
			--index_x;
		}
		--index_y;
	}
}

void		draw_map(t_data *data)
{
//	calc_new_centre_for_iso(data);
//	ft_bzero(data->img, WINDOW_X * WINDOW_Y * data->bpp / 8);
//
//	draw_first_sector(data);
//	draw_second_sector(data);
//	draw_third_sector(data);
//	draw_fourth_sector(data);

	size_t	index_x;
	size_t	index_y;

	index_y = 0;
	while (index_y < data->len_y)
	{
		index_x = 0;
		while (index_x < data->len_x)
		{
			if (index_x != data->len_x - 1)
				draw_line(index_x, index_y, index_x + 1, index_y, data);
			if (index_y != data->len_y - 1)
				draw_line(index_x, index_y, index_x, index_y + 1, data);
			++index_x;
		}
		++index_y;
	}
}

void		drawing(t_data *data)
{
	if (data->flagXD == 4)
		write(1, "Projection = ISO\n", 17);
	if (data->flagXD == 1)
		write(1, "Projection = PARALLEL\n", 22);
	ft_bzero(data->img, WINDOW_X * WINDOW_Y * data->bpp / 8);
	draw_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
