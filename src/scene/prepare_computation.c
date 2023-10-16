/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_computation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:24:21 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/16 23:44:12 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computations.h"

static void	calculate_over_point(t_comp *comps)
{
	t_tuple		product;

	product = multiply_tuple_by_scalar(&comps->normalv, EPSILON);
	comps->over_point = add_tuples(&comps->point, &product);
}	

static t_tuple	normal_at(t_shape *shape, t_tuple *point)
{
	t_tuple		local_point;
	t_tuple		local_normal;
	t_tuple		world_normal;

	local_point = multiply_matrix_by_tuple(&shape->inverse, point);
	local_normal = shape->normal_at(shape, &local_point);
	world_normal = multiply_matrix_by_tuple(&shape->transform, &local_normal);
	world_normal.w = 0.0;
	return (normalize(&world_normal));
}

t_comp	prepare_computations(t_hit *intersection, t_ray *ray)
{
	t_comp	comps;

	ft_bzero(&comps, sizeof(t_comp));
	comps.t = intersection->t;
	comps.object = intersection->obj;
	comps.point = position(ray, comps.t);
	comps.eyev = negate_tuple(&ray->direction);
	comps.normalv = normal_at(comps.object, &comps.point);
	if (dot(&comps.normalv, &comps.eyev) < 0.0)
	{
		comps.inside = true;
		comps.normalv = negate_tuple(&comps.normalv);
	}
	else
		comps.inside = false;
	calculate_over_point(&comps);
	return (comps);
}
