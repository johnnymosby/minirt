/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:55:59 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/09 23:45:08 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

static int	close_button(t_win *win)
{
	if (win->menu.img_ptr)
		mlx_destroy_image(win->mlx_ptr, win->menu.img_ptr);
	if (win->pct.img_ptr)
		mlx_destroy_image(win->mlx_ptr, win->pct.img_ptr);
	if (win->win_ptr)
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	// mlx_loop_end(win->mlx_ptr);
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

void	catch_mlx_hooks(t_win *window)
{
	mlx_hook(window->win_ptr, 2, 1L << 0, &escape_key, window);
	mlx_hook(window->win_ptr, 17, 1L << 17, &close_button, window);
}
