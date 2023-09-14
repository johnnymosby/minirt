/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:38:03 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/14 14:22:47 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

/*
** ------------------------------- CREATING TUPLES ---------------------------
*/

Test(tuples, is_point)
{
	t_tuple a = tuple(4.3, -4.2, 3.1, 1.0);

	cr_assert(are_equal_doubles(a.x, 4.3));
	cr_assert(are_equal_doubles(a.y, -4.2));
	cr_assert(are_equal_doubles(a.z, 3.1));
	cr_assert(are_equal_doubles(a.w, 1.0), "The tuple is not a point");
}

Test(tuples, is_vector)
{
	t_tuple a = tuple(4.3, -4.2, 3.1, 0.0);

	cr_assert(are_equal_doubles(a.x, 4.3));
	cr_assert(are_equal_doubles(a.y, -4.2));
	cr_assert(are_equal_doubles(a.z, 3.1));
	cr_assert(are_equal_doubles(a.w, 0.0), "The tuple is not a vector");
}

Test(tuples, create_point)
{
	t_tuple a = point(4.3, -4.2, 3.1);

	cr_assert(a.x == 4.3);
	cr_assert(a.y == -4.2);
	cr_assert(a.z == 3.1);
	cr_assert(a.w == 1.0, "The tuple is not a point");
}

Test(tuples, create_vector)
{
	t_tuple a = vector(4.3, -4.2, 3.1);

	cr_assert(a.x == 4.3);
	cr_assert(a.y == -4.2);
	cr_assert(a.z == 3.1);
	cr_assert(a.w == 0.0, "The tuple is not a vector");
}

/*
** ------------------------------- ARITHMETIC OPERATIONS ---------------------
*/

Test(tuples, add_tuples)
{
	t_tuple a1 = tuple(3, -2, 5, 1);
	t_tuple a2 = tuple(-2, 3, 1, 0);
	t_tuple a3 = add_tuples(a1, a2);
	t_tuple a4 = tuple(1, 1, 6, 1);

	cr_assert(are_equal_tuples(a3, a4), "The tuples are not equal");
}

Test(tuples, substract_points)
{
	t_tuple p1 = point(3, 2, 1);
	t_tuple p2 = point(5, 6, 7);
	t_tuple v1 = substract_tuples(p1, p2);
	t_tuple v2 = vector(-2, -4, -6);

	cr_assert(are_equal_tuples(v1, v2), "The tuples are not equal");
}

Test(tuples, substract_point_and_vector)
{
	t_tuple p1 = point(3, 2, 1);
	t_tuple v = vector(5, 6, 7);
	t_tuple p2 = substract_tuples(p1, v);
	t_tuple p3 = point(-2, -4, -6);

	cr_assert(are_equal_tuples(p2, p3), "The tuples are not equal");
}

Test(tuples, substract_vectors)
{
	t_tuple v1 = vector(3, 2, 1);
	t_tuple v2 = vector(5, 6, 7);
	t_tuple v3 = substract_tuples(v1, v2);
	t_tuple v4 = vector(-2, -4, -6);

	cr_assert(are_equal_tuples(v3, v4), "The tuples are not equal");
}

Test(tuples, substract_zero_vector_and_vector)
{
	t_tuple zero = vector(0, 0, 0);
	t_tuple v = vector(1, -2, 3);
	t_tuple v1 = substract_tuples(zero, v);
	t_tuple v2 = vector(-1, 2, -3);

	cr_assert(are_equal_tuples(v1, v2), "The tuples are not equal");
}

Test(tuples, negate_tuple)
{
	t_tuple a1 = tuple(1, -2, 3, -4);
	t_tuple a2 = negate_tuple(a1);
	t_tuple a3 = tuple(-1, 2, -3, 4);

	cr_assert(are_equal_tuples(a2, a3), "The tuples are not equal");
}

Test(tuples, multiply_tuple_by_scalar)
{
	t_tuple a1 = tuple(1, -2, 3, -4);
	double	sc1 = 3.5;
	t_tuple a2 = multiply_tuple_by_scalar(a1, sc1);
	t_tuple a3 = tuple(3.5, -7, 10.5, -14);

	cr_assert(are_equal_tuples(a2, a3), "The tuples are not equal");

	double	sc2 = 0.5;
	t_tuple a4 = multiply_tuple_by_scalar(a1, sc2);
	t_tuple a5 = tuple(0.5, -1, 1.5, -2);
	cr_assert(are_equal_tuples(a4, a5), "The tuples are not equal");
}

Test(tuples, divide_tuple_by_scalar)
{
	t_tuple a1 = tuple(1, -2, 3, -4);
	double	sc = 2;
	t_tuple a2 = divide_tuple_by_scalar(a1, sc);
	t_tuple a3 = tuple(0.5, -1, 1.5, -2);

	cr_assert(are_equal_tuples(a2, a3), "The tuples are not equal");
}

/*
** ------------------------------- VECTORS' MANIPULATION ---------------------
*/

Test(tuples, magnitude)
{
	t_tuple v1 = vector(1, 0, 0);
	t_tuple v2 = vector(0, 1, 0);
	t_tuple v3 = vector(0, 0, 1);

	cr_assert(are_equal_doubles(magnitude(v1), 1.0), "The doubles are not equal");
	cr_assert(are_equal_doubles(magnitude(v2), 1.0), "The doubles are not equal");
	cr_assert(are_equal_doubles(magnitude(v3), 1.0), "The doubles are not equal");

	t_tuple v4 = vector(1, 2, 3);
	cr_assert(are_equal_doubles(magnitude(v4), sqrt(14)), "The doubles are not equal");

	t_tuple v5 = vector(-1, -2, -3);
	cr_assert(are_equal_doubles(magnitude(v5), sqrt(14)), "The doubles are not equal");
}

Test(tuples, normalize)
{
	t_tuple v1 = vector(4, 0, 0);
	t_tuple v2 = vector(1, 0, 0);

	cr_assert(are_equal_tuples(normalize(v1), v2), "The tuples are not equal");

	t_tuple v3 = vector(1, 2, 3);
	t_tuple v4 = vector(0.26726, 0.53452, 0.80178);
	cr_assert(are_equal_tuples(normalize(v3), v4), "The tuples are not equal");

	t_tuple v5 = vector(1, 2, 3);
	t_tuple norm = normalize(v5);
	cr_assert(are_equal_doubles(magnitude(norm), 1.0), "The doubles are not equal");
}

Test(tuples, dot)
{
	t_tuple a = vector(1, 2, 3);
	t_tuple b = vector(2, 3, 4);

	cr_assert(are_equal_doubles(dot(a, b), 20.0), "The doubles are not equal");
}

Test(tuples, cross)
{
	t_tuple a = vector(1, 2, 3);
	t_tuple b = vector(2, 3, 4);

	t_tuple v1 = vector(-1, 2, -1);
	t_tuple v2 = vector(1, -2, 1);

	cr_assert(are_equal_tuples(cross(a, b), v1), "The tuples are not equal");
	cr_assert(are_equal_tuples(cross(b, a), v2), "The tuples are not equal");
}
