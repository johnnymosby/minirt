/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:55:59 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/12 17:23:34 by rbasyrov         ###   ########.fr       */
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

//change so that when tanf changes sign the picture is not swapped
int	mouse_hook(int keycode, int x, int y, t_controls *controls)
{
	t_scene	*scene;

	scene = controls->scene;
	(void)x;
	(void)y;
	if (keycode == KEY_ZOOM_IN || keycode == KEY_ZOOM_OUT)
	{
		if (controls->control_state == CAMERA)
			change_camera_zoom(keycode, scene);
		else if (controls->control_state == SHAPE)
			change_shape_size(keycode, controls);
	}
	if (keycode == LEFT_CLICK)
		respond_to_left_click(controls, x, y);
	if (keycode == RIGHT_CLICK)
		respond_to_right_click(controls);
	return (0);
}
