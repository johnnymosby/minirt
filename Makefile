NAME	=	minirt

LIBFT		=	./lib/libft/libft.a
LIBFT_MAKE	=	./lib/libft/Makefile
INC_LIBFT	=	-I./lib/libft/inc

UNAME	=	$(shell uname -s)

CC		=	cc
CFLAGS	+=	-Wall -Wextra -Werror

MAIN	=	main.c

TUPLES	=	create_tuple.c logical_operations.c arithmetic_operations.c \
			vectors_manipulation.c
TUPLES	:=	$(addprefix tuples/, $(TUPLES))

COLORS	=	create_color.c arithmetic_operations.c logical_operations.c
COLORS	:=	$(addprefix colors/, $(COLORS))

CANVAS	=	create_canvas.c pixels.c save_canvas.c
CANVAS	:=	$(addprefix canvas/, $(CANVAS))

WINDOW	=	create_window.c
WINDOW	:=	$(addprefix window/, $(WINDOW))

MATRICES	=	utils.c logical_operations.c arithmetic_operations.c \
				properties.c transformations.c rotations.c
MATRICES	:=	$(addprefix matrices/, $(MATRICES))

RAYS	=	utils.c light.c lightning.c
RAYS	:=	$(addprefix rays/, $(RAYS))

SHAPES	=	utils.c spheres.c intersection.c reflection.c
SHAPES	:=	$(addprefix shapes/, $(SHAPES))

SOURCE	=	$(MAIN) $(TUPLES) $(COLORS) $(CANVAS) $(WINDOW) $(MATRICES) $(RAYS) $(SHAPES)
SRC_DIR	=	src/
SRC		=	$(addprefix $(SRC_DIR), $(SOURCE))

OBJ_DIR	=	obj/
OBJ		=	$(addprefix $(OBJ_DIR), $(SOURCE:.c=.o))

ifeq ($(UNAME), Darwin)
		MLX_DIR		=	../lib/mlx_osx/
		MLX_FLAGS	=	-L $(MLX_DIR) -l mlx -framework OpenGl -framework Appkit
		INC_DIRS	=	-I./inc -I./lib/libft/inc/ -I$(MLX_DIR)
endif

ifeq ($(UNAME), Linux)
		MLX_DIR		=	./lib/mlx_linux/
		MLX_FLAGS	=	-L $(MLX_DIR) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
		INC_DIRS	= 	-I./inc/ -I./lib/libft/inc/ -I$(MLX_DIR)
endif

MLX		=	$(MLX_DIR)libmlx.a

all:		$(NAME)

$(NAME):	$(OBJ) $(LIBFT) $(MLX)
			$(CC) $(OBJ) $(CFLAGS) $(MLX_FLAGS) $(INC_DIRS) -lm $(RDL_LIB) $(LIBFT) -o $(NAME)

$(MLX):
			make -C $(MLX_DIR)

$(LIBFT):
			if [ ! -e $(LIBFT_MAKE) ]; then \
				git submodule update --init --recursive; \
			fi
			make -C ./lib/libft/

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(LIBFT)
			@mkdir -p $(@D)
			$(CC) $(CFLAGS) $(INC_DIRS) -c $< -o $@

clean:
			make clean -C ./lib/libft/
			make clean -C ./tests/
			rm -rf $(OBJ_DIR)

fclean:		clean
			make fclean -C ./lib/libft/
			make fclean -C ./tests/
			rm -f $(NAME)

re:			fclean all

.PHONY:		all, clean, fclean, re
