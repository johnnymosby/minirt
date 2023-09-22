/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:22:57 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/22 18:26:38 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

t_matrix	matrix(const double matrix[MAX_SIDE_SIZE][MAX_SIDE_SIZE],
			int side_size)
{
	t_matrix	ret;

	ret.side_size = side_size;
	ft_memmove(ret.table, matrix, sizeof(double) * MAX_TOTAL_SIZE);
	return (ret);
}

t_matrix	identity_matrix(void)
{
	const double	table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
	{1, 0, 0, 0},
	{0, 1, 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}
	};

	return (matrix(table, MAX_SIDE_SIZE));
}

t_matrix	transpose(t_matrix *m)
{
	t_matrix	ret;
	int			x;
	int			y;

	x = 0;
	ret.side_size = m->side_size;
	while (x < MAX_SIDE_SIZE)
	{
		y = 0;
		while (y < MAX_SIDE_SIZE)
		{
			ret.table[x][y] = m->table[y][x];
			y++;
		}
		x++;
	}
	return (ret);
}

t_matrix	submatrix(t_matrix *m, int row_to_remove, int col_to_remove)
{
	t_matrix	ret;
	int			row;
	int			col;

	ft_bzero(&ret, sizeof(t_matrix));
	if (m->side_size < 1 || m->side_size > 4)
		return (ret);
	row = 0;
	ret.side_size = m->side_size - 1;
	while (row < ret.side_size)
	{
		col = 0;
		while (col < ret.side_size)
		{
			ret.table[row][col]
				= m->table[row + (row >= row_to_remove)] \
					[col + (col >= col_to_remove)];
			col++;
		}
		row++;
	}
	return (ret);
}

t_matrix	inverse(t_matrix *m)
{
	double		det;
	t_matrix	ret;
	int			row;
	int			col;

	det = determinant(m);
	if (det == 0)
		return (ft_bzero(&ret, sizeof(t_matrix)), ret);
	ret.side_size = m->side_size;
	row = 0;
	while (row < m->side_size)
	{
		col = 0;
		while (col < m->side_size)
		{
			ret.table[col][row] = cofactor(m, row, col) / determinant(m);
			col++;
		}
		row++;
	}
	return (ret);
}
