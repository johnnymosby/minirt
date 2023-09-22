/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:09:40 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/22 12:38:22 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

Test(spheres, intersect_at_two_points)
{
	t_ray	r;
	t_shape sph = create_sphere();
	t_hit	*xs;
	t_tuple	p = point(0, 0, -5);
	t_tuple	v = vector(0, 0, 1);

	xs = NULL;
	r = ray(&p, &v);
	intersect(&sph, &r, &xs);
	cr_assert(are_equal_doubles(xs->t, 4.0));
	cr_assert(are_equal_doubles(xs->right->t, 6.0));
}

Test(spheres, intersect_at_tangent)
{
	t_ray	r;
	t_shape sph = create_sphere();
	t_hit	*xs;
	t_tuple	p = point(0, 1, -5);
	t_tuple	v = vector(0, 0, 1);

	xs = NULL;
	r = ray(&p, &v);
	intersect(&sph, &r, &xs);
	cr_assert(are_equal_doubles(xs->t, 5.0));
	cr_assert(are_equal_doubles(xs->right->t, 5.0));
}

Test(spheres, no_intersect)
{
	t_ray	r;
	t_shape sph = create_sphere();
	t_hit	*xs;
	t_tuple	p = point(0, 2, -5);
	t_tuple	v = vector(0, 0, 1);

	xs = NULL;
	r = ray(&p, &v);
	intersect(&sph, &r, &xs);
	cr_assert(xs == NULL);
}

Test(spheres, ray_originates_inside_sphere)
{
	t_ray	r;
	t_shape sph = create_sphere();
	t_hit	*xs;
	t_tuple	p = point(0, 0, 0);
	t_tuple	v = vector(0, 0, 1);

	xs = NULL;
	r = ray(&p, &v);
	intersect(&sph, &r, &xs);

	cr_assert(count_intersections(xs, false) == 2);
	cr_assert(are_equal_doubles(xs->t, -1));
	cr_assert(are_equal_doubles(xs->right->t, 1));
}

Test(spheres, ray_is_behind_sphere)
{
	t_ray	r;
	t_shape sph = create_sphere();
	t_hit	*xs;
	t_tuple	p = point(0, 0, 5);
	t_tuple	v = vector(0, 0, 1);

	xs = NULL;
	r = ray(&p, &v);
	intersect(&sph, &r, &xs);

	cr_assert(count_intersections(xs, false) == 2);
	cr_assert(are_equal_doubles(xs->t, -6));
	cr_assert(are_equal_doubles(xs->right->t, -4));
}

Test(spheres, intersection_encapsulates_t_and_object)
{
	t_shape sph = create_sphere();
	t_hit *i = intersection(3.5, &sph);

	cr_assert(are_equal_doubles(i->t, 3.5));
	cr_assert(i->obj->shape_type == SPHERE);
}
