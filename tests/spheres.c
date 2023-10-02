/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spheres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:09:40 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/02 16:57:20 by rbasyrov         ###   ########.fr       */
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
	cr_assert(are_equal_doubles(xs->left->t, 6.0));
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
	cr_assert(are_equal_doubles(xs->left->t, 5.0));
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

	cr_assert(count_intersections(xs, true) == 2);
	cr_assert(are_equal_doubles(xs->t, -1));
	cr_assert(are_equal_doubles(xs->left->t, 1));
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

	cr_assert(count_intersections(xs, true) == 2);
	cr_assert(are_equal_doubles(xs->t, -6));
	cr_assert(are_equal_doubles(xs->left->t, -4));
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
	i1->left = i2;
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
	t_tuple	p = point(0, 0, -5);
	t_tuple v = vector(0, 0, 1);
	t_ray r = ray(&p, &v);
	t_shape s = create_sphere();

	t_matrix m_scale = scaling(2, 2, 2);
	set_transform(&s, &m_scale);

	t_hit	*xs;
	xs = NULL;
	intersect(&s, &r, &xs);

	cr_assert(count_intersections(xs, true) == 2);
	cr_assert(are_equal_doubles(xs->t, 3));
	cr_assert(are_equal_doubles(xs->left->t, 7));
}

Test(spheres, intersecting_a_translated_sphere_with_a_ray)
{
	t_tuple	p = point(0, 0, -5);
	t_tuple v = vector(0, 0, 1);
	t_ray r = ray(&p, &v);
	t_shape s = create_sphere();

	t_matrix m_scale = translation(5, 0, 0);
	set_transform(&s, &m_scale);

	t_hit	*xs;
	xs = NULL;
	intersect(&s, &r, &xs);

	cr_assert(count_intersections(xs, true) == 0);
}

Test(spheres_normal, the_normal_on_a_sphere_at_a_point_on_the_x_axis)
{
	t_tuple	p = point(1, 0, 0);
	t_shape s = create_sphere();
	t_tuple n = normal_at_sphere(&s, &p);

	t_tuple v = vector(1, 0, 0);

	cr_assert(are_equal_tuples(&n, &v));
}

Test(spheres_normal, the_normal_on_a_sphere_at_a_point_on_the_y_axis)
{
	t_tuple	p = point(0, 1, 0);
	t_shape s = create_sphere();
	t_tuple n = normal_at_sphere(&s, &p);

	t_tuple v = vector(0, 1, 0);

	cr_assert(are_equal_tuples(&n, &v));
}

Test(spheres_normal, the_normal_on_a_sphere_at_a_point_on_the_z_axis)
{
	t_tuple	p = point(0, 0, 1);
	t_shape s = create_sphere();
	t_tuple n = normal_at_sphere(&s, &p);

	t_tuple v = vector(0, 0, 1);

	cr_assert(are_equal_tuples(&n, &v));
}

Test(spheres_normal, the_normal_on_a_sphere_at_a_nonaxial_point)
{
	t_tuple	p = point(sqrt(3) / 3, sqrt(3) / 3, sqrt(3) / 3);
	t_shape s = create_sphere();
	t_tuple n = normal_at_sphere(&s, &p);

	t_tuple v = vector(sqrt(3) / 3, sqrt(3) / 3, sqrt(3) / 3);

	cr_assert(are_equal_tuples(&n, &v));
}

Test(spheres_normal, the_normal_is_a_normalized_vector)
{
	t_tuple	p = point(sqrt(3) / 3, sqrt(3) / 3, sqrt(3) / 3);
	t_shape s = create_sphere();
	t_tuple n = normal_at_sphere(&s, &p);

	t_tuple n_normalized = normalize(&n);

	cr_assert(are_equal_tuples(&n, &n_normalized));
}

Test(spheres_normal, computing_the_normal_on_a_translated_sphere)
{
	t_tuple	p = point(0, 1.70711, -0.70711);
	t_shape s = create_sphere();
	t_matrix m_transl = translation(0, 1, 0);
	set_transform(&s, &m_transl);
	t_tuple n = normal_at_sphere(&s, &p);


	t_tuple v = vector(0, 0.70711, -0.70711);

	cr_assert(are_equal_tuples(&n, &v));
}

Test(spheres_normal, computing_the_normal_on_a_transformed_sphere)
{
	t_tuple	p = point(0, sqrt(2) / 2, - sqrt(2) / 2);
	t_shape s = create_sphere();
	t_matrix m_sc = scaling(1, 0.5, 1);
	t_matrix m_ror_z = rotation_z(M_PI / 5);
	t_matrix m_mult = multiply_matrices(&m_sc, &m_ror_z);
	set_transform(&s, &m_mult);
	t_tuple n = normal_at_sphere(&s, &p);


	t_tuple v = vector(0, 0.97014, -0.24254);

	cr_assert(are_equal_tuples(&n, &v));
}

Test(spheres_intersection, intersecting_two_spheres)
{
	t_shape s = create_sphere();
	t_shape s1 = create_sphere();
	t_matrix m = scaling(0.5, 0.5, 0.5);
	set_transform(&s1, &m);

	t_hit		*xs;
	xs = NULL;

	t_tuple		p = point(0, 0, -5);
	t_tuple		v = vector(0, 0, 1);

	t_ray r = ray(&p, &v);

	intersect(&s, &r, &xs);
	intersect(&s1, &r, &xs);

	cr_assert(are_equal_doubles(xs->t, 4.0));
	cr_assert(are_equal_doubles(xs->left->t, 4.5));
	cr_assert(are_equal_doubles(xs->left->left->t, 5.5));
	cr_assert(are_equal_doubles(xs->left->left->left->t, 6));
	cr_assert(xs->left->left->left->left == NULL);
}

