NAME		=	tests

TESTS		=	parser.c tuples.c colors.c canvas.c matrices.c transformations.c \
				rays.c spheres.c reflection.c world.c camera.c computations.c \
				shadows.c cylinders.c shapes.c planes.c parser_elements.c \
				parser_full_files.c parser_open_files.c parser_shapes.c

PLATFORM_DEPENDENT_FILES = main_mac.c main_linux.c create_window_mac.c \
			create_window_linux.c mlx_hooks_mac.c mlx_hooks_linux.c \
			render_menu_mac.c render_menu_linux.c
PLATFORM_DEPENDENT_FILES	:=	$(addprefix ../src/platform_dependent/, $(PLATFORM_DEPENDENT_FILES))

COPIED_PLATFORM_DEPENDENT_FILES = ../src/main.c ../src/window/create_window.c ../src/window/mlx_hooks.c \
			../src/window/render_menu.c

SRC_DIR		=	../src
SRC			=	$(SRC_DIR)/%.c
SRC			:=	$(filter-out $(PLATFORM_DEPENDENT_FILES), $(SRC))
OBJ_DIR		=	../obj
LIBFT_DIR 	=	../lib/libft/
LIBFT		=	../lib/libft/libft.a
LIBFT_MAKE	=	../lib/libft/Makefile

UNAME		=	$(shell uname -s)

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

CRITERION_EXISTS := $(shell pkg-config --exists criterion && echo "yes" || echo "no")

ifeq ($(UNAME), Darwin)
		MLX_DIR		=	../lib/mlx_osx/
		MLX_FLAGS	=	-L $(MLX_DIR) -l mlx -framework OpenGl -framework Appkit
		INC_DIRS	=	-I../inc/ -I../lib/libft/inc/ -I$(MLX_DIR)
endif

ifeq ($(UNAME), Linux)
		MLX_DIR		=	../lib/mlx_linux/
		MLX_FLAGS	=	-L $(MLX_DIR) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
		INC_DIRS	= 	-I../inc/ -I../lib/libft/inc/ -I$(MLX_DIR)
endif

ifeq ($(UNAME), Darwin)
		CRITERION_FLAGS := -lcriterion -I/Users/johnnymosby/.brew/Cellar/criterion/2.4.1_3/include/ \
				-L/Users/johnnymosby/.brew/Cellar/criterion/2.4.1_3/lib/
else ifeq ($(CRITERION_EXISTS), yes)
		CRITERION_FLAGS:= $(shell pkg-config --cflags-only-I criterion | sed 's/-I//')
else
		CRITERION_FLAGS := -lcriterion  -L../lib/criterion/lib/ -I$(realpath ../lib/criterion/include)
		CRITERION_DIRS := -I..lib/criterion/include/
		export LD_LIBRARY_PATH := $(LD_LIBRARY_PATH):$(realpath ../lib/criterion/lib)
endif


MLX			=	$(MLX_DIR)libmlx.a

SOURCE = $(shell find $(SRC_DIR) -name '*.c')
SOURCE := $(filter-out $(SRC_DIR)/main.c, $(SOURCE))
SOURCE := $(filter-out $(PLATFORM_DEPENDENT_FILES), $(SOURCE))

$(COPIED_PLATFORM_DEPENDENT_FILES):
ifeq ($(UNAME), Darwin)
		cp ../src/platform_dependent/main_mac.c ../src/main.c
		cp ../src/platform_dependent/create_window_mac.c ../src/window/create_window.c
		cp ../src/platform_dependent/mlx_hooks_mac.c ../src/window/mlx_hooks.c
		cp ../src/platform_dependent/render_menu_mac.c ../src/window/render_menu.c
endif
ifeq ($(UNAME), Linux)
		cp ../src/platform_dependent/main_linux.c ../src/main.c
		cp ../src/platform_dependent/render_menu_linux.c ../src/window/render_menu.c
		cp ../src/platform_dependent/mlx_hooks_linux.c ../src/window/mlx_hooks.c
		cp ../src/platform_dependent/render_menu_linux.c ../src/window/render_menu.c
endif

$(LIBFT):
			if [ ! -e $(LIBFT_MAKE) ]; then \
				git submodule update --init --recursive; \
			fi
			make -C $(LIBFT_DIR)

OBJ		= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCE))

$(OBJ_DIR)/%.o: $(SRC)
			@mkdir -p $(@D)
			$(CC) $(CFLAGS) $(INC_DIRS) -c $< -o $@

$(MLX):
			make -C $(MLX_DIR)

$(TESTS): $(OBJ) $(LIBFT) $(MLX)
	@$(call compile, "$^")

define compile
 	$(CC) $(CFLAGS) $^ $(INC_DIRS) $(MLX_FLAGS) $(CRITERION_FLAGS) -o $(basename $@ .c) && ./$(basename $@ .c) --verbose
endef

# -------------------------------- TESTS ------------------------------------- #

all: $(LIBFT) $(OBJ) $(MLX) | $(COPIED_PLATFORM_DEPENDENT_FILES)
	make parser
	make tuples
	make colors
	make canvas
	make matrices
	make world
	make camera
	make computations
	make rays
	make transformations
	make shadows
	make shapes
	make planes

parser: $(LIBFT) $(OBJ) $(MLX) parser_elements.c parser_full_files.c parser_open_files.c parser_shapes.c | $(COPIED_PLATFORM_DEPENDENT_FILES)
	@$(call compile, "$^")
parser_elements: $(LIBFT) $(OBJ) $(MLX) parser_elements.c | $(COPIED_PLATFORM_DEPENDENT_FILES)
	@$(call compile, "$^")
parser_full_files: $(LIBFT) $(OBJ) $(MLX) parser_full_files.c | $(COPIED_PLATFORM_DEPENDENT_FILES)
	@$(call compile, "$^")
parser_open_files: $(LIBFT) $(OBJ) $(MLX) parser_open_files.c | $(COPIED_PLATFORM_DEPENDENT_FILES)
	@$(call compile, "$^")

tuples: $(LIBFT) $(OBJ) $(MLX) tuples.c | $(COPIED_PLATFORM_DEPENDENT_FILES)
	@rm -f $(patsubst %.c,%,$(TESTS))
	@$(call compile, "$^")

colors: $(LIBFT) $(OBJ) $(MLX) colors.c | $(COPIED_PLATFORM_DEPENDENT_FILES)
	@$(call compile, "$^")

canvas: $(LIBFT) $(OBJ) $(MLX) canvas.c | $(COPIED_PLATFORM_DEPENDENT_FILES)
	@$(call compile, "$^")

matrices: $(LIBFT) $(OBJ) $(MLX) matrices.c | $(COPIED_PLATFORM_DEPENDENT_FILES)
	@$(call compile, "$^")

transformations: $(LIBFT) $(OBJ) $(MLX) transformations.c | $(COPIED_PLATFORM_DEPENDENT_FILES)
	@$(call compile, "$^")

rays: $(LIBFT) $(OBJ) $(MLX) rays.c | $(COPIED_PLATFORM_DEPENDENT_FILES)
	@$(call compile, "$^")

spheres: $(LIBFT) $(OBJ) $(MLX) spheres.c | $(COPIED_PLATFORM_DEPENDENT_FILES)
	@$(call compile, "$^")

reflection: $(LIBFT) $(OBJ) $(MLX) reflection.c | $(COPIED_PLATFORM_DEPENDENT_FILES)
	@$(call compile, "$^")

world: $(LIBFT) $(OBJ) $(MLX) world.c
	@$(call compile, "$^")

camera: $(LIBFT) $(OBJ) $(MLX) camera.c
	@$(call compile, "$^")

computations: $(LIBFT) $(OBJ) $(MLX) computations.c
	@$(call compile, "$^")

shapes: $(LIBFT) $(OBJ) $(MLX) shapes.c
	@$(call compile, "$^")

shadows: $(LIBFT) $(OBJ) $(MLX) shadows.c
	@$(call compile, "$^")

cylinders: $(LIBFT) $(OBJ) $(MLX) cylinders.c
	@$(call compile, "$^")

planes: $(LIBFT) $(OBJ) $(MLX) planes.c
	@$(call compile, "$^")

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)
	@rm -f $(patsubst %.c,%,$(TESTS))

fclean: clean
	make clean -C $(MLX_DIR)
	make fclean -C $(LIBFT_DIR)
	rm $(COPIED_PLATFORM_DEPENDENT_FILES)

re: fclean all

.PHONY: all clean fclean re
