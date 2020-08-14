#ifndef FDF_H
#define FDF_H

#include "libft.h"
#include "get_next_line.h"
#include <math.h>
#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

typedef struct	s_data
{
	int		fd;	// fd
	char	*line;	// буфер для GNL
	size_t	len_x;	// длина таблицы по X
	size_t	len_y;	// длина таблицы по Y
	int32_t	**coords;	// двумерный массив интов (высота Z)
	size_t	zoom;	// Зум, может менятся в процессе по клавише
	int32_t	min_z;	// (not use yet)!! минимальная высота (Z)
	int32_t	max_z;	// (not use yet)!! максимальная высота (Z)
	int32_t	low_z_color;	// (not use yet)!! цвет для "нижней" части высот
	int32_t	hi_z_color;	// (not use yet)!! цвет для "верхней" части высот
	int32_t	color;	// цвет для отрисовки точки конкретной
	int32_t	centre_x;	// относительная координата центра нашего основания по XY
						// с учетом зума (zoom)
	int32_t	centre_y;	// относительная координата центра нашего основания по XY
						// с учетом зума (zoom)
	int32_t	shift_x;	// сдвиг по абсциссе
	int32_t	delta_shift_x;	// изменение сдвига по абсциссе
	int32_t	shift_y;	// сдвиг по ординате
	int32_t	delta_shift_y; // // изменение сдвига по ординате
	int32_t	flagXD;	// flag проекции
	size_t	mouse_x;	// Координата X, где щелкнули мышкой
	size_t	mouse_y;	// Координата Y, где щелкнули мышкой
	char	*img;	// массив байт для записи в экран
	int		bpp;	// количество битов на пиксель
	int		sizl;	// количество пикселей на одной линии окна
	int		endian; // очередность RGB в байте, зависит от платформы
	void	*mlx_ptr;	// служебные указатели либы mlx
	void	*win_ptr;	// служебные указатели либы mlx
	void	*img_ptr;	// служебные указатели либы mlx
}				t_data;

#define WINDOW_X 800
#define WINDOW_Y 800
#define BLACK 0x000000
#define GREEN 0x00FF00
#define BROWN 0x800000
#define WHITE 0xFFFFFF

#define MALLOC_PROBLEM "Malloc problem"
#define OPEN_FILE_PROBLEM "Open file problem"
#define GNL_PROBLEM "GNL problem"
#define FT_STRSPLIT_PROBLEM "FT_STRSPLIT problem"
#define EMPTY_LINE_DETECTED "Invalid map. Empty file in file detected"
#define LINES_DIFF_LEN_DETECTED "Invalid map. Lines with different lens detected"
#define CLOSE_FILE_PROBLEM "Close file problem"

// deal_interact.c
int				deal_key(int key, t_data *data);
int				mouse_press_button(int arg, int x, int y, void *data_void);
int				mousemove_hook(int x, int y, void *d);

// draw_stuff.c
void			convert_to_3d(int32_t *x, int32_t *y, int32_t z);
void			put_pxl_to_img(t_data *data,
					  int32_t x, int32_t y, int32_t color);
void			draw_map(t_data *data);
void			drawing(t_data *data);

// get_sizes_table
void			get_sizes_table(t_data *data, char *file_name);

// init_table
void			free_words(char **words);
void			init_table(t_data *data, char *file_name);

// main.c

// menu.c
void			output_menu(t_data *data);

// shifts_centres.c
void			calc_coords_centre_table(t_data *data);
void			calc_zoom_and_shift(t_data *data);
void			calc_new_centre_for_iso(t_data *data);
void			set_projection(t_data *data);

// utils.c
void			debug_output(t_data *data);
void			init_data(t_data *data);
void			free_data(t_data *data);
void			print_error_and_exit(char *type_error, t_data *data);

#endif
