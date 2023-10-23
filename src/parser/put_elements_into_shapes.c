/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elements_into_shapes.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:35:23 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/23 20:05:45 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	put_element_into_sphere(t_element *element, int index, t_world *w)
{
	t_matrix	trans;
	t_matrix	scale;
	t_matrix	res;

	w->shape[index] = create_sphere();
	trans = translation(element->coordinates.x, element->coordinates.y,
			element->coordinates.z);
	scale = scaling(element->radius / 2, element->radius / 2, element->radius / 2);
	res = multiply_matrices(&trans, &scale);
	set_transform(w->shape + index, &res);
	w->shape[index].material.color = element->color;
}

static void	put_element_into_cylinder(t_element *element, int index, t_world *w)
{
	t_matrix	trans;
	t_matrix	scale;
	t_matrix	res;

	w->shape[index] = create_cylinder();
	trans = translation(element->coordinates.x, element->coordinates.y,
			element->coordinates.z);
	scale = scaling(element->radius, element->radius, element->radius);
	res = multiply_matrices(&scale, &trans);
	set_transform(w->shape + index, &res);
	w->shape[index].material.color = element->color;
	w->shape[index].cylinder.max = element->cylinder_height / 2;
	w->shape[index].cylinder.min = -element->cylinder_height / 2;
}

static void	put_element_into_plane(t_element *element, int index, t_world *w)
{
	t_matrix	trans;
	t_matrix	rotx;
	t_matrix	roty;
	t_matrix	rotz;

	w->shape[index] = create_plane();
	trans = translation(element->coordinates.x, \
		element->coordinates.y, element->coordinates.z);
	rotx = rotation_x(element->orientation.x);
	roty = rotation_y(element->orientation.y);
	rotz = rotation_z(element->orientation.z);
	set_transform(w->shape + index, &trans);
	set_transform(w->shape + index, &rotx);
	set_transform(w->shape + index, &roty);
	set_transform(w->shape + index, &rotz);
	w->shape[index].material.color = element->color;
}

void	put_elements_into_shapes(t_element *element, int index, t_world *w)
{
	if (element->element_type == ELMT_SPHERE)
		put_element_into_sphere(element, index, w);
	else if (element->element_type == ELMT_PLANE)
		put_element_into_plane(element, index, w);
	else if (element->element_type == ELMT_CYLINDER)
		put_element_into_cylinder(element, index, w);
}
