NAME	=	minirt

LIBFT	=	./lib/libft/libft.a

OS		=	$(shell uname)
USER	=	$(shell whoami)

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

MAIN	=	main.c

TUPLES	=	tuples.c
TUPLES	:=	$(addprefix tuples/, $(TUPLES))

SOURCE	=	$(MAIN)
SRC_DIR	=	src/
SRC		=	$(addprefix $(SRC_DIR), $(SOURCE))

OBJ_DIR	=	obj/
OBJ		=	$(addprefix $(OBJ_DIR), $(SOURCE:.c=.o))

INC_DIR	=	inc/

ifeq ($(UNAME), Darwin)
		MLX_DIR		=	lib/mlx_osx
		OFLAGS		= 	$(CFLAGS) -L $(MLX) -l mlx -framework OpenGl -framework Appkit
endif

ifeq ($(UNAME), Linux)
		MLX_DIR		= lib/mlx_linux
		OFLAGS		= 	$(CFLAGS) -L $(MLX) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
endif

all:		$(NAME)

$(NAME):	$(OBJ) $(LIBFT)
			$(CC) $(OBJ) $(CFLAGS) $(RDL_LIB) $(LIBFT) -o $(NAME)

$(LIBFT):
			make -C ./lib/libft/

$(OBJ): $(SRC)
			@mkdir -p $(@D)
			$(CC) -c $< -o $@ -I $(INC_DIR)

clean:
			make clean -C ./lib/libft/
			rm -rf $(OBJ_DIR)

fclean:		clean
			make fclean -C ./lib/libft/
			rm -f $(NAME)

re:			fclean all

.PHONY:		all, clean, fclean, re