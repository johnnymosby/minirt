/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:55:05 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/21 15:12:08 by rbasyrov         ###   ########.fr       */
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

t_hit	intersect_sphere(t_shape *shape, t_ray *r)
{
	t_hit		hit;
	t_disc_calc	d_calc;
	double		d_squared;

	discriminant(&shape->sphere, r, &d_calc);
	hit.count = 0;
	if (d_calc.dscr < 0)
		return (hit); //to change to pointer when return value of the function's signature is changed
	else
	{
		d_squared = sqrt(d_calc.dscr);
		hit.t[0] = (-d_calc.b - d_squared) / (2 * d_calc.a);
		hit.t[1] = (-d_calc.b + d_squared) / (2 * d_calc.a);
	}
	if (are_equal_doubles(d_calc.dscr, 0) == true)
		hit.count = 1;
	else
		hit.count = 2;
	hit.obj = shape;
	return (hit);
}

t_shape	create_sphere(void)
{
	t_shape	shape;

	shape.sphere.origin = point(0, 0, 0);
	shape.sphere.radius = 1;
	shape.shape_type = SPHERE;
	return (shape);
}
