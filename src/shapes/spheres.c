/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:55:05 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/24 16:17:25 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

static void	discriminant(t_sphere *sphere, t_ray *r, t_disc_calc *d_calc)
{
	t_tuple	sphere_to_ray;

	sphere_to_ray = substract_tuples(&r->origin, &sphere->origin);
	d_calc->a = dot(&r->direction, &r->direction);
	d_calc->b = 2 * dot(&r->direction, &sphere_to_ray);
	d_calc->c = dot(&sphere_to_ray, &sphere_to_ray) - 1;
	d_calc->dscr = d_calc->b * d_calc->b - 4 * d_calc->a * d_calc->c;
}

void	intersect_sphere(t_shape *shape, t_ray *r, t_hit **hits)
{
	t_disc_calc	d_calc;
	double		d_squared;
	double		t[2];

	discriminant(&shape->sphere, r, &d_calc);
	if (d_calc.dscr > 0 || are_equal_doubles(d_calc.dscr, 0))
	{
		d_squared = sqrt(d_calc.dscr);
		t[0] = (-d_calc.b - d_squared) / (2 * d_calc.a);
		t[1] = (-d_calc.b + d_squared) / (2 * d_calc.a);
		add_intersection(hits, intersection(t[0], shape));
		add_intersection(hits, intersection(t[1], shape));
	}
}

t_shape	create_sphere(void)
{
	t_shape	shape;
	t_tuple	null_point;

	set_shape_to_default(&shape);
	null_point = point(0, 0, 0);
	shape.sphere.origin = null_point;
	shape.sphere.null_point = null_point;
	shape.sphere.radius = 1;
	shape.shape_type = SPHERE;
	shape.intersect = intersect_sphere;
	shape.normal_at = normal_at_sphere;
	return (shape);
}

t_tuple	normal_at_sphere(t_shape *shape, t_tuple *point)
{
	t_tuple	object_normal;

	object_normal = substract_tuples(point, &shape->sphere.null_point);
	object_normal.w = 0;
	return (normalize(&object_normal));
}
