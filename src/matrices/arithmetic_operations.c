/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:52:22 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/14 17:15:59 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

t_tuple	multiply_matrix_by_tuple(t_matrix a, t_tuple b)
{
	int		i;
	t_tuple	ret;
	t_tuple	row_a;

	i = 0;
	row_a = (t_tuple){a.table[i][0], a.table[i][1], a.table[i][2],
		a.table[i][3]};
	ret.x = dot(row_a, b);
	i = 1;
	row_a = (t_tuple){a.table[i][0], a.table[i][1], a.table[i][2],
		a.table[i][3]};
	ret.y = dot(row_a, b);
	i = 2;
	row_a = (t_tuple){a.table[i][0], a.table[i][1], a.table[i][2],
		a.table[i][3]};
	ret.z = dot(row_a, b);
	i = 3;
	row_a = (t_tuple){a.table[i][0], a.table[i][1], a.table[i][2],
		a.table[i][3]};
	ret.w = dot(row_a, b);
	return (ret);
}

t_matrix	multiply_matrices(t_matrix a, t_matrix b)
{
	int			row;
	int			col;
	t_matrix	ret;
	t_tuple		row_a;
	t_tuple		col_b;

	row = 0;
	ret.side_size = MAX_TOTAL_SIZE;
	while (row < MAX_SIDE_SIZE)
	{
		col = 0;
		while (col < MAX_SIDE_SIZE)
		{
			row_a = (t_tuple){a.table[row][0], a.table[row][1], a.table[row][2],
				a.table[row][3]};
			col_b = (t_tuple){b.table[0][col], b.table[1][col], b.table[2][col],
				b.table[3][col]};
			ret.table[row][col] = dot(row_a, col_b);
			col++;
		}
		row++;
	}
	return (ret);
}
