/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:09:40 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/22 18:39:31 by rbasyrov         ###   ########.fr       */
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

Test(spheres, aggregating_intersections)
{
	t_hit	*xs;
	t_shape sph = create_sphere();
	t_hit *i1 = intersection(1, &sph);
	t_hit *i2 = intersection(2, &sph);

	xs = NULL;
	add_intersection(&xs, i1);
	add_intersection(&xs, i2);


	cr_assert(count_intersections(xs, true) == 2);
	cr_assert(are_equal_doubles(xs->t, 1));
	cr_assert(are_equal_doubles(xs->left->t, 2));
}

Test(spheres, intersect_sets_object_on_the_intersection)
{
	t_hit	*xs;
	t_shape sph = create_sphere();
	t_hit *i1 = intersection(1, &sph);
	t_hit *i2 = intersection(2, &sph);

	xs = NULL;
	add_intersection(&xs, i1);
	add_intersection(&xs, i2);


	cr_assert(count_intersections(xs, true) == 2);
	cr_assert(xs->obj->shape_type == SPHERE);
	cr_assert(xs->left->obj->shape_type == SPHERE);
}

Test(spheres, hit_when_all_intersections_have_positive_t)
{
	t_hit	*xs;
	t_shape sph = create_sphere();
	t_hit *i1 = intersection(1, &sph);
	t_hit *i2 = intersection(2, &sph);

	xs = NULL;
	i1->right = i2;
	add_intersection(&xs, i1);

	t_hit *i = hit(xs, false);

	cr_assert(i == i1);
}

Test(spheres, hit_when_some_intersections_have_negative_t)
{
	t_hit	*xs;
	t_shape sph = create_sphere();
	t_hit *i1 = intersection(-1, &sph);
	t_hit *i2 = intersection(1, &sph);

	xs = NULL;
	add_intersection(&xs, i1);
	add_intersection(&xs, i2);

	t_hit *i = hit(xs, true);

	cr_assert(i == i2);
}

Test(spheres, hit_when_all_intersections_have_negative_t)
{
	t_hit	*xs;
	t_shape sph = create_sphere();
	t_hit *i1 = intersection(-2, &sph);
	t_hit *i2 = intersection(-1, &sph);

	xs = NULL;
	add_intersection(&xs, i1);
	add_intersection(&xs, i2);


	t_hit *i = hit(xs, true);

	cr_assert(i == NULL);
}

Test(spheres, hit_is_always_the_lowest_nonnegative_intersection)
{
	t_hit	*xs;
	t_shape sph = create_sphere();
	t_hit *i1 = intersection(5, &sph);
	t_hit *i2 = intersection(7, &sph);
	t_hit *i3 = intersection(-3, &sph);
	t_hit *i4 = intersection(2, &sph);

	xs = NULL;
	add_intersection(&xs, i1);
	add_intersection(&xs, i2);
	add_intersection(&xs, i3);
	add_intersection(&xs, i4);

	t_hit *i = hit(xs, true);

	cr_assert(i == i4);
}

Test(spheres, translating_a_ray)
{
	t_tuple	p = point(1, 2, 3);
	t_tuple v = vector(0, 1, 0);
	t_matrix m = translation(3, 4, 5);

	t_ray r = ray(&p, &v);
	t_ray r2 = transform(&r, &m);

	t_tuple p2 = point(4, 6, 8);
	t_tuple v2 = vector(0, 1, 0);

	cr_assert(are_equal_tuples(&r2.origin, &p2));
	cr_assert(are_equal_tuples(&r2.direction, &v2));
	
}

Test(spheres, scaling_a_ray)
{
	t_tuple	p = point(1, 2, 3);
	t_tuple v = vector(0, 1, 0);
	t_matrix m = scaling(2, 3, 4);

	t_ray r = ray(&p, &v);
	t_ray r2 = transform(&r, &m);

	t_tuple p2 = point(2, 6, 12);
	t_tuple v2 = vector(0, 3, 0);

	cr_assert(are_equal_tuples(&r2.origin, &p2));
	cr_assert(are_equal_tuples(&r2.direction, &v2));
	
}

Test(spheres, sphere_default_transformation)
{
	t_shape sph = create_sphere();
	t_matrix i_matrix = identity_matrix();

	cr_assert(are_equal_matrices(&sph.transform, &i_matrix));	
}

Test(spheres, changing_sphere_transformation)
{
	t_shape sph = create_sphere();
	t_matrix t = translation(2, 3, 4);

	sph.transform = t;

	cr_assert(are_equal_matrices(&t, &sph.transform));	
}


Test(spheres, intersecting_a_scaled_sphere_with_a_ray)
{
	t_shape sph = create_sphere();
	t_matrix i_matrix = identity_matrix();

	cr_assert(are_equal_matrices(&sph.transform, &i_matrix));
	
}
