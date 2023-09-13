/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:24:16 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/13 15:44:08 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICES_H
# define MATRICES_H

# include "tuples.h"

# define SIDE_SIZE 4
# define MATRIX_FULL_SIZE 16

typedef struct s_matrix
{
	double	table[SIDE_SIZE][SIDE_SIZE];
	int		size;
}	t_matrix;

t_matrix	create_matrix(const double matrix[SIDE_SIZE][SIDE_SIZE], int size);

#endif