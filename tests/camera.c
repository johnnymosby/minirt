/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 10:53:19 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/06 18:35:57 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "math.h"

#define EPSILON 0.001

Test(camera, constructing_a_camera)
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

Test(camera, pixel_size)
{
	t_camera	c;
	
	c = camera(200, 125, M_PI_2);
	cr_assert(are_equal_doubles(c.pixel_size, 0.01));

	c = camera(125, 200, M_PI_2);
	cr_assert(are_equal_doubles(c.pixel_size, 0.01));
}

Test(camera, ray_center_of_canvas)
{
	t_camera	c = camera(201, 101, M_PI_2);
	t_ray		r = ray_for_pixel(&c, 100, 50);
	t_tuple		p = point(0, 0, 0);
	t_tuple		v = vector(0, 0, -1);
	
	cr_assert(are_equal_tuples(&r.origin, &p));
	printf("%f %f %f\n", r.direction.x, r.direction.y, r.direction.z);
	cr_assert(are_equal_tuples(&r.direction, &v));
}
/*
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