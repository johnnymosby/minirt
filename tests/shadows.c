#include "tests.h"

Test(shadows, lighting_with_the_surface_in_shadow)
{
	t_lightning	data;
	t_material m;
	set_material_to_default(&m);
	t_tuple eyev = vector(0, 0, -1);
	t_tuple	normalv = vector(0, 0, -1);
	t_tuple	p1 = point(0, 0, -10);
	t_tuple	p2 = point(0, 0, 0);
	t_color	c1 = color(1, 1, 1);
	t_light	light = point_light(&c1, &p1);
	bool	in_shadow = true;

	data.material = &m;
	data.point = &p2;
	data.eyev = &eyev;
	data.normalv = &normalv;
	data.light = &light;
	data.in_shadow = in_shadow;

	t_color result = lightning(&data);
	t_color answer = color(0.1, 0.1, 0.1);
	cr_assert(are_equal_colors(&result, &answer));
}

Test(shadows, there_is_no_shadow_when_nothing_is_collinear_with_point_and_light)
{
	t_world w = default_world();
	t_tuple p = point(0, 10, 0);
	cr_assert(is_shadowed(&w, &p) == false);
}

Test(shadows, the_shadow_when_an_object_is_between_the_point_and_the_light)
{
	t_world w = default_world();
	t_tuple p = point(10, -10, 10);
	cr_assert(is_shadowed(&w, &p) == true);
}

Test(shadows, there_is_no_shadow_when_an_object_is_behind_the_light)
{
	t_world w = default_world();
	t_tuple p = point(-20, 20, -20);
	cr_assert(is_shadowed(&w, &p) == false);
}

Test(shadows, there_is_no_shadow_when_an_object_is_behind_the_point)
{
	t_world w = default_world();
	t_tuple p = point(-2, 2, -2);
	cr_assert(is_shadowed(&w, &p) == false);
}
Test(shadows, shade_hit_is_given_an_intersection_in_shadow)
{
	t_shape	s[2];
	t_world w = default_world();
 	t_tuple p1 = point(0, 0, -10);
 	t_color c1 = color(1, 1, 1);
 	t_tuple p2 = point(0, 0, 5);
 	t_tuple v2 = vector(1, 0, 1);
	t_matrix m2 = translation(0, 0, 10);
	t_ray r = ray(&p2, &v2);
 	t_light l = point_light(&c1, &p1);
	w.lights = &l;
	s[0] = create_sphere();
	s[1] = create_sphere();
	set_transform(s+1, &m2);
	w.shape = s;
	t_hit *i = intersection(4, s+1);
	t_comp cp = prepare_computations(i, &r);
	t_color c = shade_hit(&w, &cp);
	t_color	color_check = color(0.1, 0.1, 0.1);
 	cr_assert(are_equal_colors(&c, &color_check));
 }
Test(shadows, hit_should_offset_the_point)
{
//	t_world	w;
	t_tuple	p1 = point(0, 0, -5);
	t_tuple	v1 = vector(0, 0, 1);
	t_ray		r1 = ray(&p1, &v1);
	t_shape		shape = create_sphere();
	t_matrix 	m1 = translation(0, 0, 1);
	set_transform(&shape,&m1);
	t_hit		*i = intersection(5, &shape);
	t_comp		comps = prepare_computations(i, &r1);
	//shade_hit(&w, &comps);
 	cr_assert(comps.over_point.z < EPSILON / 2);
 	cr_assert(comps.point.z > comps.over_point.z);
}