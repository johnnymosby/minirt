/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:35:55 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/23 18:22:27 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	set_size_values(t_camera *c)
{
	double	half_view;
	double	aspect;

	half_view = tanf(c->field_of_view / 2);
	aspect = (double)c->hsize / (double)c->vsize;
	if (aspect >= 1)
	{
		c->half_width = half_view;
		c->half_height = half_view / aspect;
	}
	else
	{
		c->half_width = half_view * aspect;
		c->half_height = half_view;
	}
	c->pixel_size = (c->half_width * 2 / c->hsize);
}

void	set_transform_in_camera(t_camera *camera, t_matrix *m)
{
	camera->transform = *m;
	camera->inverse = inverse(m);
}

t_camera	camera(int hsize, int vsize, double field_of_view)
{
	t_camera	c;

	c.hsize = hsize;
	c.vsize = vsize;
	c.field_of_view = field_of_view;
	c.transform = identity_matrix();
	c.original_transform = identity_matrix();
	c.inverse = inverse(&c.transform);
	set_size_values(&c);
	return (c);
}
