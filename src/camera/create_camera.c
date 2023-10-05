/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:35:55 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/05 13:29:37 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void	set_size_values(t_camera *c)
{
	float	half_view;
	double	aspect;

	half_view = tan(c->field_of_view / 2);
	if (half_view == 0.0000)
		half_view = 0.01;
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

t_camera	camera(int hsize, int vsize, double field_of_view)
{
	t_camera	c;

	c.hsize = hsize;
	c.vsize = vsize;
	c.field_of_view = field_of_view;
	c.transform = identity_matrix();
	set_size_values(&c);
	return (c);
}
