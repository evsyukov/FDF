#include "fdf.h"

void	debug_output(t_data *data)
{
	size_t index_x;
	size_t index_y;

	write(1, "len_x = ", 8);
	ft_putnbr(data->len_x);
	write(1, ", len_y = ", 10);
	ft_putnbr(data->len_y);
	write(1, "\n\n", 2);

	index_y = 0;
	while (index_y < data->len_y)
	{
		index_x = 0;
		while (index_x < data->len_x)
		{
			if (index_x != 0)
				write(1, " ", 1);
			ft_putnbr(data->coords[index_y][index_x]);
			++index_x;
		}
		write(1, "\n", 1);
		++index_y;
	}
}

void	init_data(t_data *data)
{
	data->fd = 0;
	data->line = NULL;
	data->len_x = 0;
	data->len_y = 0;
	data->coords = NULL;
	data->zoom = 20;
	data->min_z = INT_MAX;
	data->max_z = INT_MIN;
	data->low_z_color = 0;
	data->hi_z_color = 0;
	data->color = WHITE;
	data->centre_x = 0;
	data->centre_y = 0;
	data->shift_x = 0;
	data->delta_shift_x = 0;
	data->shift_y = 0;
	data->delta_shift_y = 0;
	data->flagXD = 1;
	data->mouse_x = 0;
	data->mouse_y = 0;
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->img_ptr = NULL;
}

void	free_data(t_data *data)
{
	size_t	index;

	if (data->coords == NULL)
		return ;
	index = 0;
	while (data->coords[index] != NULL)
	{
		free(data->coords[index]);
		++index;
	}
	free(data->coords);
	free(data->line);
}

void	print_error_and_exit(char *type_error, t_data *data)
{
	free_data(data);
	if (!errno)
		ft_putendl_fd(type_error, 2);
	else
		perror("ERROR ");
	exit(1);
}
