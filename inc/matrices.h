/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:24:16 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/14 16:22:31 by rbasyrov         ###   ########.fr       */
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
	int		total_size;
}	t_matrix;

t_matrix	create_matrix(const double matrix[MAX_SIDE_SIZE][MAX_SIDE_SIZE],
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

t_matrix	transpose_matrix(t_matrix m);

#endif