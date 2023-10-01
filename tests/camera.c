/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 10:53:19 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/01 19:40:51 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "math.h"

Test(constructing_a_camera, camera)
{
	t_camera	c;
	t_matrix	mat;
	
	c = camera(160, 120, M_PI_2);
	mat = identity_matrix();
	
	cr_assert(c.hsize == 160);
	cr_assert(c.vsize == 120);
	cr_assert(c.field_of_view = M_PI_2);
	cr_assert(are_equal_matrices(&mat, &c.transform));	

}
Test(pixel_size, camera)
{
	t_camera	c;
	
//	c = camera(200, 125, M_PI_2);
//	printf("1 - camera.pixel_size %f\n", c.pixel_size);
//	cr_assert(c.pixel_size == 0.01);

	c = camera(125, 200, M_PI_2);
	printf("2 - camera.pixel_size %f\n", c.pixel_size);
	cr_assert(c.pixel_size == 0.01);
}