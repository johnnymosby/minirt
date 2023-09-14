/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:19:33 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/14 20:33:35 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

Test(matrices_creation, matrix_4_by_4)
{
	const double m_table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{1, 2, 3, 4},
		{5.5, 6.5, 7.5, 8.5},
		{9, 10, 11, 12},
		{13.5, 14.5, 15.5, 16.5}
	};
	t_matrix m = matrix(m_table, 4);

	cr_assert(are_equal_doubles(m.table[0][0], 1));
	cr_assert(are_equal_doubles(m.table[0][3], 4));
	cr_assert(are_equal_doubles(m.table[1][0], 5.5));
	cr_assert(are_equal_doubles(m.table[1][2], 7.5));
	cr_assert(are_equal_doubles(m.table[2][2], 11));
	cr_assert(are_equal_doubles(m.table[3][0], 13.5));

	cr_assert(are_equal_doubles(m.table[3][2], 15.5));
}

Test(matrices_creation, matrix_2_by_2)
{
	const double m_table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{-3, 5},
		{1, -2}
	};
	t_matrix m = matrix(m_table, 2);

	cr_assert(are_equal_doubles(m.table[0][0], -3));
	cr_assert(are_equal_doubles(m.table[0][1], 5));
	cr_assert(are_equal_doubles(m.table[1][0], 1));
	cr_assert(are_equal_doubles(m.table[1][1], -2));
}

Test(matrices_creation, matrix_3_by_3)
{
	const double m_table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{-3, 5, 0},
		{1, -2, -7},
		{0, 1, 1}
	};
	t_matrix m = matrix(m_table, 3);

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
	t_matrix a = matrix(a_table, 4);
	t_matrix b = matrix(b_table, 4);
	t_matrix c = matrix(c_table, 4);

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
	t_matrix a = matrix(a_table, 4);
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
	t_matrix a = matrix(a_table, 4);
	t_matrix I = matrix(I_table, 4);

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
	t_matrix a = matrix(a_table, 4);
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
	t_matrix a = matrix(a_table, 4);
	t_matrix b = matrix(b_table, 4);

	t_matrix product = transpose(a);
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
	t_matrix a = matrix(a_table, 4);

	t_matrix product = transpose(a);
	cr_assert(are_equal_matrices(product, a));
}

Test(matrices_properties, get_determinant_of_2_by_2)
{
	const double a_table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{1, 5},
		{-3, 2}
	};
	t_matrix a = matrix(a_table, 2);

	double product = determinant(a);
	cr_assert(are_equal_doubles(product, 17));
}

Test(matrices_properties, submatrix_of_3_by_3)
{
	const double a_table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{1, 5, 0},
		{-3, 2, 7},
		{0, 6, -3}
	};
	const double b_table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{-3, 2},
		{0, 6}
	};
	t_matrix a = matrix(a_table, 3);
	t_matrix b = matrix(b_table, 2);

	t_matrix product = submatrix(a, 0, 2);
	cr_assert(are_equal_matrices(product, b));
}

Test(matrices_properties, submatrix_of_4_by_4)
{
	const double a_table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{-6, 1, 1, 6},
		{-8, 5, 8, 6},
		{-1, 0, 8, 2},
		{-7, 1, -1, 1}
	};
	const double b_table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{-6, 1, 6},
		{-8, 8, 6},
		{-7, -1, 1}
	};
	t_matrix a = matrix(a_table, 4);
	t_matrix b = matrix(b_table, 3);

	t_matrix product = submatrix(a, 2, 1);
	cr_assert(are_equal_matrices(product, b));
}

Test(matrices_properties, minor_of_3_by_3)
{
	const double a_table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{3, 5, 0},
		{2, -1, -7},
		{6, -1, 5}
	};
	t_matrix A = matrix(a_table, 3);

	t_matrix B = submatrix(A, 1, 0);
	double d = determinant(B);
	double m = minor(A, 1, 0);
	cr_assert(are_equal_doubles(d, 25)
		&& are_equal_doubles(m, 25));
}
