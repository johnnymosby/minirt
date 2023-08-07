/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 00:16:18 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/08/08 00:40:22 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

Test(canvas, canvas_creation)
{
	t_canvas *c = NULL;
	int width = 10;
	int height = 20;
	t_color black = color(0, 0, 0);
	
	c = canvas(width, height);
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			cr_assert(are_equal_colors(pixel_at(c, i, j), black), "The pixel is not black");
		}
	}

	t_color red = color(1, 0, 0);
	write_pixel(c, 2, 3, red);
	cr_assert(are_equal_colors(pixel_at(c, 2, 3), red), "The pixel is not red");
}
