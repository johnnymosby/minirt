/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:55:59 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/12 14:47:39 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "window.h"

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

static int	escape_key(int keysym, t_win *win)
{
	if (keysym == KEY_ESC)
		close_button(win);
	if (keysym == KEY_PLUS)
		printf("+\n");
	if (keysym == KEY_MINUS)
		printf("-\n");
	if (keysym == KEY_UP)
		printf("Up\n");
	if (keysym == KEY_DOWN)
		printf("Down\n");
	if (keysym == KEY_LEFT)
		printf("Left\n");
	if (keysym == KEY_RIGHT)
		printf("Right\n");
	return (0);
}


// static int	key_hook(int keycode, t_win *win)
// {
// 	if (keycode == KEY_ESC)
// 		escape_key(keycode, win);
// 	return (0);
// }


void	catch_mlx_hooks(t_win *window)
{
	// mlx_key_hook(window->win_ptr, key_hook, window);
	mlx_hook(window->win_ptr, 2, 1L << 0, &escape_key, window);
	mlx_hook(window->win_ptr, 17, 1L << 17, &close_button, window);
}

static void	rerender(t_scene *scene)
{
	size_t		canvas_size;
	t_canvas	*canvas;

	canvas = scene->canvas;
	canvas_size = canvas->width * canvas->height * sizeof(t_color);
	ft_bzero(canvas->pixels, canvas_size);
	set_size_values(&scene->camera);
	render(scene);
	canvas_to_mlx_image(canvas, canvas->win->pct.addr);
	mlx_put_image_to_window(canvas->win->mlx_ptr, canvas->win->win_ptr,
		canvas->win->pct.img_ptr, 0, 0);
}

//change so that when tanf changes sign the picture is not swapped
int	mouse_hook(int keycode, int x, int y, t_scene *scene)
{
	(void)x;
	(void)y;
	if (keycode == KEY_ZOOM_IN && scene->camera.field_of_view > -2.85)
	{
		scene->camera.field_of_view /= 1.1;
		rerender(scene);
	}
	else if (keycode == KEY_ZOOM_OUT
		&& scene->camera.field_of_view < 2.85)
	{
		scene->camera.field_of_view *= 1.1;
		rerender(scene);
	}
	return (0);
}
