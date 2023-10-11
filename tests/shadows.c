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

// Test(shadows, shade_hit_is_given_an_intersection_in_shadow)
// {
// 	t_world w = default_world();
// 	t_tuple p1 = point(0, 0, -10);
// 	t_tuple c1 = color(1, 1, 1);
// 	w.light = point_light(&c1, &p1);
// 	cr_assert(is_shadowed(&w, &p) == false);
// }