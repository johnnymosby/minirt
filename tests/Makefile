NAME		=	tests

TESTS		=	tuples.c

SRC_DIR		=	../src
OBJ_DIR		=	../obj
LIBFT_DIR 	=	../lib/libft/
LIBFT		=	../lib/libft/libft.a

UNAME		=	$(shell uname -s)

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

CRITERION	=	-lcriterion -I/Users/johnnymosby/.brew/Cellar/criterion/2.4.1_2/include/ \
				-L/Users/johnnymosby/.brew/Cellar/criterion/2.4.1_2/lib/

ifeq ($(UNAME), Darwin)
		MLX_DIR		=	../lib/mlx_osx/
		MLX_FLAGS	=	-L $(MLX_DIR) -l mlx -framework OpenGl -framework Appkit
		INC_DIRS	=	-I../inc/ -I../lib/libft/inc/ -I$(MLX_DIR)
endif

ifeq ($(UNAME), Linux)
		MLX_DIR		=	../lib/mlx_linux/
		MLX_FLAGS	=	-lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
		INC_DIRS	= 	-I../inc/ -I../lib/libft/inc/ -I$(MLX_DIR)
endif


MLX			=	$(MLX_DIR)libmlx.a

SOURCE = $(shell find $(SRC_DIR) -name '*.c')
SOURCE := $(filter-out $(SRC_DIR)/main.c, $(SOURCE))

$(LIBFT):
			make -C $(LIBFT_DIR)

OBJ		= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCE))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
			@mkdir -p $(@D)
			$(CC) $(CFLAGS) $(INC_DIRS) -c $< -o $@

$(MLX):
			make -C $(MLX_DIR)

define compile
 	$(CC) $(CFLAGS) $^ $(LIBFT) $(MLX_FLAGS) $(CRITERION) $(INC_DIRS) -o $@ && ./$@ --verbose
endef

# -------------------------------- TESTS ------------------------------------- #

all: $(TESTS) clean

echo_wow: $(SOURCE) $(OBJ)
	echo $(SOURCE)
	echo $(OBJ)

tuples: $(OBJ) $(LIBFT) $(MLX) tuples.c
	@$(call compile, "$^")

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)
	@rm -f $(patsubst %.c,%,$(TESTS))

fclean: clean
	make clean -C $(MLX_DIR)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re tuples