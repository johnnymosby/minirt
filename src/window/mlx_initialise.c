/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initialise.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:13:02 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/23 17:14:27 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "camera.h"

int	initialise_mlx(t_scene *sc, t_win *w)
{
	sc->canvas->win = w;
	*w = window();
	if (sc->canvas->win->mlx_ptr == NULL)
		return (print_error(NULL, -1, ERR_MLX_WIN, 0));
	if (initialise_picture(sc->canvas->win) == false)
		return (print_error(NULL, -1, ERR_MLX_WIN, 0));
	if (initialise_menu(sc->canvas->win) == false)
		return (print_error(NULL, -1, ERR_MLX_MENU, 0));
	return (0);
}
