#include "fdf.h"

static void	check_shifts(int key, int32_t *flag_press, t_data *data)
{
	// ВВЕРХ
	if (key == 65362 && (*flag_press = 1))
		data->shift_y -= 5;
	// ВЛЕВО
	if (key == 65361 && (*flag_press = 1))
		data->shift_x -= 5;
	// ВНИЗ
	if (key == 65364 && (*flag_press = 1))
		data->shift_y += 5;
	// ВПРАВО
	if (key == 65363 && (*flag_press = 1))
		data->shift_x += 5;
}

static void check_switch_projection(int key, int32_t *flag_press, t_data *data)
{
	// переключение на PARALLEL
	if (key == 49 && (*flag_press = 1))
		if (data->flagXD != 1 && (data->flagXD = 1))
		{
			calc_coords_centre_table(data);
			calc_zoom_and_shift(data);
		}
	// переключение на ISOMETRIC
	if (key == 52 && (*flag_press = 1))
		if (data->flagXD != 4 && (data->flagXD = 4))
			// перерасчет сдвига для центрирования проекции
			set_projection(data);
}

static void check_switch_zoom(int key, int32_t *flag_press, t_data *data)
{
	// ZOOM x2
	if (key == 113 && (*flag_press = 1))
	{
		data->zoom *= 2;
//		data->shift_x = 2 * data->shift_x - WINDOW_X / 2;
		data->shift_x = WINDOW_X / 2 - (data->len_x * data->zoom) / 2;
		data->shift_y = WINDOW_Y / 2 - (data->len_y * data->zoom) / 2;
		set_projection(data);
	}
	// ZOOM / 2
	if (key == 97 && (*flag_press = 1))
	{
		data->zoom = data->zoom / 2 == 0 ? 1 : data->zoom / 2;
//		data->shift_x = 2 * data->shift_x - WINDOW_X / 2;
		data->shift_x = WINDOW_X / 2 - (data->len_x * data->zoom) / 2;
		data->shift_y = WINDOW_Y / 2 - (data->len_y * data->zoom) / 2;
		set_projection(data);
	}
}

int			deal_key(int key, t_data *data)
{
	int32_t	flag_press;

	flag_press = 0;
	check_shifts(key, &flag_press, data);
	check_switch_projection(key, &flag_press, data);
	check_switch_zoom(key, &flag_press, data);
	// ESC
	if (key == 65307)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free_data(data);
		exit(0);
	}
	// при обработанной клавише - перерисовываем окно
	if (flag_press == 1 && !(flag_press = 0))
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		drawing(data);
	}
	return (0);
}

int			mouse_press_button(int arg, int x, int y, void *data_void)
{
	t_data *data;

	++arg;
	data = (t_data *)data_void;
	data->mouse_x = x;
	data->mouse_y = y;
	data->shift_x += WINDOW_X / 2 - data->mouse_x;
	data->shift_y += WINDOW_Y / 2 - data->mouse_y;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	drawing(data);
	write(1, "Mouse click detected at x = ", 28);
	ft_putnbr(x);
	write(1, " and y = ", 9);
	ft_putnbr(y);
	write(1, "\n", 1);
	return (0);
}

int			mousemove_hook(int x, int y, void *d)
{
	t_data *data;

	data = (t_data *)d;
	++data;

	write(1, "x = ", 4);
	ft_putnbr(x);
	write(1, ", y = ", 6);
	ft_putnbr(y);
	write(1, "\n", 1);
	return (0);
}
