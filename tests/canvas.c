/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 00:16:18 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/11 21:02:29 by aguilmea         ###   ########.fr       */
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
Test(canvas, mlx_img_creation)
{
	t_canvas *c = canvas(5,3);
	void *img = NULL;
	
	char str[60];// 60 = 5 * 3 * sizeof(int)

	ft_bzero(str, 60);

	str[0 + 2] = 255;// 1 = indice red
	t_color c1 = color(1, 0, 0);
	write_pixel(c, 0, 0, c1);
	img = canvas_to_mlx_image(c);
	printf("1-%X-\n", *((int *)img));
	cr_assert(are_equal_images(img, str, 60), "first pixel one color failed");

	str[0 + 1] = 127;// green
	str[0 + 0] = 25;//blue
	c1 = color(1, 0.5, 0.1);
	write_pixel(c, 0, 0, c1);
	img = canvas_to_mlx_image(c);
	printf("2-%X-\n", *((int *)img));
	cr_assert(are_equal_images(img, str, 60), "first pixel multiple colors failed");

	str[5] = 255; //red 
	t_color c2 = color(1, 0, 0);
	write_pixel(c, 1, 0, c2);
	img = canvas_to_mlx_image(c);
	printf("3-%s-\n", (char *)img);
	cr_assert(are_equal_images(img, str, 60), "color in second pixel failed");
	
	t_color c3 = color(0, 0, 1);
	write_pixel(c, 4, 2, c3);
	c1 = color(1.5, 0, 0);
	c2 = color(0, 0.5, 0);
	c3 = color(-0.5, 0, 1);
	write_pixel(c, 0, 0, c1);
	write_pixel(c, 2, 1, c2);
	write_pixel(c, 4, 2, c3);

	img = canvas_to_mlx_image(c);
	cr_assert(are_equal_images(img, str, 60), "The mlx image is not the same as the canvas (colors out of range)");
}