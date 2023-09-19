/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:24:16 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/19 18:34:21 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICES_H
# define MATRICES_H

# include "tuples.h"

# define MAX_SIDE_SIZE 4
# define MAX_TOTAL_SIZE 16

typedef struct s_matrix
{
	double	table[MAX_SIDE_SIZE][MAX_SIDE_SIZE];
	int		side_size;
}	t_matrix;

// l - left, r - right
typedef struct s_shearing
{
	double	l;
	double	r;
}	t_shearing;

/*
** ------------------------------- MATRIX UTILS ------------------------------
*/

t_matrix	matrix(const double matrix[MAX_SIDE_SIZE][MAX_SIDE_SIZE],
				int side_size);
t_matrix	transpose(t_matrix m);
t_matrix	submatrix(t_matrix m, int row_to_remove, int col_to_remove);
t_matrix	inverse(t_matrix m);

/*
** ------------------------------- LOGICAL OPERATIONS ------------------------
*/

bool		are_equal_matrices(t_matrix a, t_matrix b);

/*
** ------------------------------- ARITHMETIC OPERATIONS ---------------------
*/

t_matrix	multiply_matrices(t_matrix a, t_matrix b);
t_tuple		multiply_matrix_by_tuple(t_matrix a, t_tuple *b);

/*
** ------------------------------- MATRIX PROPERTIES -------------------------
*/

double		determinant(t_matrix m);
double		minor(t_matrix m, int row, int col);
double		cofactor(t_matrix m, int row, int col);
bool		is_invertible(t_matrix m);

/*
** ------------------------------- MATRIX TRANSFORMATIONS --------------------
*/

t_matrix	translation(double x, double y, double z);
t_matrix	scaling(double x, double y, double z);
t_matrix	shearing(t_shearing x, t_shearing y, t_shearing z);

/*
** ------------------------------- MATRIX ROTATIONS --------------------------
*/

t_matrix	rotation_x(double r);
t_matrix	rotation_y(double r);
t_matrix	rotation_z(double r);

#endif