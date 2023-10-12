/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:03:52 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/12 17:49:52 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

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
	pl.intersect(&pl, &r, &xs);

	cr_assert(xs == NULL);	
}
/*
Test(planes, intersect_with_a_coplanar_ray)
{
	t_tuple	p = point(0, 0, 0);
	t_tuple	v = vector(0, 0, 1);
	t_ray	r = ray(&p, &v);
	t_shape	pl = create_plane();
	t_hit	*xs = NULL;
	pl.intersect(&pl, &r, &xs);

	cr_assert(xs == NULL);	
}

Test(planes, a_ray_intersecting_a_plane_from_above)
{
	t_tuple	p = point(0, 1, 0);
	t_tuple	v = vector(0, -1, 1);
	t_ray	r = ray(&p, &v);
	t_shape	pl = create_plane();
	t_hit	*xs = NULL;
	pl.intersect(&pl, &r, &xs);

	cr_assert(count_intersections(xs, true) == 1);	
	cr_assert(xs[0].t == 1);
	//cr_assert(&xs[0].obj == &pl);
}


Test(planes, a_ray_intersecting_a_plane_from_below)
{
	cr_assert(false);	
}*/