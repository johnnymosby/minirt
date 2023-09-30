/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elements_into_shapes.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:35:23 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/30 20:09:47 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	put_shape_into_sphere(t_element *element, int index, t_world *w)
{
	w->shape[index] = create_sphere();
	w->shape[index].sphere.origin = element->coordinates;
	w->shape[index].sphere.radius = element->radius;
}

static void	put_shape_into_cylinder(t_element *element, int index, t_world *w)
{
	(void) element;
	(void) index;
	(void) w;
}

static void	put_shape_into_plane(t_element *element, int index, t_world *w)
{
	(void) element;
	(void) index;
	(void) w;
}

void	put_elements_into_shapes(t_element *element, int index, t_world *w)
{
	if (element->element_type == ELMT_SPHERE)
		put_shape_into_sphere(element, index, w);
	else if (element->element_type == ELMT_PLANE)
		put_shape_into_cylinder(element, index, w);
	else if (element->element_type == ELMT_CYLINDER)
		put_shape_into_plane(element, index, w);
}
