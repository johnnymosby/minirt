/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:03:52 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/19 13:12:00 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static t_shape	create_test_shape(void)
{
	t_shape	shape;

	set_shape_to_default(&shape);
	shape.intersect = intersect_cylinder;
	shape.normal_at = normal_at_cylinder;
	return (shape);
}
Test(shapes, The_default_transformation)
{
	t_shape		s = create_test_shape();
	t_matrix	i = identity_matrix();

	cr_assert(are_equal_matrices(&s.transpose,&i));
}
Test(shapes, Assigning_a_transformation)
{
	t_shape		s = create_test_shape();
	t_matrix	t = translation(2, 3, 4);

	set_transform(&s,&t);
	cr_assert(are_equal_matrices(&s.transform, &t));
}
Test(shapes, The_default_material)
{
	t_shape		s = create_test_shape();
	t_color		color_check = color(1, 1, 1);

	set_material_to_default(&s.material);
	cr_assert(are_equal_colors(&s.material.color, &color_check));
	cr_assert(are_equal_doubles(0.1, s.material.ambient));	
	cr_assert(are_equal_doubles(0.9, s.material.diffuse));	
	cr_assert(are_equal_doubles(0.9, s.material.specular));	
	cr_assert(are_equal_doubles(200.0, s.material.shininess));	
}


Test(planes, the_normal_of_a_plane_is_constant_everywhere)
{
	t_tuple	pt1 = point(0, 0, 0);
	t_tuple	pt2 = point(-10, 0, -10);
	t_tuple	pt3 = point(-5, 0, 150);
	t_tuple	check = vector(0, 1, 0);
	t_shape	p = create_plane();	
	t_tuple	n1 = p.normal_at(&p, &pt1);
	t_tuple	n2 = p.normal_at(&p, &pt2);
	t_tuple	n3 = p.normal_at(&p, &pt3);
	
	cr_assert(are_equal_tuples(&n1, &check));	
	cr_assert(are_equal_tuples(&n2, &check));	
	cr_assert(are_equal_tuples(&n3, &check));	
}

Test(planes, intersect_with_a_ray_parallel_to_the_plane)
{
	t_tuple	p = point(0, 10, 0);
	t_tuple	v = vector(0, 0, 1);
	t_ray	r = ray(&p, &v);
	t_shape	pl = create_plane();
	t_hit	*xs = NULL;
	intersect(&pl, &r, &xs);

	cr_assert(xs == NULL);	
}

Test(planes, intersect_with_a_coplanar_ray)
{
	t_tuple	p = point(0, 0, 0);
	t_tuple	v = vector(0, 0, 1);
	t_ray	r = ray(&p, &v);
	t_shape	pl = create_plane();
	t_hit	*xs = NULL;
	intersect(&pl, &r, &xs);

	cr_assert(xs == NULL);	
}

Test(planes, a_ray_intersecting_a_plane_from_above)
{
	t_tuple	p = point(0, 1, 0);
	t_tuple	v = vector(0, -1, 1);
	t_ray	r = ray(&p, &v);
	t_shape	pl = create_plane();
	t_hit	*xs = NULL;
	intersect(&pl, &r, &xs);

	printf("xs = %p\n", xs);
	//cr_assert(count_intersections(xs, true) == 1);	
	//cr_assert(xs[0].t == 1);
	//cr_assert(xs[0].obj == &pl);
}


Test(planes, a_ray_intersecting_a_plane_from_below)
{
	t_tuple	p = point(0, -1, 0);
	t_tuple	v = vector(0, 1, 1);
	t_ray	r = ray(&p, &v);
	t_shape	pl = create_plane();
	t_hit	*xs = NULL;
	intersect(&pl, &r, &xs);

	//cr_assert(count_intersections(xs, true) == 1);	
	//cr_assert(xs[0].t == 1);
	//cr_assert(xs[0].obj == &pl);
}