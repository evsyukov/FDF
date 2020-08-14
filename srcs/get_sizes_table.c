#include "fdf.h"

static size_t	get_len_words(char **words)
{
	size_t	index;

	index = 0;
	while (words[index] != NULL)
		++index;
	return (index);
}

static size_t	get_len_x(t_data *data, char *file_name)
{
	int32_t	flag_gnl;
	int32_t	flag_close;
	size_t	len_x_current;
	size_t	len_x_result;
	char	**words;

	if ((data->fd = open(file_name, O_RDONLY, 0)) == -1)
		print_error_and_exit(OPEN_FILE_PROBLEM, data);
	if ((flag_gnl = get_next_line(data->fd, &(data->line))) == -1)
		print_error_and_exit(GNL_PROBLEM, data);
	if ((words = ft_strsplit(data->line, ' ')) == NULL)
		print_error_and_exit(FT_STRSPLIT_PROBLEM, data);
	free(data->line);
	if ((len_x_current = get_len_words(words)) == 0)
		print_error_and_exit(EMPTY_LINE_DETECTED, data);
	free_words(words);
	len_x_result = len_x_current;
	while ((flag_gnl = get_next_line(data->fd, &(data->line))) == 1)
	{
		if ((words = ft_strsplit(data->line, ' ')) == NULL)
			print_error_and_exit(FT_STRSPLIT_PROBLEM, data);
		free(data->line);
		free_words(words);
		len_x_current = get_len_words(words);
		if (len_x_current != len_x_result)
			print_error_and_exit(LINES_DIFF_LEN_DETECTED, data);
		if (len_x_current == 0)
			print_error_and_exit(EMPTY_LINE_DETECTED, data);
	}
	if ((flag_close = close(data->fd)) == -1 || flag_gnl == -1)
	{
		if (flag_gnl == -1)
			print_error_and_exit(GNL_PROBLEM, data);
		else
			print_error_and_exit(CLOSE_FILE_PROBLEM, data);
	}
	return (len_x_result);
}

static size_t	get_len_y(t_data *data, char *file_name)
{
	int32_t	flag_gnl;
	int32_t	flag_close;
	size_t	len_y;

	len_y = 0;
	if ((data->fd = open(file_name, O_RDONLY, 0)) == -1)
		print_error_and_exit(OPEN_FILE_PROBLEM, data);
	while ((flag_gnl = get_next_line(data->fd, &(data->line))) == 1)
	{
		free(data->line);
		++len_y;
	}
	if ((flag_close = close(data->fd)) == -1 || flag_gnl == -1)
	{
		if (flag_gnl == -1)
			print_error_and_exit(GNL_PROBLEM, data);
		else
			print_error_and_exit(CLOSE_FILE_PROBLEM, data);
	}
	return (len_y);
}

void			get_sizes_table(t_data *data, char *file_name)
{
	data->len_x = get_len_x(data, file_name);
	data->len_y = get_len_y(data, file_name);
}
