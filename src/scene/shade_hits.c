/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_hits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:14:35 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/11 15:27:59 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computations.h"
/*
static t_tuple	adjust_point_to_mitigate_acne_effect(t_comp *comps)
{
	t_tuple	normalv_by_epsilon;

	normalv_by_epsilon = multiply_tuple_by_scalar(&comps->normalv, EPSILON);
	return (add_tuples(&comps->point, &normalv_by_epsilon));
}*/

t_color	shade_hit(t_world *world, t_comp *comps)
{
	t_lightning	l;

	ft_bzero(&l, sizeof(t_lightning));
	//comps->over_point = adjust_point_to_mitigate_acne_effect(comps);
	l.in_shadow = is_shadowed(world, &comps->over_point);
	l.material = &comps->object.material;
	l.light = world->lights;
	l.point = &comps->over_point;
	l.eyev = &comps->eyev;
	l.normalv = &comps->normalv;
	return (lightning(&l));
}

t_color	color_at(t_world *w, t_ray *r)
{
	t_color	col;
	t_hit	*h;
	t_comp	comps;

	intersect_world(w, r);
	h = hit(w->xs, true);
	if (h == NULL)
	{
		col = color(0, 0, 0);
	}
	else
	{
		comps = prepare_computations(h, r);
		col = shade_hit(w, &comps);
	}
	return (col);
}
