/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_computation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:24:21 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/12 12:38:04 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computations.h"

static void	calculate_over_point(t_comp *comps)
{
	t_tuple		product;

	product = multiply_tuple_by_scalar(&comps->normalv, EPSILON);
	comps->over_point = add_tuples(&comps->point, &product);
}	

t_comp	prepare_computations(t_hit *intersection, t_ray *ray)
{
	t_comp	comps;

	ft_bzero(&comps, sizeof(t_comp));
	comps.t = intersection->t;
	comps.object = intersection->obj;
	comps.point = position(ray, comps.t);
	comps.eyev = negate_tuple(&ray->direction);
	comps.normalv = comps.object->normal_at(comps.object, &comps.point);
// normal_at will be refactored for all shapesin chapter 9
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
