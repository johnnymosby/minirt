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

Test(cylinders, normal_vector_on_a_cylinder)
{
	t_shape cylinder;
	t_tuple p;
	t_tuple v;
	t_tuple n;

	cylinder = create_cylinder();
	p = point(1, 0, 0);
	n = cylinder.normal_at(&cylinder, &p);
	v = vector(1, 0, 0);
	cr_assert(are_equal_tuples(&n, &v));

	p = point(0, 5, -1);
	n = cylinder.normal_at(&cylinder, &p);
	v = vector(0, 0, -1);
	cr_assert(are_equal_tuples(&n, &v));

	p = point(0, -2, 1);
	n = cylinder.normal_at(&cylinder, &p);
	v = vector(0, 0, 1);
	cr_assert(are_equal_tuples(&n, &v));

	p = point(-1, 1, 0);
	n = cylinder.normal_at(&cylinder, &p);
	v = vector(-1, 0, 0);
	cr_assert(are_equal_tuples(&n, &v));
}


Test(cylinders, the_default_minimum_and_maximum_for_a_cylinder)
{
	t_shape cyl;

	cyl = create_cylinder();
	cr_assert(cyl.cylinder.max == INFINITY);
	cr_assert(cyl.cylinder.min == -INFINITY);
}

Test(cylinders, intersecting_constrained_cylinder)
{
	t_shape cyl;
	t_tuple v;
	t_tuple direction;
	t_ray r;
	t_tuple p;
	t_hit	*xs;

	cyl = create_cylinder();
	cyl.cylinder.min = 1;
	cyl.cylinder.max = 2;

	p = point(0, 1.5, 0);
	v = vector(0.1, 1, 0);
	direction = normalize(&v);
	r = ray(&p, &direction);
	xs = NULL;
	intersect(&cyl, &r, &xs);
	cr_assert(xs == NULL);

	p = point(0, 3, -5);
	v = vector(0, 0, 1);
	direction = normalize(&v);
	r = ray(&p, &direction);
	xs = NULL;
	intersect(&cyl, &r, &xs);
	cr_assert(xs == NULL);

	p = point(0, 0, -5);
	direction = normalize(&v);
	r = ray(&p, &direction);
	xs = NULL;
	intersect(&cyl, &r, &xs);
	cr_assert(xs == NULL);

	p = point(0, 2, -5);
	direction = normalize(&v);
	r = ray(&p, &direction);
	xs = NULL;
	intersect(&cyl, &r, &xs);
	cr_assert(xs == NULL);

	p = point(0, 1, -5);
	direction = normalize(&v);
	r = ray(&p, &direction);
	xs = NULL;
	intersect(&cyl, &r, &xs);
	cr_assert(xs == NULL);

	p = point(0, 1.5, -2);
	direction = normalize(&v);
	r = ray(&p, &direction);
	xs = NULL;
	intersect(&cyl, &r, &xs);
	cr_assert(count_intersections(xs, true) == 2);
}

Test(cylinders, the_default_closed_value_for_a_cylinder)
{
	t_shape cyl;

	cyl = create_cylinder();
	cr_assert(cyl.cylinder.closed == false);
}

Test(cylinders, intersect_the_caps_of_a_closed_cylinder)
{
	t_shape cyl;
	t_tuple	v;
	t_tuple	direction;
	t_tuple	p;
	t_ray	r;
	t_hit	*xs;

	cyl = create_cylinder();
	cyl.cylinder.min = 1;
	cyl.cylinder.max = 2;
	cyl.cylinder.closed = true;

	p = point(0, 3, 0);
	v = vector(0, -1, 0);
	direction = normalize(&v);
	r = ray(&p, &direction);
	xs = NULL;
	intersect(&cyl, &r, &xs);
	cr_assert(count_intersections(xs, true) == 2);

	p = point(0, 3, -2);
	v = vector(0, -1, 2);
	direction = normalize(&v);
	r = ray(&p, &direction);
	xs = NULL;
	intersect(&cyl, &r, &xs);
	cr_assert(count_intersections(xs, true) == 2);

	p = point(0, 4, -2);
	v = vector(0, -1, 1);
	direction = normalize(&v);
	r = ray(&p, &direction);
	xs = NULL;
	intersect(&cyl, &r, &xs);
	cr_assert(count_intersections(xs, true) == 2);

	p = point(0, 0, -2);
	v = vector(0, 1, 2);
	direction = normalize(&v);
	r = ray(&p, &direction);
	xs = NULL;
	intersect(&cyl, &r, &xs);
	cr_assert(count_intersections(xs, true) == 2);

	p = point(0, -1, -2);
	v = vector(0, 1, 1);
	direction = normalize(&v);
	r = ray(&p, &direction);
	xs = NULL;
	intersect(&cyl, &r, &xs);
	cr_assert(count_intersections(xs, true) == 2);
}

Test(cylinders, the_normal_vector_on_a_cylinders_end_caps)
{
	t_shape cyl;
	t_tuple	v;
	t_tuple	p;
	t_tuple	n;

	cyl = create_cylinder();
	cyl.cylinder.min = 1;
	cyl.cylinder.max = 2;
	cyl.cylinder.closed = true;

	p = point(0, 1, 0);
	n = cyl.normal_at(&cyl, &p);
	v = vector(0, -1, 0);
	cr_assert(are_equal_tuples(&n, &v));

	p = point(0.5, 1, 0);
	n = cyl.normal_at(&cyl, &p);
	v = vector(0, -1, 0);
	cr_assert(are_equal_tuples(&n, &v));

	p = point(0, 1, 0.5);
	n = cyl.normal_at(&cyl, &p);
	v = vector(0, -1, 0);
	cr_assert(are_equal_tuples(&n, &v));

	p = point(0, 2, 0);
	n = cyl.normal_at(&cyl, &p);
	v = vector(0, 1, 0);
	cr_assert(are_equal_tuples(&n, &v));

	p = point(0.5, 2, 0);
	n = cyl.normal_at(&cyl, &p);
	v = vector(0, 1, 0);
	cr_assert(are_equal_tuples(&n, &v));

	p = point(0, 2, 0.5);
	n = cyl.normal_at(&cyl, &p);
	v = vector(0, 1, 0);
	cr_assert(are_equal_tuples(&n, &v));
}
