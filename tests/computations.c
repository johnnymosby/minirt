/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:43:44 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/04 11:54:14 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

Test(precomputing_intersection_state ,precomputation)
{
	t_comp      c;
    t_ray       r;
	t_shape     shape;
    t_hit       *i;
    t_tuple     p;
    t_tuple     v;

    p = point(0, 0, -5);
    v = vector(0, 0, 1);
    r = ray(&p, &v);
    shape = create_sphere();
    i = intersection(4, &shape);
    c = prepare_computations(i, &r);
    cr_assert(c.t == i->t);
    p = point(0, 0, -1);
    cr_assert(are_equal_tuples(&c.point, &p));
    v = vector(0, 0, -1);
    cr_assert(are_equal_tuples(&c.eyev, &v));
    cr_assert(are_equal_tuples(&c.normalv, &v));
}
Test(precomputing_intersection_in_out ,precomputation)
{
	t_comp      c;
    t_ray       r;
	t_shape     shape;
    t_hit       *i;
    t_tuple     p;
    t_tuple     v;

    p = point(0, 0, -5);
    v = vector(0, 0, 1);
    r = ray(&p, &v);
    shape = create_sphere();
    i = intersection(4, &shape);
    c = prepare_computations(i, &r);
    cr_assert(c.inside == false);
    
    p = point(0, 0, 0);
    v = vector(0, 0, 1);
    r = ray(&p, &v);
    shape = create_sphere();
    i = intersection(1, &shape);
    c = prepare_computations(i, &r);
    p = point(0, 0, 1);
    cr_assert(are_equal_tuples(&c.point, &p));
    v = vector(0, 0, -1);
    cr_assert(are_equal_tuples(&c.eyev, &v));
    cr_assert(c.inside == true);
    cr_assert(are_equal_tuples(&c.normalv, &v));
}

Test(shading_an_intersection ,precomputation)
{
	t_world     w;
    t_tuple     p;
    t_tuple     v;
    t_ray       r;
    t_hit       *i;
    t_comp      comps;
    t_color     col;
    t_color     col_check;

    w = default_world();
    p = point(0, 0, -5);
    v = vector(0, 0,1);
    r = ray(&p, &v);
    i = intersection(4, w.shape);
    comps = prepare_computations(i, &r);
    col = shade_hit(&w, &comps);
    col_check = color(0.380661, 0.475826, 0.285496);
   cr_assert(are_equal_colors(&col, &col_check));
    
}
Test(the_color_when_ray_misses ,precomputation)
{
	t_world     w;
    t_tuple     p;
    t_tuple     v;
    t_ray       r;
    t_color     col;
    t_color     col_check;

    w = default_world();
    p = point(0, 0, -5);
    v = vector(0, 1,0);
    r = ray(&p, &v);
    col = color_at(&w, &r);
    col_check = color(0.0, 0.0, 0.0);
    cr_assert(are_equal_colors(&col, &col_check));
    
}
/*
Test(the_color_when_ray_hits ,precomputation)
{
	t_world     w;
    t_tuple     p;
    t_tuple     v;
    t_ray       r;
    t_color     col;
    t_color     col_check;

    w = default_world();
    p = point(0, 0, -5);
    v = vector(0, 0,1);
    r = ray(&p, &v);
    col = color_at(&w, &r);
    col_check = color(0.38066, 0.47583, 0.2855);
    cr_assert(are_equal_colors(&col, &col_check));
}
Test(the_color_intersection_behind_ray ,precomputation)
{
	t_world     w;
    t_tuple     p;
    t_tuple     v;
    t_ray       r;
    t_color     col;

    w = default_world();
    w.shape[0].material.ambient = 1; // outer
    w.shape[1].material.ambient = 1; // inner
    p = point(0, 0, -5);
    v = vector(0, 0,1);
    r = ray(&p, &v);
    col = color_at(&w, &r);
    cr_assert(are_equal_colors(&col, &w.shape[0].material.color));
}*/