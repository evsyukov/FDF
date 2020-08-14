#include "fdf.h"

static int32_t	is_valid_args(int32_t argc)
{
	if (argc == 1)
		return (0);
	if (argc > 2)
	{
		write(1, "usage: ./fdf path/to/file\n", 26);
		return (0);
	}
	return (1);
}

static void		read_from_file(t_data *data, char *file_name)
{
	get_sizes_table(data, file_name);
	init_table(data, file_name);
}

void			prepare_data(t_data *data)
{
	calc_zoom_and_shift(data);
	calc_coords_centre_table(data);
	set_projection(data);
}

void			prepare_window_and_image(t_data *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_X, WINDOW_Y, "FDF");
	data->img_ptr = mlx_new_image(data->mlx_ptr, WINDOW_X, WINDOW_Y);
	data->img = mlx_get_data_addr(data->img_ptr, &(data->bpp),
							   &(data->sizl), &(data->endian));
}

int				main(int argc, char **argv)
{
	t_data	data;

	if (!(is_valid_args(argc)))
		return (0);
	init_data(&data);
	read_from_file(&data, argv[1]);
	debug_output(&data);
	prepare_data(&data);
	prepare_window_and_image(&data);

	write(1, "bpp = ", 6);
	ft_putnbr(data.bpp);
	write(1, ", sizl = ", 9);
	ft_putnbr(data.sizl);
	write(1, ", endian = ", 11);
	ft_putnbr(data.endian);
	write(1, "\n", 1);

	drawing(&data);
	mlx_hook(data.win_ptr, 2, 1L << 0, deal_key, &data);
	mlx_hook(data.win_ptr, 4, 1L << 2, mouse_press_button, &data);
//	mlx_hook(data.win_ptr, 6, 1L << 6, mousemove_hook, &data);
	mlx_loop(data.mlx_ptr);
	free_data(&data);
	return (0);
}
