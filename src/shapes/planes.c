/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:35:50 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/12 17:18:14 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

static void	intersect_plane(t_shape *shape, t_ray *r, t_hit **hits)
{
	double	t;

	(void) hits;
	if (fabs(r->direction.y) < EPSILON)
		return ;
	t = -r->origin.y / r->direction.y;
	intersection(t, shape);
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
	shape.intersect = intersect_plane;
	shape.normal_at = normal_at_plane;
	//shape.cylinder.max = INFINITY;
	//shape.cylinder.min = -INFINITY;
	//shape.cylinder.closed = false;
	return (shape);
}