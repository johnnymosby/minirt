NAME	=	minirt

LIBFT	=	./lib/libft/libft.a

OS		=	$(shell uname)
USER	=	$(shell whoami)

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

MAIN	=	main.c

TUPLES	=	create_tuples.c logical_operations.c arithmetic_operations.c \
			vectors_manipulation.c
TUPLES	:=	$(addprefix tuples/, $(TUPLES))

SOURCE	=	$(MAIN)
SRC_DIR	=	src/
SRC		=	$(addprefix $(SRC_DIR), $(SOURCE))

OBJ_DIR	=	obj/
OBJ		=	$(addprefix $(OBJ_DIR), $(SOURCE:.c=.o))


ifeq ($(UNAME), Darwin)
		MLX_DIR		=	../lib/mlx_osx/
		MLX_FLAGS	=	-L $(MLX_DIR) -l mlx -framework OpenGl -framework Appkit
		INC_DIRS	= -I ../inc/ -I../lib/libft/inc/ -I $(MLX_DIR)
endif

ifeq ($(UNAME), Linux)
		MLX_DIR		=	../lib/mlx_linux/
		MLX_FLAGS	=	-L $(MLX_DIR) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
		INC_DIRS		= 	-I../inc/ -I../lib/libft/inc/ -I$(MLX_DIR)
endif

MLX		=	$(MLX_DIR)libmlx.a

all:		$(NAME)

$(NAME):	$(OBJ) $(LIBFT)
			$(CC) $(OBJ) $(CFLAGS) $(RDL_LIB) $(LIBFT) -o $(NAME)

$(LIBFT):
			make -C ./lib/libft/

$(OBJ): $(SRC)
			@mkdir -p $(@D)
			$(CC) -c $< -o $@ $(INC_DIRS)

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