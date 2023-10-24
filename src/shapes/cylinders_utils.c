/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinders_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:18:35 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/24 16:19:28 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

t_tuple	normal_at_cylinder(t_shape *shape, t_tuple *point)
{
	double	dist;

	dist = pow(point->x, 2) + pow(point->z, 2);
	if (dist < 1 && point->y >= (shape->cylinder.max - EPSILON))
		return (vector(0, 1, 0));
	if (dist < 1 && point->y <= (shape->cylinder.min + EPSILON))
		return (vector(0, -1, 0));
	return (vector(point->x, 0, point->z));
}

t_shape	create_cylinder(void)
{
	t_shape	shape;

	set_shape_to_default(&shape);
	shape.cylinder.max = INFINITY;
	shape.cylinder.min = -INFINITY;
	shape.cylinder.closed = true;
	shape.shape_type = CYLINDER;
	shape.intersect = intersect_cylinder;
	shape.normal_at = normal_at_cylinder;
	return (shape);
}
