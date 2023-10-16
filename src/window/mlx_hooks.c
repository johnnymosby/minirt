/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:55:59 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/16 12:00:33 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "window.h"

static int	close_button(t_win *window)
{
	mlx_loop_end(window->mlx_ptr);
	return (0);
}

static int	escape_key(int keysym, t_win *window)
{
	if (keysym == KEY_ESC)
		mlx_loop_end(window->mlx_ptr);
	return (0);
}

void	catch_close_hooks(t_win *window)
{
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
