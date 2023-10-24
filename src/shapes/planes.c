/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:35:50 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/24 14:34:59 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

static void	intersect_plane(t_shape *shape, t_ray *r, t_hit **hits)
{
	double	t;

	if (fabs(r->direction.y) < EPSILON)
		return ;
	t = -r->origin.y / r->direction.y;
	add_intersection(hits, intersection(t, shape));
	return ;
}

static t_tuple	normal_at_plane(t_shape *shape, t_tuple *point)
{
	(void) shape;
	(void) point;
	return (vector(0, 1, 0));
}

t_shape	create_plane(void)
{
	t_shape	shape;

	set_shape_to_default(&shape);
	shape.shape_type = PLANE;
	shape.intersect = intersect_plane;
	shape.normal_at = normal_at_plane;
	return (shape);
}
