LIBFT_A = libft.a
MINILIBX_A = libmlx.a
FDF_BIN = fdf

FLASG = -Wall -Wextra -Werror

HEADERS = -I./includes -I./libft
HEADERS_MINILIBX_LINUX_DIR = -I./minilibx/minilibx_linux
HEADERS_MINILIBX_SIERRA_DIR = -I./minilibx/minilibx_sierra

LIBFT_DIR = libft
MINILIBX_LINUX_DIR = minilibx/minilibx_linux
MINILIBX_SIERRA_DIR = minilibx/minilibx_sierra

SRCS_FDF_C = deal_interact.c draw_stuff.c get_next_line.c get_sizes_table.c \
init_table.c main.c menu.c shifts_centres.c utils.c
SRCS_DIR = srcs

OBJS_FDF = $(SRCS_FDF_C:.c=.o)
OBJS_DIR = objs

OBJS_FDF_PATH = $(addprefix $(OBJS_DIR)/, $(OBJS_FDF))

OS := $(shell uname)

ifeq ($(OS), Linux)
    MINILIBX_DIR := $(MINILIBX_LINUX_DIR)
    HEADERS_MINILIBX_DIR := $(HEADERS_MINILIBX_LINUX_DIR)
    FLAG_MLX_OS := -lXext -lX11 -lm
endif

ifeq ($(OS), Darwin)
    MINILIBX_DIR := $(MINILIBX_SIERRA_DIR)
    HEADERS_MINILIBX_DIR := $(HEADERS_MINILIBX_SIERRA_DIR)
    FLAG_MLX_OS := -framework OpenGL -framework Appkit
endif

.Phony : clean fclean all re

all : make_libft_a make_minilibx $(OBJS_FDF_PATH) $(FDF_BIN)

make_libft_a :
	make -C $(LIBFT_DIR)

make_minilibx :
	make -C $(MINILIBX_DIR)

$(FDF_BIN) : $(OBJS_FDF_PATH)
	gcc -o $@ $(OBJS_FDF_PATH) $(HEADERS) $(HEADERS_MINILIBX_DIR) $(LIBFT_DIR)/$(LIBFT_A) \
	$(MINILIBX_DIR)/$(MINILIBX_A) $(FLAG_MLX_OS) -g

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c includes/fdf.h includes/get_next_line.h $(MINILIBX_DIR)/mlx.h
	mkdir -p $(OBJS_DIR)
	gcc -o $@ -c $< $(HEADERS) $(HEADERS_MINILIBX_DIR) $(FLASG) -g

clean :
	$(RM) -rf $(OBJS_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MINILIBX_DIR)

fclean : clean
	$(RM) -rf $(FDF_BIN)
	make fclean -C $(LIBFT_DIR)

re : fclean all
