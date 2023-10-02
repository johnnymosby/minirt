/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:43:44 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/02 19:41:12 by aguilmea         ###   ########.fr       */
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

