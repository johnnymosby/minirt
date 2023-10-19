/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elements_into_shapes.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:35:23 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/18 18:47:57 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	put_element_into_sphere(t_element *element, int index, t_world *w)
{
	//t_matrix	trans;
	(void)element;
	w->shape[index] = create_sphere();
//	trans = translation(element->coordinates.x, element->coordinates.y,
//			element->coordinates.z);
//	set_transform(w->shape +index, &trans);
//	w->shape[index].sphere.radius = element->radius;
//	w->shape[index].material.color = element->color;
}

static void	put_element_into_cylinder(t_element *element, int index, t_world *w)
{
//	t_matrix	trans;
	w->shape[index] = create_cylinder();
	(void)element;
//	trans = translation(element->coordinates.x, element->coordinates.y,
//			element->coordinates.z);
//	set_transform(w->shape +index, &trans);
//	w->shape[index].cylinder.radius = element->radius;
//	w->shape[index].cylinder.radius = element->radius;
//	w->shape[index].material.color = element->color;
}

static void	put_element_into_plane(t_element *element, int index, t_world *w)
{
	//w->shape[index] = create_plane();
	w->shape[index].cylinder.origin = element->coordinates;
	w->shape[index].cylinder.radius = element->radius;
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
