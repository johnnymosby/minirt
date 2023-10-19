/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elements_into_shapes.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:35:23 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/19 23:47:06 by aguilmea         ###   ########.fr       */
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
	scale = scaling(element->radius, element->radius, element->radius);
	res = multiply_matrices(&trans, &scale);
	set_transform(w->shape +index, &res);
	w->shape[index].sphere.radius = element->radius;
	w->shape[index].material.color = element->color;
}

static void	put_element_into_cylinder(t_element *element, int index, t_world *w)
{
	(void)element;
	(void)index;
	(void)w;
//	t_matrix	trans;
	w->shape[index] = create_cylinder();
//	w->shape[index].transform = scaling(10.00, 0.01, 10.0);
//	w->shape[index].material.color = color(1, 0.9, 0.9);
//	trans = translation(element->coordinates.x, element->coordinates.y,
//			element->coordinates.z);
//	set_transform(w->shape +index, &trans);
//	w->shape[index].cylinder.radius = element->radius;
//	w->shape[index].cylinder.radius = element->radius;
//	w->shape[index].material.color = element->color;
}

static void	put_element_into_plane(t_element *element, int index, t_world *w)
{
	t_matrix	trans;
	t_matrix	rotx;
	t_matrix	roty;
	t_matrix	rotz;
	
	w->shape[index] = create_plane();
	trans = translation(element->coordinates.x,element->coordinates.y, element->coordinates.z );
	rotx = rotation_x(element->orientation.x);
	roty = rotation_y(element->orientation.y);
	rotz = rotation_z(element->orientation.z);
	set_transform(w->shape +index, &trans);
	set_transform(w->shape +index, &rotx);
	set_transform(w->shape +index, &roty);
	set_transform(w->shape +index, &rotz);
	w->shape[index].material.color = element->color;
	//w->shape[index].material.color = color(1, 0.9, 0.9);
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
