/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:41:44 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/06 17:33:33 by rbasyrov         ###   ########.fr       */
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
	t_matrix	m;
	m = scaling(0.5, 0.5, 0.5);
	set_transform(&sp2, &m);

	t_color c = color(1,1,1);
	t_tuple p = point(-10, 10, -10);
	l = point_light(&c, &p);

	w = default_world();
	cr_assert(are_equal_lights(w.lights, &l));
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

	w = default_world();
	r = ray(&p, &v);
	w.xs = NULL;
	intersect_world(&w, &r);

	cr_assert(count_intersections(w.xs, true) == 4);
	cr_assert(are_equal_doubles(w.xs->t, 4.0));
	cr_assert(are_equal_doubles(w.xs->left->t, 4.5));
	cr_assert(are_equal_doubles(w.xs->left->left->t, 5.5));
	cr_assert(are_equal_doubles(w.xs->left->left->left->t, 6));
}

Test(view, transformation_for_default_orientation)
{
	t_tuple from	= point(0, 0, 0);
	t_tuple to		= point(0, 0, -1);
	t_tuple up		= vector(0, 1, 0);

	t_matrix t = view_transform(&from, &to, &up);

	t_matrix I = identity_matrix();
	cr_assert(are_equal_matrices(&t, &I));
}

Test(view, transformation_for_looking_in_positive_z)
{
	t_tuple from	= point(0, 0, 0);
	t_tuple to		= point(0, 0, 1);
	t_tuple up		= vector(0, 1, 0);

	t_matrix t = view_transform(&from, &to, &up);

	t_matrix scaled_m = scaling(-1, 1, -1);
	cr_assert(are_equal_matrices(&t, &scaled_m));
}

Test(view, transformation_moves_the_world)
{
	t_tuple from	= point(0, 0, 8);
	t_tuple to		= point(0, 0, 0);
	t_tuple up		= vector(0, 1, 0);

	t_matrix t = view_transform(&from, &to, &up);

	t_matrix translated_m = translation(0, 0, -8);
	cr_assert(are_equal_matrices(&t, &translated_m));
}

Test(view, transformation_arbitrary)
{
	t_tuple from	= point(1, 3, 2);
	t_tuple to		= point(4, -2, 8);
	t_tuple up		= vector(1, 1, 0);

	t_matrix t = view_transform(&from, &to, &up);

	const double table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {{-0.50709, 0.50709, 0.67612, -2.36643},
	{0.76772, 0.60609, 0.12122, -2.82843},
	{-0.35857, 0.59761, -0.71714, 0},
	{0, 0, 0, 1}
	};
	t_matrix m = matrix(table, MAX_SIDE_SIZE);
	cr_assert(are_equal_matrices(&t, &m));
}

