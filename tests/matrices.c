/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:19:33 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/19 20:16:25 by aguilmea         ###   ########.fr       */
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

	cr_assert(are_equal_matrices(&a, &b));
	cr_assert(!are_equal_matrices(&a, &c));
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

	t_tuple product = multiply_matrix_by_tuple(&a, &b);

	cr_assert(are_equal_tuples(&product, &c));
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

	t_matrix product = multiply_matrices(&a, &I);

	cr_assert(are_equal_matrices(&product, &a));
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

	t_tuple product = multiply_matrix_by_tuple(&a, &b);

	cr_assert(are_equal_tuples(&product, &b));
}

Test(matrices_utils, transpose_matrix)
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

	t_matrix product = transpose(&a);
	cr_assert(are_equal_matrices(&product, &b));
}

Test(matrices_utils, transpose_identity_matrix)
{
	const double a_table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{1, 0, 0, 0},
		{0, 1, 0, 0},
		{0, 0, 1, 0},
		{0, 0, 0, 1}
	};
	t_matrix a = matrix(a_table, 4);

	t_matrix product = transpose(&a);
	cr_assert(are_equal_matrices(&product, &a));
}

Test(matrices_properties, get_determinant_of_2_by_2)
{
	const double a_table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{1, 5},
		{-3, 2}
	};
	t_matrix a = matrix(a_table, 2);

	double product = determinant(&a);
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

	t_matrix product = submatrix(&a, 0, 2);
	cr_assert(are_equal_matrices(&product, &b));
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

	t_matrix product = submatrix(&a, 2, 1);
	cr_assert(are_equal_matrices(&product, &b));
}

Test(matrices_properties, minor_of_3_by_3)
{
	const double a_table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{3, 5, 0},
		{2, -1, -7},
		{6, -1, 5}
	};
	t_matrix A = matrix(a_table, 3);

	t_matrix B = submatrix(&A, 1, 0);
	double d = determinant(&B);
	double m = minor(&A, 1, 0);
	cr_assert(are_equal_doubles(d, 25)
		&& are_equal_doubles(m, 25));
}

Test(matrices_properties, cofactor_of_3_by_3)
{
	const double a_table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{3, 5, 0},
		{2, -1, -7},
		{6, -1, 5}
	};
	t_matrix A = matrix(a_table, 3);

	double minor_0 = minor(&A, 0, 0);
	double cofactor_0 = cofactor(&A, 0, 0);
	double minor_1 = minor(&A, 1, 0);
	double cofactor_1 = cofactor(&A, 1, 0);
	cr_assert(are_equal_doubles(minor_0, -12));
	cr_assert(are_equal_doubles(cofactor_0, -12));
	cr_assert(are_equal_doubles(minor_1, 25));
	cr_assert(are_equal_doubles(cofactor_1, -25));
}

Test(matrices_properties, get_determinant_of_3_by_3)
{
	const double a_table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{1, 2, 6},
		{-5, 8, -4},
		{2, 6, 4}
	};
	t_matrix A = matrix(a_table, 3);

	double cofactor_0 = cofactor(&A, 0, 0);
	double cofactor_1 = cofactor(&A, 0, 1);
	double cofactor_2 = cofactor(&A, 0, 2);
	double det = determinant(&A);
	cr_assert(are_equal_doubles(cofactor_0, 56));
	cr_assert(are_equal_doubles(cofactor_1, 12));
	cr_assert(are_equal_doubles(cofactor_2, -46));
	cr_assert(are_equal_doubles(det, -196));
}

Test(matrices_properties, is_invertible)
{
	const double a_table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{6, 4, 4, 4},
		{5, 5, 7, 6},
		{4, -9, 3, -7},
		{9, 1, 7, -6}
	};
	t_matrix A = matrix(a_table, 4);

	double det_A = determinant(&A);
	bool A_is_invertible = is_invertible(&A);
	cr_assert(are_equal_doubles(det_A, -2120));
	cr_assert(A_is_invertible == true);

	const double b_table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{-4, 2, -2, -3},
		{9, 6, 2, 6},
		{0, -5, 1, -5},
		{0, 0, 0, 0}
	};
	t_matrix B = matrix(b_table, 4);

	double det_B = determinant(&B);
	bool B_is_invertible = is_invertible(&B);
	cr_assert(are_equal_doubles(det_B, 0));
	cr_assert(B_is_invertible == false);
}

Test(matrices_inverse, inverse_0)
{
	const double a_table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{-5, 2, 6, -8},
		{1, -5, 1, 8},
		{7, 7, -6, -7},
		{1, -3, 7, 4}
	};
	t_matrix A = matrix(a_table, 4);
	t_matrix B = inverse(&A);

	const double c_table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{0.21805, 0.45113, 0.24060, -0.04511},
		{-0.80827, -1.45677, -0.44361, 0.52068},
		{-0.07895, -0.22368, -0.05263, 0.19737},
		{-0.52256, -0.81391, -0.30075, 0.30639}
	};
	t_matrix C = matrix(c_table, 4);

	double det_A = determinant(&A);
	double cofactor_0 = cofactor(&A, 2, 3);
	double cofactor_1 = cofactor(&A, 3, 2);
	cr_assert(are_equal_doubles(det_A, 532));
	cr_assert(are_equal_doubles(cofactor_0, -160));
	cr_assert(are_equal_doubles(B.table[3][2], (double) -160 / 532));
	cr_assert(are_equal_doubles(cofactor_1, 105));
	cr_assert(are_equal_doubles(B.table[2][3], (double) 105 / 532));
	cr_assert(B.side_size == 4);
	cr_assert(are_equal_matrices(&B, &C));
}

Test(matrices_inverse, inverse_1)
{
	const double a_table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{8, -5, 9, 2},
		{7, 5, 6, 1},
		{-6, 0, 9, 6},
		{-3, 0, -9, -4}
	};
	t_matrix A = matrix(a_table, 4);
	t_matrix B = inverse(&A);

	const double c_table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{-0.15385, -0.15385, -0.28205, -0.53846},
		{-0.07692, 0.12308, 0.02564, 0.03077},
		{0.35897, 0.35897, 0.43590, 0.92308},
		{-0.69231, -0.69231, -0.76923, -1.92308}
	};
	t_matrix C = matrix(c_table, 4);

	cr_assert(are_equal_matrices(&B, &C));
}

Test(matrices_inverse, inverse_2)
{
	const double a_table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{3, -9, 7, 3},
		{3, -8, 2, -9},
		{-4, 4, 4, 1},
		{-6, 5, -1, 1}
	};
	t_matrix A = matrix(a_table, 4);
	const double b_table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
		{8, 2, 2, 2},
		{3, -1, 7, 0},
		{7, 0, 5, 4},
		{6, -2, 0, 5}
	};
	t_matrix B = matrix(b_table, 4);
	t_matrix C = multiply_matrices(&A, &B);
	t_matrix B_inverted = inverse(&B);
	t_matrix mult = multiply_matrices(&C, &B_inverted);
	cr_assert(are_equal_matrices(&mult, &A));
}
