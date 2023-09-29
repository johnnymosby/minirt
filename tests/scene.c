/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:41:44 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/29 15:45:58 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

static bool	are_equal_lights(t_light *l1, t_light *l2)
{
	if (!are_equal_colors(&l1->intensity, &l2->intensity))
		return (false);
	if (!are_equal_tuples(&l1->position, &l2->position))
		return (false);
	return (true);
}

Test(scene, the_default_world)
{
	t_world		w;
	t_shape		sp1;
	t_shape		sp2;
	t_light		l;

	sp1 = create_sphere();
	set_material_to_default(&sp1.material);
	sp1.material.color = color(0.8, 1.0, 0.6);
	sp1.material.diffuse = 0.7;
	sp1.material.specular = 0.2;
	
	sp2 = create_sphere();
	set_material_to_default(&sp2.material);
	sp1.material.color = color(0.8, 1.0, 0.6);
	sp1.material.diffuse = 0.7;
	sp1.material.specular = 0.2;

	t_color c = color(1,1,1);
	t_tuple p = point(-10, 10, -10);
	l = point_light(&c, &p);

	w = default_world();
	cr_assert(are_equal_lights(w.lightning.light, &l));
	cr_assert(w.shape[0].shape_type == SPHERE);
	cr_assert(are_equal_materials(&w.shape->material, &sp1.material));
	cr_assert(w.shape[1].shape_type == SPHERE);
	cr_assert(are_equal_materials(&w.shape[1].material, &sp2.material));
}

Test(scene, intersect_world_with_a_ray)
{
	t_world		w;
	t_ray		r;
	t_tuple		p = point(0, 0, -5);
	t_tuple		v = vector(0, 0, 1);
	t_hit		**xs;

	w = default_world();
	r = ray(&p, &v);
	w.xs = NULL;
	xs = intersect_world(&w, &r);
	w.xs = *xs;
	//cr_assert(xs[0][0].t == 4.0);
	//printf("%d\n", count_intersections(xs[0], false));
	printf("%f\n", w.xs[0].t);
	printf("%f\n", w.xs[1].t);
	printf("%f\n", w.xs[2].t);
	printf("%f\n", w.xs[3].t);
	printf("%f\n", w.xs[4].t);
	cr_assert(false);
//	printf("%f\n", xs[0][0].left->t);
//	cr_assert(xs[0][1].t == 4.5);
//	printf("%f\n", xs[0][2].t);
//	cr_assert(xs[0][2].t == 5.5);
//	printf("%f\n", xs[0][3].t);
//	cr_assert(xs[0][3].t == 6.0);
}