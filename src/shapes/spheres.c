/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:55:05 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/02 17:20:35 by rbasyrov         ###   ########.fr       */
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
	t_hit		*intrs[2];

	discriminant(&shape->sphere, r, &d_calc);
	if (d_calc.dscr >= 0)
	{
		d_squared = sqrt(d_calc.dscr);
		t[0] = (-d_calc.b - d_squared) / (2 * d_calc.a);
		t[1] = (-d_calc.b + d_squared) / (2 * d_calc.a);
		intrs[0] = intersection(t[0], shape);
		intrs[1] = intersection(t[1], shape);
		intrs[0]->left = intrs[1];
		intrs[1]->prev = intrs[0];
		add_intersection(hits, intrs[0]);
		add_intersection(hits, intrs[1]);
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
	return (shape);
}

t_tuple	normal_at_sphere(t_shape *shape, t_tuple *point)
{
	t_tuple	object_point;
	t_tuple	object_normal;
	t_tuple	world_normal;
	t_tuple	world_normal_normalized;

	object_point = multiply_matrix_by_tuple(&shape->inverse, point);
	object_normal = substract_tuples(&object_point, &shape->sphere.null_point);
	world_normal = multiply_matrix_by_tuple(&shape->transpose, &object_normal);
	world_normal.w = 0;
	world_normal_normalized = normalize(&world_normal);
	return (world_normal_normalized);
}
