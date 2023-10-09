/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:50:03 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/09 12:55:22 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_canvas	*render(t_camera *c, t_world *w)
{
	t_canvas	*image;
	int			x;
	int			y;
	t_ray		r;
	t_color		color;

	image = canvas(c->hsize, c->vsize);
	if (image == NULL)
		return (NULL);
	y = 0;
	while (y < c->vsize)
	{
		x = 0;
		while (x < c->hsize)
		{
			r = ray_for_pixel(c, x, y);
			color = color_at(w, &r);
			write_pixel(image, x, y, color);
			x++;
		}
		y++;
	}
	return (image);
}
