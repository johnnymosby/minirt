/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:58:35 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/20 12:55:35 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

Test(mx_transformations_translation, multiply_by_translation_mx)
{
	t_tuple p = point(-3, 4, 5);
	t_matrix transform = translation(5, -3, 2);

	t_tuple product = multiply_matrix_by_tuple(&transform, &p);
	t_tuple p_answer = point(2, 1, 7);

	cr_assert(are_equal_tuples(&product, &p_answer));
}

Test(mx_transformations_translation, multiply_by_inverse_of_translation_mx)
{
	t_tuple p = point(-3, 4, 5);
	t_matrix transform = translation(5, -3, 2);
	t_matrix inv = inverse(&transform);

	t_tuple product = multiply_matrix_by_tuple(&inv, &p);
	t_tuple p_answer = point(-8, 7, 3);

	cr_assert(are_equal_tuples(&product, &p_answer));
}

Test(mx_transformations_translation, multiply_by_translation_of_vec)
{
	t_tuple v = vector(-3, 4, 5);
	t_matrix transform = translation(5, -3, 2);

	t_tuple product = multiply_matrix_by_tuple(&transform, &v);

	cr_assert(are_equal_tuples(&product, &v));
}


Test(mx_transformations_scaling, scale_point)
{
	t_tuple p = point(-4, 6, 8);
	t_matrix transform = scaling(2, 3, 4);

	t_tuple product = multiply_matrix_by_tuple(&transform, &p);
	t_tuple p_answer = point(-8, 18, 32);

	cr_assert(are_equal_tuples(&product, &p_answer));
}

Test(mx_transformations_scaling, scale_vector)
{
	t_tuple v = vector(-4, 6, 8);
	t_matrix transform = scaling(2, 3, 4);

	t_tuple product = multiply_matrix_by_tuple(&transform, &v);
	t_tuple v_answer = vector(-8, 18, 32);

	cr_assert(are_equal_tuples(&product, &v_answer));
}

Test(mx_transformations_scaling, scale_vector_inversely)
{
	t_tuple v = vector(-4, 6, 8);
	t_matrix transform = scaling(2, 3, 4);
	t_matrix inv = inverse(&transform);

	t_tuple product = multiply_matrix_by_tuple(&inv, &v);
	t_tuple v_answer = vector(-2, 2, 2);

	cr_assert(are_equal_tuples(&product, &v_answer));
}

Test(mx_transformations_scaling, reflection)
{
	t_matrix transform = scaling(-1, 1, 1);
	t_tuple p = point(2, 3, 4);

	t_tuple product = multiply_matrix_by_tuple(&transform, &p);
	t_tuple p_answer = point(-2, 3, 4);

	cr_assert(are_equal_tuples(&product, &p_answer));
}

Test(mx_transformations_rotation, rotation_x)
{
	t_tuple p = point(0, 1, 0);
	t_matrix half_quarter = rotation_x(M_PI / 4);
	t_matrix full_quarter = rotation_x(M_PI / 2);

	t_tuple product_0 = multiply_matrix_by_tuple(&half_quarter, &p);
	t_tuple product_1 = multiply_matrix_by_tuple(&full_quarter, &p);

	t_tuple p_answer_0 = point(0, sqrt(2) / 2, sqrt(2) / 2);
	t_tuple p_answer_1 = point(0, 0, 1);

	cr_assert(are_equal_tuples(&product_0, &p_answer_0));
	cr_assert(are_equal_tuples(&product_1, &p_answer_1));
}

Test(mx_transformations_rotation, rotation_x_inversely)
{
	t_tuple p = point(0, 1, 0);
	t_matrix half_quarter = rotation_x(M_PI / 4);
	t_matrix inv = inverse(&half_quarter);

	t_tuple product = multiply_matrix_by_tuple(&inv, &p);
	t_tuple p_answer = point(0, sqrt(2) / 2, - sqrt(2) / 2);

	cr_assert(are_equal_tuples(&product, &p_answer));
}

Test(mx_transformations_rotation, rotation_y)
{
	t_tuple p = point(0, 0, 1);
	t_matrix half_quarter = rotation_y(M_PI / 4);
	t_matrix full_quarter = rotation_y(M_PI / 2);

	t_tuple product_0 = multiply_matrix_by_tuple(&half_quarter, &p);
	t_tuple product_1 = multiply_matrix_by_tuple(&full_quarter, &p);

	t_tuple p_answer_0 = point(sqrt(2) / 2, 0, sqrt(2) / 2);
	t_tuple p_answer_1 = point(1, 0, 0);
	cr_assert(are_equal_tuples(&product_0, &p_answer_0));
	cr_assert(are_equal_tuples(&product_1, &p_answer_1));
}

Test(mx_transformations_rotation, rotation_z)
{
	t_tuple p = point(0, 1, 0);
	t_matrix half_quarter = rotation_z(M_PI / 4);
	t_matrix full_quarter = rotation_z(M_PI / 2);

	t_tuple product_0 = multiply_matrix_by_tuple(&half_quarter, &p);
	t_tuple product_1 = multiply_matrix_by_tuple(&full_quarter, &p);

	t_tuple p_answer_0 = point(-sqrt(2) / 2, sqrt(2) / 2, 0);
	t_tuple p_answer_1 = point(-1, 0, 0);

	cr_assert(are_equal_tuples(&product_0, &p_answer_0));
	cr_assert(are_equal_tuples(&product_1, &p_answer_1));
}

Test(mx_transformations_shearing, x_relative_to_y)
{
	t_shearing	x = {1, 0};
	t_shearing	y = {0, 0};
	t_shearing	z = {0, 0};
	t_matrix transform = shearing(&x, &y, &z);
	t_tuple p = point(2, 3, 4);

	t_tuple product = multiply_matrix_by_tuple(&transform, &p);
	t_tuple p_answer = point(5, 3, 4);

	cr_assert(are_equal_tuples(&product, &p_answer));
}

Test(mx_transformations_shearing, x_relative_to_z)
{
	t_shearing	x = {0, 1};
	t_shearing	y = {0, 0};
	t_shearing	z = {0, 0};
	t_matrix transform = shearing(&x, &y, &z);
	t_tuple p = point(2, 3, 4);

	t_tuple product = multiply_matrix_by_tuple(&transform, &p);
	t_tuple p_answer = point(6, 3, 4);

	cr_assert(are_equal_tuples(&product, &p_answer));
}

Test(mx_transformations_shearing, y_relative_to_x)
{
	t_shearing	x = {0, 0};
	t_shearing	y = {1, 0};
	t_shearing	z = {0, 0};
	t_matrix transform = shearing(&x, &y, &z);
	t_tuple p = point(2, 3, 4);

	t_tuple product = multiply_matrix_by_tuple(&transform, &p);
	t_tuple p_answer = point(2, 5, 4);

	cr_assert(are_equal_tuples(&product, &p_answer));
}

Test(mx_transformations_shearing, y_relative_to_z)
{
	t_shearing	x = {0, 0};
	t_shearing	y = {0, 1};
	t_shearing	z = {0, 0};
	t_matrix transform = shearing(&x, &y, &z);
	t_tuple p = point(2, 3, 4);

	t_tuple product = multiply_matrix_by_tuple(&transform, &p);
	t_tuple p_answer = point(2, 7, 4);

	cr_assert(are_equal_tuples(&product, &p_answer));
}

Test(mx_transformations_shearing, z_relative_to_x)
{
	t_shearing	x = {0, 0};
	t_shearing	y = {0, 0};
	t_shearing	z = {1, 0};
	t_matrix transform = shearing(&x, &y, &z);
	t_tuple p = point(2, 3, 4);

	t_tuple product = multiply_matrix_by_tuple(&transform, &p);

	t_tuple p_answer = point(2, 3, 6);

	cr_assert(are_equal_tuples(&product, &p_answer));
}

Test(mx_transformations_shearing, z_relative_to_y)
{
	t_shearing	x = {0, 0};
	t_shearing	y = {0, 0};
	t_shearing	z = {0, 1};
	t_matrix transform = shearing(&x, &y, &z);
	t_tuple p = point(2, 3, 4);

	t_tuple product = multiply_matrix_by_tuple(&transform, &p);
	t_tuple p_answer = point(2, 3, 7);

	cr_assert(are_equal_tuples(&product, &p_answer));
}

Test(mx_transformations_chaining, in_sequence)
{
	t_tuple p0 = point(1, 0, 1);
	t_matrix A = rotation_x(M_PI / 2);
	t_matrix B = scaling(5, 5, 5);
	t_matrix C = translation(10, 5, 7);

	
	t_tuple p1 = multiply_matrix_by_tuple(&A, &p0);
	t_tuple p_answer_1 = point(1, -1, 0);
	cr_assert(are_equal_tuples(&p1, &p_answer_1));


	t_tuple p2 = multiply_matrix_by_tuple(&B, &p1);
	t_tuple p_answer_2 = point(5, -5, 0);
	cr_assert(are_equal_tuples(&p2, &p_answer_2));

	t_tuple p3 = multiply_matrix_by_tuple(&C, &p2);
	t_tuple p_answer_3 = point(15, 0, 7);
	cr_assert(are_equal_tuples(&p3, &p_answer_3));

}