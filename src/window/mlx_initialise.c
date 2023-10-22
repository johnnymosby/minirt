/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initialise.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:13:02 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/22 13:02:41 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

int	initialise_mlx(t_win *win)
{
	*win = window();
	if (win->mlx_ptr == NULL)
		return (print_error(NULL, -1, ERR_MLX_WIN, 0));
	if (initialise_picture(win) == false)
		return (print_error(NULL, -1, ERR_MLX_WIN, 0));
	if (initialise_menu(win) == false)
		return (print_error(NULL, -1, ERR_MLX_MENU, 0));
	return (0);
}
