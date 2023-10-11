#include "tests.h"

Test(cylinders, a_ray_misses_a_cylinder)
{
	t_shape cylinder = create_cylinder();
	t_hit	*xs = NULL;
	t_tuple	origin = point(1, 0, 0);
	t_tuple	v = vector(0, 1, 0);
	t_tuple	direction = normalize(&v);
	t_ray r = ray(&origin, &direction);
	intersect(&cylinder, &r, &xs);
	cr_assert(xs == NULL);

	cylinder = create_cylinder();
	t_hit	*xs1 = NULL;
	origin = point(0, 0, 0);
	v = vector(0, 1, 0);
	direction = normalize(&v);
	r = ray(&origin, &direction);
	intersect(&cylinder, &r, &xs1);
	cr_assert(xs1 == NULL);

	cylinder = create_cylinder();
	t_hit	*xs2 = NULL;
	origin = point(0, 0, -5);
	v = vector(1, 1, 1);
	direction = normalize(&v);
	r = ray(&origin, &direction);
	intersect(&cylinder, &r, &xs2);
	cr_assert(xs2 == NULL);
}

Test(cylinders, a_ray_hits_a_cylinder)
{
	t_shape cylinder;
	t_tuple origin;
	t_tuple v;
	t_hit	*xs;
	t_tuple direction;
	t_ray r;

	cylinder = create_cylinder();
	xs = NULL;
	origin = point(1, 0, -5);
	v = vector(0, 0, 1);
	direction = normalize(&v);
	r = ray(&origin, &direction);
	intersect(&cylinder, &r, &xs);
	cr_assert(are_equal_doubles(xs->t, 5.0));
	cr_assert(are_equal_doubles(xs->left->t, 5.0));

	cylinder = create_cylinder();
	xs = NULL;
	origin = point(0, 0, -5);
	v = vector(0, 0, 1);
	direction = normalize(&v);
	r = ray(&origin, &direction);
	intersect(&cylinder, &r, &xs);
	cr_assert(are_equal_doubles(xs->t, 4));
	cr_assert(are_equal_doubles(xs->left->t, 6));

	cylinder = create_cylinder();
	xs = NULL;
	origin = point(0.5, 0, -5);
	v = vector(0.1, 1, 1);
	direction = normalize(&v);
	r = ray(&origin, &direction);
	intersect(&cylinder, &r, &xs);
	cr_assert(are_equal_doubles(xs->t, 6.80798));
	cr_assert(are_equal_doubles(xs->left->t, 7.08872));
	cr_assert(true);
}