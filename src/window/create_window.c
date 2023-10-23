/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 12:58:41 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/23 18:31:09 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

static void	free_mlx_memory(t_win *window)
{
	if (window == NULL)
		return ;
	if (window->menu.img_ptr)
		mlx_destroy_image(window->mlx_ptr, window->menu.img_ptr);
	if (window->pct.img_ptr)
		mlx_destroy_image(window->mlx_ptr, window->pct.img_ptr);
	if (window->win_ptr)
		mlx_destroy_window(window->mlx_ptr, window->win_ptr);
	if (window->mlx_ptr)
	{
		//mlx_destroy_display(window->mlx_ptr);
		free(window->mlx_ptr);
		window->mlx_ptr = NULL;
	}
	window = NULL;
	return ;
}

/*
*	creates a MLX ptr and a window ptr
*	exits on errors
*/
t_win	window(void)
{
	t_win	window;

	ft_bzero(&window, sizeof(t_win));
	window.mlx_ptr = mlx_init();
	if (window.mlx_ptr == NULL)
		return (window); // print_error in an error.h src/error/error.c?
	window.win_ptr = mlx_new_window(window.mlx_ptr, MENU_WIDTH + PCT_WIDTH, \
		WIN_HEIGHT, "MiniRT");
	if (window.win_ptr == NULL)
	{
		//mlx_destroy_display(window.mlx_ptr);
		free(window.mlx_ptr);
		window.mlx_ptr = NULL;
		ft_bzero(&window, sizeof(t_win));
		return (window); /// print_error in an error.h src/error/error.c?
	}
	return (window);
}

/*
	returns false if mlx_new_image fails (t_win has been correctly freed)
*/
bool	initialise_picture(t_win *window)
{
	t_image	pct;

	ft_bzero(&pct, sizeof(t_image));
	pct.img_ptr = mlx_new_image(window->mlx_ptr, PCT_WIDTH, WIN_HEIGHT);
	if (pct.img_ptr == NULL)
	{
		free_mlx_memory(window);
		return (false);
	}
	pct.addr = mlx_get_data_addr(pct.img_ptr, \
		&(pct.bpp), &(pct.line_len), &(pct.endian));
	window->pct = pct;
	return (true);
}

/*
	returns false if mlx_new_image fails (t_win has been correctly freed)
*/
bool	initialise_menu(t_win *window)
{
	t_image	menu;

	ft_bzero(&menu, sizeof(t_image));
	menu.img_ptr = mlx_new_image(window->mlx_ptr, MENU_WIDTH, WIN_HEIGHT);
	if (menu.img_ptr == NULL)
	{
		free_mlx_memory(window);
		return (false);
	}
	menu.addr = mlx_get_data_addr(menu.img_ptr, \
		&(menu.bpp), &(menu.line_len), &(menu.endian));
	window->menu = menu;
	return (true);
}
