/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:09:40 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/21 15:25:24 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

Test(spheres, intersect_at_two_points)
{
	t_tuple	p = point(0, 0, -5);
	t_tuple	v = vector(0, 0, 1);
	t_ray r = ray(&p, &v);
	t_shape sph = create_sphere();
	t_hit xs = intersect_sphere(&sph, &r);

	cr_assert(xs.count == 2);
	cr_assert(are_equal_doubles(xs.t[0], 4.0));
	cr_assert(are_equal_doubles(xs.t[1], 6.0));
}

Test(spheres, intersect_at_tangent)
{
	t_tuple	p = point(0, 1, -5);
	t_tuple	v = vector(0, 0, 1);
	t_ray r = ray(&p, &v);
	t_shape sph = create_sphere();
	t_hit xs = intersect_sphere(&sph, &r);

	cr_assert(xs.count == 1);
	cr_assert(are_equal_doubles(xs.t[0], 5.0));
	cr_assert(are_equal_doubles(xs.t[1], 5.0));
}

Test(spheres, no_intersect)
{
	t_tuple	p = point(0, 2, -5);
	t_tuple	v = vector(0, 0, 1);
	t_ray r = ray(&p, &v);
	t_shape sph = create_sphere();
	t_hit xs = intersect_sphere(&sph, &r);

	cr_assert(xs.count == 0);
}

Test(spheres, ray_originates_inside_sphere)
{
	t_tuple	p = point(0, 0, 0);
	t_tuple	v = vector(0, 0, 1);
	t_ray r = ray(&p, &v);
	t_shape sph = create_sphere();
	t_hit xs = intersect_sphere(&sph, &r);

	cr_assert(xs.count == 2);
	cr_assert(are_equal_doubles(xs.t[0], -1.0));
	cr_assert(are_equal_doubles(xs.t[1], 1.0));
}

Test(spheres, ray_is_behind_sphere)
{
	t_tuple	p = point(0, 0, 5);
	t_tuple	v = vector(0, 0, 1);
	t_ray r = ray(&p, &v);
	t_shape sph = create_sphere();
	t_hit xs = intersect_sphere(&sph, &r);

	cr_assert(xs.count == 2);
	cr_assert(are_equal_doubles(xs.t[0], -6.0));
	cr_assert(are_equal_doubles(xs.t[1], -4.0));
}

Test(spheres, intersection_encapsulates_t_and_object)
{
	t_shape sph = create_sphere();
	t_intrs i = intersection(3.5, &sph);

	cr_assert(are_equal_doubles(i.t, 3.5));
	cr_assert(i.obj->shape_type == SPHERE);
}
