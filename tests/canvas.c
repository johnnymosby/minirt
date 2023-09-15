/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 00:16:18 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/15 13:53:07 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

#define RED_MULT	65536
#define GREEN_MULT	256
#define BLUE_MULT	1

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
Test(canvas, mlx_img_creation)
{
	t_canvas *c = canvas(15,10);
	void *img = NULL;
	
	int tab[150];// 60 = 5 * 3 * sizeof(int)
	ft_bzero(tab, 600);

	tab[0] = 255 * RED_MULT;// 2 = indice red
	t_color c1 = color(1, 0, 0);
	write_pixel(c, 0, 0, c1);
	img = canvas_to_mlx_image(c);
	cr_assert(are_equal_images(img, tab, 600), "first pixel one color failed");

	tab[0] += 25 * GREEN_MULT;
	c1 = color(1, 0.1, 0);
	write_pixel(c, 0, 0, c1);
	img = canvas_to_mlx_image(c);
	cr_assert(are_equal_images(img, tab, 600), "first pixel 2 colors failed");
	
	tab[0] += 127 * BLUE_MULT;
	c1 = color(1, 0.1, 0.5);
	write_pixel(c, 0, 0, c1);
	img = canvas_to_mlx_image(c);
	cr_assert(are_equal_images(img, tab, 600), "first pixel 3 colors failed");
}

Test(canvas, mlx_img_values_outside_range)
{
	t_canvas *c = canvas(15,10);
	void *img = NULL;
	int tab[150];// 60 = 5 * 3 * sizeof(int)

	ft_bzero(tab, 600);

	tab[10] = 255 * RED_MULT;// 2 = indice red
	tab[10] += 255 * GREEN_MULT;// 1 = green
	tab[10] += 255 * BLUE_MULT; // 0 = blue
	t_color c2 = color(1.2, 2, 3.1);
	write_pixel(c, 10, 0, c2);
	img = canvas_to_mlx_image(c);
	cr_assert(are_equal_images(img, tab, 600), "pixel over range 1 failed");

	tab[30] = 255 * RED_MULT;// 2 = indice red
	tab[30] += 255 * GREEN_MULT;// 1 = green
	tab[30] += 255 * BLUE_MULT; // 0 = blue
	t_color c3 = color(1, 1, 1);
	write_pixel(c, 0, 2, c3);
	img = canvas_to_mlx_image(c);
	cr_assert(are_equal_images(img, tab, 600), "colors under range 0 failed");
}