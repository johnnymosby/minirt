/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 10:53:19 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/08 21:05:41 by rbasyrov         ###   ########.fr       */
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
	cr_assert(are_equal_tuples(&r.direction, &v));
}

Test(camera, ray_corner_of_canvas)
{
	t_camera	c;
	t_ray		r;
	t_tuple		p = point(0, 0, 0);
	t_tuple		v = vector(0.66519, 0.33259, -0.66851);
	
	c = camera(201, 101, M_PI_2);
	r = ray_for_pixel(&c, 0, 0);
	cr_assert(are_equal_tuples(&r.origin, &p));
	cr_assert(are_equal_tuples(&r.direction, &v));
}

Test(camera, ray_camera_transformation)
{
	t_camera	c;
	t_ray		r;
	t_tuple		p = point(0, 2, -5);
	t_tuple		v = vector(sqrt(2)/2, 0, -sqrt(2)/2);
	t_matrix	m_rotation_y = rotation_y(M_PI_4);
	t_matrix	m_translation = translation(0, -2, 5);
	t_matrix	m_transform = multiply_matrices(&m_rotation_y, &m_translation);
	
	c = camera(201, 101, M_PI_2);
	set_transform_in_camera(&c, &m_transform);
	r = ray_for_pixel(&c, 100, 50);
	

	cr_assert(are_equal_tuples(&r.origin, &p));
	cr_assert(are_equal_tuples(&r.direction, &v));
}

Test(camera, render)
{
	t_world w = default_world();
	t_camera c = camera(11, 11, M_PI_2);
	t_tuple from = point(0, 0, -5);
	t_tuple to = point(0, 0, 0);
	t_tuple up = vector(0, 1, 0);
	t_matrix transform = view_transform(&from, &to, &up);
	set_transform_in_camera(&c, &transform);
	t_canvas *image = render(&c, &w);
	t_color col = color(0.38066, 0.47583, 0.2855);
	t_color col2 = pixel_at(image, 5, 5);
	cr_assert(are_equal_colors(&col, &col2));
}