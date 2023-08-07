/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:48:26 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/08/08 00:37:39 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# include "colors.h"
# include "tuples.h"

typedef struct s_canvas {
	int		width;
	int		height;
	t_color	*pixels;
}	t_canvas;

/*
** ------------------------------- CREATE CANVAS -----------------------------
*/

t_canvas	*canvas(int width, int height);

/*
** ------------------------------- PIXELS ------------------------------------
*/

void		write_pixel(t_canvas *canvas, int x, int y, t_color color);
t_color		pixel_at(t_canvas *canvas, int x, int y);

#endif