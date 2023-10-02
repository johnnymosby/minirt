/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 10:53:19 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/02 15:24:00 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "math.h"

#define EPSILON 0.001

Test(constructing_a_camera, camera)
{
	t_camera	c;
	t_matrix	mat;
	
	c = camera(160, 120, M_PI_2);
	mat = identity_matrix();
	
	cr_assert(c.hsize == 160);
	cr_assert(c.vsize == 120);
	cr_assert(c.field_of_view == M_PI_2);
	cr_assert(are_equal_matrices(&mat, &c.transform));	

}
Test(pixel_size, camera)
{
	t_camera	c;
	
	c = camera(200, 125, M_PI_2);
	cr_assert(fabs(c.pixel_size - 0.01) < EPSILON);

	c = camera(125, 200, M_PI_2);
	cr_assert(fabs(c.pixel_size - 0.01) < EPSILON);;
}
/*
Test(ray_center_of_canvas, camera)
{
	t_camera	c;
	t_ray		r;
	
	c = camera(201, 101, M_PI_2);
	r = ray_for_pixel(c, 100, 50);
	cr_assert(r.origin = point(0, 0, 0));
	cr_assert(r.direction = vector(0, 0, -1));
}

Test(ray_corner_of_canvas, camera)
{
	t_camera	c;
	t_ray		r;
	
	c = camera(201, 101, M_PI_2);
	r = ray_for_pixel(c, 0, 0);
	cr_assert(r.origin = point(0, 0, 0));
	cr_assert(r.direction = vector(0.66519, 0.33259, -0.66851));
}

Test(ray_camera_transformation, camera)
{
	t_camera	c;
	t_ray		r;
	
	c = camera(201, 101, M_PI_2);
	c.transform = rotation_y(M_PI_4) * translation(0, -2, 5);
	r = ray_for_pixel(c, 100, 50);
	cr_assert(r.origin = point(0, 2, -5));
	cr_assert(r.direction = vector(sqrt(M_PI_2)/2, 0, sqrt(-M_PI_2)/2);
}*/