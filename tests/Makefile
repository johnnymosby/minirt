TESTS		=	tuples.c simple.c

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
		MLX_DIR		=	../lib/mlx_osx
		MLX			=	-L $(MLX_DIR) -l mlx -framework OpenGl -framework Appkit
		INC_DIRS	= -I../inc/ -I../lib/libft/inc/ -I$(MLX_DIR)
endif

ifeq ($(UNAME), Linux)
		MLX_DIR		=	../lib/mlx_linux
		MLX			=	-L $(MLX_DIR) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
		INC_DIRS	= -I../inc/ -I../lib/libft/inc/ -I$(MLX_DIR)
endif

SOURCE = $(shell find $(SRC_DIR) -name '*.c' -exec basename {} \;)
SOURCE := $(filter-out main.c, $(SOURCE))

$(LIBFT):
			make -C $(LIBFT_DIR)

OBJ		= $(addprefix $(OBJ_DIR)/, $(SOURCE:.c=.o))
$(OBJ): $(SOURCE)
			@mkdir -p $(@D)
			$(CC) $(CFLAGS) $(OFLAGS) $(LIBFT) $(CRITERION) -c $< -o $@ -I $(INC_DIRS)

define compile
 	$(CC) $(CFLAGS) $^ $(OFLAGS) $(LIBFT) $(CRITERION) $(INC_DIRS) -o $@ && ./$@ --verbose
endef

# -------------------------------- TESTS ------------------------------------- #

all: $(TESTS) clean

simple: $(OBJ) $(LIBFT) simple.c
	@$(call compile, "$^")

clean:
	make clean -C $(LIBFT_DIR)
	@rm -f $(patsubst %.c,%,$(TESTS))

wow:
	$(CC) $(CFLAGS) simple.c $(OFLAGS) $(LIBFT_DIR) -I $(INC_DIRS) -o simple && ./simple --verbose

fclean: clean
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re tuples