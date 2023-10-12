/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:00:43 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/12 10:34:37 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static t_shape	create_test_shape(void)
{
	t_shape	shape;
	t_tuple	null_point;

	set_shape_to_default(&shape);
	null_point = point(0, 0, 0);
	shape.intersect = intersect_sphere;
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
Test(shapes, Assigning_a_material)
{
	t_shape		s = create_test_shape();
	t_material	m;
	t_color		color_check = color(1, 1, 1);

	set_material_to_default(&m);
	m.ambient = 1.0;
	s.material = m;
	cr_assert(are_equal_colors(&s.material.color, &color_check));
	cr_assert(are_equal_doubles(1.0, s.material.ambient));	
	cr_assert(are_equal_doubles(0.9, s.material.diffuse));	
	cr_assert(are_equal_doubles(0.9, s.material.specular));	
	cr_assert(are_equal_doubles(200.0, s.material.shininess));	
}

Test(shapes, Intersecting_a_scaled_shape_with_a_ray)
{
	t_tuple		p = point(0, 0, -5);
	t_tuple		v = vector(0, 0, 1);	
	t_ray		r = ray(&p, &v);
	t_shape		s = create_test_shape();
	t_matrix	sc = scaling(2, 2, 2);
	t_hit		*xs;

	set_transform(&s, &sc);
	xs = NULL;
	intersect(&s, &r, &xs);
	p = point(0, 0, -2.5);
	cr_assert(are_equal_tuples(&r.origin, &p));
	v = vector(0, 0, 0.5);
	cr_assert(are_equal_tuples(&r.direction, &p));
}

Test(shapes, Intersecting_a_translated_shape_with_a_ray)
{
	t_tuple		p = point(0, 0, -5);
	t_tuple		v = vector(0, 0, 1);	
	t_ray		r = ray(&p, &v);
	t_shape		s = create_test_shape();
	t_matrix	tr = translation(5, 5, 5);
	t_hit		*xs;

	set_transform(&s, &tr);
	xs = NULL;
	intersect(&s, &r, &xs);
	p = point(-5, 0, -5);
	cr_assert(are_equal_tuples(&r.origin, &p));
	v = vector(0, 0, 1);
	cr_assert(are_equal_tuples(&r.direction, &p));
}

Test(shapes, Computing_the_normal_on_a_translated_shape)
{
	t_shape		s = create_test_shape();
	t_matrix	translat = translation(0, 1, 0);
	set_transform(&s, &translat);
	//t_tuple	p = point(0, 1.70711, -0.70711);
	//t_tuple	n = s.normal_at(&s, &p);
	//t_tuple	check = vector(0, 1.70711, -0.70711);

	//cr_assert(are_equal_tuples(&n, &check));
	cr_assert(false);
}
#include <math.h>
Test(shapes, Computing_the_normal_on_a_tranformed_shape)
{
	t_shape		s = create_test_shape();
	t_matrix	sc = scaling(1, 0.5, 1);
	t_matrix	rot = rotation_z(M_PI / 5);
	t_matrix	m = multiply_matrices(&sc, &rot);
	set_transform(&s, &m);
	//t_tuple		p = point(0, sqrt(2)/ 2, -(sqrt(2)/2));
	//t_tuple		n = s.normal_at(&s, &p);
	//t_tuple		check = vector(0, 0.97014, -0.24254);

	//cr_assert(are_equal_tuples(&n, &check));
	cr_assert(false);
}