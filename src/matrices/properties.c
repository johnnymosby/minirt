/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   properties.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:06:48 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/15 14:48:14 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

double	determinant(t_matrix m)
{
	double	det;
	int		col;

	if (m.side_size == 2)
		return (m.table[0][0] * m.table[1][1] - m.table[0][1] * m.table[1][0]);
	det = 0;
	col = 0;
	while (col < m.side_size)
	{
		det += (m.table[0][col] * cofactor(m, 0, col));
		col++;
	}
	return (det);
}

double	minor(t_matrix m, int row, int col)
{
	return (determinant(submatrix(m, row, col)));
}

double	cofactor(t_matrix m, int row, int col)
{
	return (minor(m, row, col) * pow(-1, row + col));
}

bool	is_invertible(t_matrix m)
{
	if (determinant(m) != 0)
		return (true);
	else
		return (false);
}
