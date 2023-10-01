/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 10:53:19 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/01 11:30:19 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "math.h"

Test(constructing_a_camera, camera)
{
	t_camera	c;
	t_matrice	mat;
	
	c = camera(160, 120, PI/2);
	mat = identity_matrix();
	
	cr_assert(c.hsize == 160);
	cr_assert(c.vsize == 120);
	cr_assert(c.field_of_view = PI/2);
	cr_assert(are_equal_matrices(&mat, &c.transform));	
}