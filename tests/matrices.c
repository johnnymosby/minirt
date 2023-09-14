/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:19:33 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/14 16:47:39 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

Test(matrices_creation, create_matrix_4_by_4)
{
	const double matrix[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{1, 2, 3, 4},
		{5.5, 6.5, 7.5, 8.5},
		{9, 10, 11, 12},
		{13.5, 14.5, 15.5, 16.5}
	};
	t_matrix m = create_matrix(matrix, 4);

	cr_assert(are_equal_doubles(m.table[0][0], 1));
	cr_assert(are_equal_doubles(m.table[0][3], 4));
	cr_assert(are_equal_doubles(m.table[1][0], 5.5));
	cr_assert(are_equal_doubles(m.table[1][2], 7.5));
	cr_assert(are_equal_doubles(m.table[2][2], 11));
	cr_assert(are_equal_doubles(m.table[3][0], 13.5));

	cr_assert(are_equal_doubles(m.table[3][2], 15.5));
}

Test(matrices_creation, create_matrix_2_by_2)
{
	const double matrix[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{-3, 5},
		{1, -2}
	};
	t_matrix m = create_matrix(matrix, 2);

	cr_assert(are_equal_doubles(m.table[0][0], -3));
	cr_assert(are_equal_doubles(m.table[0][1], 5));
	cr_assert(are_equal_doubles(m.table[1][0], 1));
	cr_assert(are_equal_doubles(m.table[1][1], -2));
}

Test(matrices_creation, create_matrix_3_by_3)
{
	const double matrix[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{-3, 5, 0},
		{1, -2, -7},
		{0, 1, 1}
	};
	t_matrix m = create_matrix(matrix, 3);

	cr_assert(are_equal_doubles(m.table[0][0], -3));
	cr_assert(are_equal_doubles(m.table[1][1], -2));
	cr_assert(are_equal_doubles(m.table[2][2], 1));
}

Test(matrices_logical_operations, are_equal_matrices)
{
	const double a_table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 8, 7, 6},
		{5, 4, 3, 2}
	};
	const double b_table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 8, 7, 6},
		{5, 4, 3, 2}
	};
	const double c_table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{2, 3, 4, 5},
		{6, 7, 8, 9},
		{8, 7, 6, 5},
		{4, 3, 2, 1}
	};
	t_matrix a = create_matrix(a_table, 4);
	t_matrix b = create_matrix(b_table, 4);
	t_matrix c = create_matrix(c_table, 4);

	cr_assert(are_equal_matrices(a, b));
	cr_assert(!are_equal_matrices(a, c));
}

Test(matrices_arithmetic_operations, multiply_matrix_by_tuple)
{
	const double a_table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{1, 2, 3, 4},
		{2, 4, 4, 2},
		{8, 6, 4, 1},
		{0, 0, 0, 1}
	};
	t_matrix a = create_matrix(a_table, 4);
	t_tuple b = tuple(1, 2, 3, 1);
	t_tuple c = tuple(18, 24, 33, 1);

	t_tuple product = multiply_matrix_by_tuple(a, b);

	cr_assert(are_equal_tuples(product, c));
}

Test(matrices_arithmetic_operations, multiply_matrix_by_identity_matrix)
{
	const double a_table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{0, 1, 2, 4},
		{1, 2, 4, 8},
		{2, 4, 8, 16},
		{4, 8, 16, 32}
	};
	const double I_table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	};
	t_matrix a = create_matrix(a_table, 4);
	t_matrix I = create_matrix(I_table, 4);

	t_matrix product = multiply_matrices(a, I);

	cr_assert(are_equal_matrices(product, a));
}

Test(matrices_arithmetic_operations, multiply_identity_matrix_by_tuple)
{
	const double a_table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	};
	t_matrix a = create_matrix(a_table, 4);
	t_tuple b = tuple(1, 2, 3, 4);

	t_tuple product = multiply_matrix_by_tuple(a, b);

	cr_assert(are_equal_tuples(product, b));
}

Test(matrices_transformations, transpose_matrix)
{
	const double a_table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{0, 9, 3, 0},
		{9, 8, 0, 8},
		{1, 8, 5, 3},
		{0, 0, 5, 8}
	};
	const double b_table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{0, 9, 1, 0},
		{9, 8, 8, 0},
		{3, 0, 5, 5},
		{0, 8, 3, 8}
	};
	t_matrix a = create_matrix(a_table, 4);
	t_matrix b = create_matrix(b_table, 4);

	t_matrix product = transpose_matrix(a);
	cr_assert(are_equal_matrices(product, b));
}

Test(matrices_transformations, transpose_identity_matrix)
{
	const double a_table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	};
	t_matrix a = create_matrix(a_table, 4);

	t_matrix product = transpose_matrix(a);
	cr_assert(are_equal_matrices(product, a));
}
