/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:50:03 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/11 12:08:06 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

bool	render(t_scene *scene)
{
	t_camera	*c;
	int			x;
	int			y;
	t_ray		r;
	t_color		color;

	c = &scene->camera;
	if (scene->canvas == NULL)
		scene->canvas = canvas(c->hsize, c->vsize);
	if (scene->canvas == NULL)
		return (false);
	y = 0;
	while (y < c->vsize)
	{
		x = 0;
		while (x < c->hsize)
		{
			r = ray_for_pixel(c, x, y);
			color = color_at(scene->world, &r);
			write_pixel(scene->canvas, x, y, color);
			x++;
		}
		y++;
	}
	return (true);
}
