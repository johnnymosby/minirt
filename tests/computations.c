/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:43:44 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/06 15:09:50 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

Test(precomputation, precomputing_intersection_state)
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
Test(precomputation, precomputing_intersection_in)
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
}

Test(precomputation, precomputing_intersection_out)
{
	t_comp      c;
    t_ray       r;
	t_shape     shape;
    t_hit       *i;
    t_tuple     p;
    t_tuple     v;

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

Test(precomputation, shading_an_intersection)
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
    col_check = color(0.38066, 0.47583, 0.2855);
    cr_assert(are_equal_colors(&col, &col_check));
}

Test(precomputation, shading_an_intersection_from_inside)
{
	t_world     w;
    t_tuple     p1;
    t_tuple     p2;
    t_tuple     v;
    t_ray       r;
    t_hit       *i;
    t_comp      comps;
    t_color     col;
    t_color     col_check;

    w = default_world();
    p1 = point(0, 0.25, 0);
	col = color(1, 1, 1);
	w.lights[0] = point_light(&col, &p1);
    p2 = point(0, 0, 0);
    v = vector(0, 0, 1);
    r = ray(&p2, &v);
    i = intersection(0.5, w.shape + 1);
    comps = prepare_computations(i, &r);
    col = shade_hit(&w, &comps);
    col_check = color(0.90498, 0.90498, 0.90498);
	cr_assert(are_equal_colors(&col, &col_check));
}

Test(precomputation, the_color_when_ray_misses)
{
	t_world     w;
    t_tuple     p;
    t_tuple     v;
    t_ray       r;
    t_color     col;
    t_color     col_check;

    w = default_world();
    p = point(0, 0, -5);
    v = vector(0, 1, 0);
    r = ray(&p, &v);
    col = color_at(&w, &r);
    col_check = color(0.0, 0.0, 0.0);
    cr_assert(are_equal_colors(&col, &col_check));
}

Test(precomputation, the_color_when_ray_hits)
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

Test(precomputation, the_color_intersection_behind_ray)
{
	t_world     w;
    t_tuple     p;
    t_tuple     v;
    t_ray       r;
    t_color     col;

    w = default_world();
    w.shape[0].material.ambient = 1; // outer
    w.shape[1].material.ambient = 1; // inner
    p = point(0, 0, 0.75);
    v = vector(0, 0, -1);
    r = ray(&p, &v);
    col = color_at(&w, &r);
    cr_assert(are_equal_colors(&col, &w.shape[1].material.color));
}