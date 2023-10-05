/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_canvas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 09:04:54 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/05 14:05:42 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

inline static void	correct_values(int i, int *img, t_canvas *const canvas)
{
	if (canvas->pixels[i].red > 1)
		img[i] += 255 << 16;
	else if (canvas->pixels[i].red < 0)
		((char *)img)[i + 2] = 0;
	if (canvas->pixels[i].green > 1)
		img[i] += 255 << 8;
	else if (canvas->pixels[i].green < 0)
		((char *)img)[i + 1] = 0;
	if (canvas->pixels[i].blue > 1)
		img[i] += 255;
	else if (canvas->pixels[i].blue < 0)
		((char *)img)[i] = 0;
}

void	canvas_to_mlx_image(t_canvas *const canvas, int *img)
// name of the function in the book: canvas_to_ppm
{
	int	i;

	i = 0;
	while (i < canvas->width * canvas->height)
	{
		img[i] = 0;
		if ((int)canvas->pixels[i].red >= 0 && canvas->pixels[i].red <= 1)
			img[i] += (int)(canvas->pixels[i].red * 255) << 16;
		if ((int)canvas->pixels[i].green >= 0 && canvas->pixels[i].green <= 1)
			img[i] += (int)(canvas->pixels[i].green * 255) << 8;
		if ((int)canvas->pixels[i].blue >= 0 && canvas->pixels[i].blue <= 1)
			img[i] += (int)(canvas->pixels[i].blue * 255);
		correct_values(i, img, canvas);
		i++;
	}
}
