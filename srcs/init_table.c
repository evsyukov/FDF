#include "fdf.h"

void		free_words(char **words)
{
	size_t	index;

	index = 0;
	while (words[index] != NULL)
	{
		free(words[index]);
		++index;
	}
	free(words);
}

static void	fill_line_at_nums(t_data *data, size_t index_coords)
{
	size_t	index;
	int32_t	*nums;
	char	**words;

	nums = (int32_t *)malloc(sizeof(int32_t) * (data->len_x));
	if (nums == NULL)
		print_error_and_exit(MALLOC_PROBLEM, data);
	if ((words = ft_strsplit(data->line, ' ')) == NULL)
		print_error_and_exit(FT_STRSPLIT_PROBLEM, data);
	index = 0;
	while (index < data->len_x)
	{
		nums[index] = ft_atoi(words[index]);
		if (nums[index] < data->min_z)
			data->min_z = nums[index];
		if (nums[index] > data->max_z)
			data->max_z = nums[index];
		++index;
	}
	free_words(words);
	data->coords[index_coords] = nums;
}

void		init_table(t_data *data, char *file_name)
{
	int32_t	flag_gnl;
	int32_t	flag_close;
	int32_t	**coords;
	size_t	index;

	coords = (int32_t **)malloc(sizeof(int32_t *) * (data->len_y + 1));
	if (coords == NULL)
		print_error_and_exit(MALLOC_PROBLEM, data);
	if ((data->fd = open(file_name, O_RDONLY, 0)) == -1)
		print_error_and_exit(OPEN_FILE_PROBLEM, data);
	index = 0;
	data->coords = coords;
	while ((flag_gnl = get_next_line(data->fd, &(data->line))) == 1)
	{
		fill_line_at_nums(data, index++);
		free(data->line);
	}
	if ((flag_close = close(data->fd)) == -1 || flag_gnl == -1)
	{
		if (flag_gnl == -1)
			print_error_and_exit(GNL_PROBLEM, data);
		else
			print_error_and_exit(CLOSE_FILE_PROBLEM, data);
	}
	data->coords[index] = NULL;
}
