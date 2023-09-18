/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:48:26 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/18 21:10:03 by aguilmea         ###   ########.fr       */
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
void		free_canvas(t_canvas *c);
/*
** ------------------------------- LOGICAL OPERATIONS ------------------------
*/

bool		are_equal_images(void *const image1, void *const image2, int size);

/*
** ------------------------------- PIXELS ------------------------------------
*/

void		write_pixel(t_canvas *canvas, int x, int y, t_color color);
t_color		pixel_at(t_canvas *const canvas, int x, int y);

/*
** ------------------------------- SAVE CANVAS -------------------------------
*/

void		canvas_to_mlx_image(t_canvas *const canvas, int *img);

#endif