/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:24:16 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/14 20:34:54 by rbasyrov         ###   ########.fr       */
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

t_matrix	matrix(const double matrix[MAX_SIDE_SIZE][MAX_SIDE_SIZE],
				int side_size);

/*
** ------------------------------- LOGICAL OPERATIONS ------------------------
*/
bool		are_equal_matrices(t_matrix a, t_matrix b);

/*
** ------------------------------- ARITHMETIC OPERATIONS ---------------------
*/

t_matrix	multiply_matrices(t_matrix a, t_matrix b);
t_tuple		multiply_matrix_by_tuple(t_matrix a, t_tuple b);

/*
** ------------------------------- MATRIX TRANSFORMATIONS --------------------
*/

t_matrix	transpose(t_matrix m);
t_matrix	submatrix(t_matrix m, int row_to_remove, int col_to_remove);

/*
** ------------------------------- MATRIX PROPERTIES -------------------------
*/

double		determinant(t_matrix m);
double		minor(t_matrix m, int row, int col);

#endif