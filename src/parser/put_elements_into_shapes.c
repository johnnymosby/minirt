/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elements_into_shapes.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:35:23 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/24 12:43:26 by rbasyrov         ###   ########.fr       */
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
	set_transform(w->shape + index, &res);
	w->shape[index].material.color = element->color;
}

static void	calculate_angles(t_tuple *direction, double *x, double *z)
{
	double	x_projection;

	x_projection = sqrt((direction->z * direction->z)
			+ (direction->y * direction->y));
	*z = acos(x_projection);
	if ((direction->z * direction->y) > 0)
		*z = acos(x_projection);
	else if ((direction->z * direction->y) < 0)
		*z = acos(x_projection) + M_PI_2;
	if (are_equal_doubles(x_projection, 0))
		*x = M_PI_2;
	else
		*x = acos(direction->y / x_projection);
}

t_matrix	calculate_rotation(t_tuple *direction)
{
	double		x_angle;
	double		z_angle;
	t_matrix	m_rotated_z;
	t_matrix	m_rotated_x;

	calculate_angles(direction, &x_angle, &z_angle);
	m_rotated_z = rotation_z(z_angle);
	m_rotated_x = rotation_x(x_angle);
	return (multiply_matrices(&m_rotated_x, &m_rotated_z));
}

static void	put_element_into_cylinder(t_element *element, int index, t_world *w)
{
	t_matrix	trans;
	t_matrix	scale;
	t_matrix	rotation;
	t_matrix	res;

	w->shape[index] = create_cylinder();
	trans = translation(element->coordinates.x, element->coordinates.y,
			element->coordinates.z);
	scale = scaling(element->radius, element->radius, element->radius);
	rotation = calculate_rotation(&element->orientation);
	res = multiply_matrices(&scale, &rotation);
	res = multiply_matrices(&trans, &res);
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
