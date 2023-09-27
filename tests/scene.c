/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:41:44 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/27 11:25:35 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
/*
static bool	are_equal_spheres(t_shape *sp1, t_shape *sp2)
{
	if (!are_equal_materials(&sp1->material, &sp2->material))
	{	
		printf("test 4\n");;
		return (false);
	}
	if (!are_equal_matrices(&sp1->transform, &sp2->transform))
	{	
		printf("test 1\n");
		return (false);
	}
	if (!are_equal_matrices(&sp1->inverse, &sp2->inverse))
	{	
		printf("test 2\n");
		return (false);
	}
	if (!are_equal_matrices(&sp1->transpose, &sp2->transpose))
	{	
		printf("test 3\n");
		return (false);
	}
	return (true);
}*/

Test(scene, the_default_world)
{
	t_world		w;
	t_shape		sp1;
	t_shape		sp2;

	sp1 = create_sphere();
	sp1.material.color = color(0.8, 1.0, 0.6);
	sp1.material.diffuse = 0.7;
	sp1.material.specular = 0.2;
	sp2 = create_sphere();

	w = default_world();
	//cr_assert(are_equals_lights(w.light, l));
	cr_assert(w.shape[0].shape_type == SPHERE);
	//cr_assert(are_equal_spheres(w.shape, &sp1));
	cr_assert(w.shape[1].shape_type == SPHERE);
	//cr_assert(are_equal_spheres(w.shape + 1, &sp2));
}

Test(scene, intersect_world_with_a_ray)
{
	t_world		w;

	w = default_world();
	
	cr_assert(true);
}