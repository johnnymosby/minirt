/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initialise.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:13:02 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/23 18:28:42 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

bool	initialise_mlx(t_win *win)
{	
	*win = window();
	if (win->mlx_ptr == NULL)
		return (false);
	if (initialise_picture(win) == false)
		return (false);
	if (initialise_menu(win) == false)
		return (false);
	return (true);
}