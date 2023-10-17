/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 00:01:33 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/17 14:03:13 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

void	write_pixel(t_canvas *canvas, int x, int y, t_color color)
{
	canvas->pixels[x + y * canvas->width] = color;
}

t_color	pixel_at(t_canvas *canvas, int x, int y)
{
	return (canvas->pixels[x + y * canvas->width]);
}
