#include "window.h"
#include "tuples.h"
#include "colors.h"
#include "canvas.h"

#define	ERR_MEMORY_ALLOCATION	-1
#define	ERR_MLX_FUNCTION		-2

int	main(void)
{
	t_canvas 	*c = NULL;
	int 		width = 500;
	int 		height = 1000;
	t_color		blue = color(0, 0, 1);
	t_color		red = color(1, 0, 0);
	int			i = 0;

//	INITIALISE CANVAS WITH 2 LINES (WILL BE OUR PARSING WITH FIGURES IN FUTURE)
	c = canvas(width, height);
	if (c == NULL)
		return (ERR_MEMORY_ALLOCATION);
	i = 0;
	while (i < width)
	{
		write_pixel(c, i, 50, blue);
		i++;	
	}
	i = 0;
	while (i < height)
	{
		write_pixel(c, 50, i, red);
		i++;
	}

//	INITIALISE MLX	
	t_win win = window();
	if (initialise_picture(&win) == false)
	{
		free_canvas(c);
		return (ERR_MLX_FUNCTION);
	}
	if (initialise_menu(&win) == false)
	{
		free_canvas(c);
		return (ERR_MLX_FUNCTION);
	}
	
//	FREE EVERYTHING
	free_canvas(c);
	free_mlx_memory(&win);
	return (0);
}