TESTS	=	tuples.c

SRC_DIR   := ../src
OBJ_DIR   := ../obj
LIBFT_DIR := ../lib/libft

UNAME	=	$(shell uname -s)

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

ifeq ($(UNAME), Darwin)
		MLX_DIR		=	../lib/mlx_osx
		OFLAGS		= 	-L $(MLX_DIR) -l mlx -framework OpenGl -framework Appkit
endif

ifeq ($(UNAME), Linux)
		MLX_DIR		:= ../lib/mlx_linux
		OFLAGS		= 	-L $(MLX_DIR) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
endif

INC_DIRS  := ../include $(LIBFT_DIR) $(MLX_DIR)

SOURCE = $(shell find $(SRC_DIR) -name '*.c' -exec basename {} \;)
SOURCE := $(filter-out main.c, $(SOURCE))

OBJS	= $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

define compile
 	$(CC) $(CFLAGS) $^ $(OFLAGS) -L $(LIBFT_DIR) -o $@ && ./$@ --verbose
endef

# -------------------------------- TESTS ------------------------------------- #

all: $(TESTS) clean

tuples: $(OBJS) tuples.c
	@$(call compile, "$^")

clean:
	@rm -rf $(TESTS)

fclean: clean

re: fclean all

.PHONY: all clean fclean re tuples