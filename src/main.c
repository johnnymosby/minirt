/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:43:54 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/19 21:47:58 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "tuples.h"
#include "colors.h"
#include "canvas.h"
#include "X11/keysym.h"

#define ERR_MEMORY_ALLOCATION	-1
#define ERR_MLX_FUNCTION		-2

static int	escape_key(int keysym, t_win *win)
{
	if (keysym == XK_Escape)
	{
		if (win->menu.img_ptr)
			mlx_destroy_image(win->mlx_ptr, win->menu.img_ptr);
		if (win->pct.img_ptr)
			mlx_destroy_image(win->mlx_ptr, win->pct.img_ptr);
		if (win->win_ptr)
			mlx_destroy_window(win->mlx_ptr, win->win_ptr);
		mlx_loop_end(win->mlx_ptr);
	}
	return (0);
}

static int	close_button(t_win *win)
{
	if (win->menu.img_ptr)
		mlx_destroy_image(win->mlx_ptr, win->menu.img_ptr);
	if (win->pct.img_ptr)
		mlx_destroy_image(win->mlx_ptr, win->pct.img_ptr);
	if (win->win_ptr)
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	mlx_loop_end(win->mlx_ptr);
	return (0);
}

int	main(void)
{
	t_canvas	*c;
	t_win		win;
	int			width;
	int			height;
	t_color		blue;
	t_color		red;
	int			i;

	width = PCT_WIDTH;
	height = WIN_HEIGHT;
	blue = color(0, -2, 1.5);
	red = color(1, 0, 0);
	i = 0;
//	INITIALISE CANVAS WITH 2 LINES (WILL BE OUR PARSING WITH FIGURES IN FUTURE)
	c = canvas(width, height);
	if (c == NULL)
		return (ERR_MEMORY_ALLOCATION);
	i = 0;
	while (i < width)
	{
		write_pixel(c, i, 200, blue);
		i++;
	}
	i = 0;
	while (i < height)
	{
		write_pixel(c, 200, i, red);
		i++;
	}
//	INITIALISE MLX
	win = window();
	if (win.mlx_ptr == NULL)
	{
		free_canvas(c);
		return (ERR_MLX_FUNCTION);
	}
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
//	MLX HOOKS
	mlx_hook(win.win_ptr, 2, 1L << 0, &escape_key, &win);
	mlx_hook(win.win_ptr, 17, 1L << 17, &close_button, &win);
//	RENDERING IMAGE
	canvas_to_mlx_image(c, win.pct.addr);
	mlx_put_image_to_window(win.mlx_ptr, win.win_ptr, win.pct.img_ptr, 0, 0);
//	MLX LOOP
	mlx_loop(win.mlx_ptr);
//	FREE EVERYTHING
	free_canvas(c);
	mlx_destroy_display(win.mlx_ptr);
	free(win.mlx_ptr);
	return (0);
}
