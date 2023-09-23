/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:40:16 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/23 19:04:45 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

Test(reflection, reflecting_a_vector_approaching_at_45_degrees)
{
	t_tuple v = vector(1, -1, 0);
	t_tuple n = vector(0, 1, 0);
	t_tuple r = reflect(&v, &n);

	t_tuple answer = vector(1, 1, 0);

	cr_assert(are_equal_tuples(&r, &answer));
}

Test(reflection, reflecting_a_vector_off_a_slanted_surface)
{
	t_tuple v = vector(0, -1, 0);
	t_tuple n = vector(sqrt(2) / 2, sqrt(2) / 2, 0);
	t_tuple r = reflect(&v, &n);

	t_tuple answer = vector(1, 0, 0);

	cr_assert(are_equal_tuples(&r, &answer));
}

Test(light, a_point_light_has_a_position_and_intensity)
{
	t_color intensity = color(1, 1, 1);
	t_tuple position = point(0, 0, 0);

	t_light light = point_light(&intensity, &position);

	cr_assert(are_equal_colors(&light.intensity, &intensity));
	cr_assert(are_equal_tuples(&light.position, &position));
}

Test(light, the_default_material)
{
	t_material m1;
	t_color c = color(1, 1, 1);

	set_material_to_default(&m1);

	cr_assert(are_equal_doubles(m1.ambient, 0.1));
	cr_assert(are_equal_doubles(m1.diffuse, 0.9));
	cr_assert(are_equal_doubles(m1.specular, 0.9));
	cr_assert(are_equal_doubles(m1.shininess, 200));
	cr_assert(are_equal_colors(&m1.color, &c));
}

Test(light, a_sphere_has_a_default_material)
{
	t_shape	sphere = create_sphere();
	t_material m1;

	set_material_to_default(&m1);

	cr_assert(are_equal_materials(&sphere.material, &m1));
}

Test(light, a_sphere_may_be_assigned_a_material)
{
	t_shape	sphere = create_sphere();
	t_material m1;

	set_material_to_default(&m1);
	m1.ambient = 1;
	sphere.material = m1;

	cr_assert(are_equal_materials(&sphere.material, &m1));
}

Test(lightning, lightning_with_the_eye_between_the_light_and_the_surface)
{
	t_tuple position = point(0, 0, 0);
	t_material m;
	set_material_to_default(&m);

	t_tuple eyev = vector(0, 0, -1);
	t_tuple normalv = vector(0, 0, -1);
	t_tuple p = point(0, 0, -10);
	t_color c = color(1, 1, 1);
	t_light light = point_light(&c, &p);
	t_lightning data;
	data.material = &m;
	data.light = &light;
	data.point = &position;
	data.eyev = &eyev;
	data.normalv = &normalv;
	t_color	result = lightning(&data);

	t_color	answer = color(1.9, 1.9, 1.9);

	cr_assert(are_equal_colors(&result, &answer));
}

Test(lightning, lightning_with_the_eye_between_the_light_and_the_surface_eye_offset_45)
{
	t_tuple position = point(0, 0, 0);
	t_material m;
	set_material_to_default(&m);

	t_tuple eyev = vector(0, sqrt(2) / 2, -sqrt(2) / 2);
	t_tuple normalv = vector(0, 0, -1);
	t_tuple p = point(0, 0, -10);
	t_color c = color(1, 1, 1);
	t_light light = point_light(&c, &p);
	t_lightning data;
	data.material = &m;
	data.light = &light;
	data.point = &position;
	data.eyev = &eyev;
	data.normalv = &normalv;
	t_color	result = lightning(&data);

	t_color	answer = color(1, 1, 1);

	cr_assert(are_equal_colors(&result, &answer));
}

Test(lightning, lightning_with_the_eye_opposite_surface_light_offset_45)
{
	t_tuple position = point(0, 0, 0);
	t_material m;
	set_material_to_default(&m);

	t_tuple eyev = vector(0, 0, -1);
	t_tuple normalv = vector(0, 0, -1);
	t_tuple p = point(0, 10, -10);
	t_color c = color(1, 1, 1);
	t_light light = point_light(&c, &p);
	t_lightning data;
	data.material = &m;
	data.light = &light;
	data.point = &position;
	data.eyev = &eyev;
	data.normalv = &normalv;
	t_color	result = lightning(&data);

	t_color	answer = color(0.7364, 0.7364, 0.7364);

	cr_assert(are_equal_colors(&result, &answer));
}

Test(lightning, lightning_with_the_eye_in_the_path_of_reflection_vector)
{
	t_tuple position = point(0, 0, 0);
	t_material m;
	set_material_to_default(&m);

	t_tuple eyev = vector(0, -sqrt(2) / 2, -sqrt(2) / 2);
	t_tuple normalv = vector(0, 0, -1);
	t_tuple p = point(0, 10, -10);
	t_color c = color(1, 1, 1);
	t_light light = point_light(&c, &p);
	t_lightning data;
	data.material = &m;
	data.light = &light;
	data.point = &position;
	data.eyev = &eyev;
	data.normalv = &normalv;
	t_color	result = lightning(&data);

	t_color	answer = color(1.6364, 1.6364, 1.6364);

	cr_assert(are_equal_colors(&result, &answer));
}

Test(lightning, lightning_with_the_light_behind_the_surface)
{
	t_tuple position = point(0, 0, 0);
	t_material m;
	set_material_to_default(&m);

	t_tuple eyev = vector(0, 0, -1);
	t_tuple normalv = vector(0, 0, -1);
	t_tuple p = point(0, 0, 10);
	t_color c = color(1, 1, 1);
	t_light light = point_light(&c, &p);
	t_lightning data;
	data.material = &m;
	data.light = &light;
	data.point = &position;
	data.eyev = &eyev;
	data.normalv = &normalv;
	t_color	result = lightning(&data);

	t_color	answer = color(0.1, 0.1, 0.1);

	cr_assert(are_equal_colors(&result, &answer));
}
