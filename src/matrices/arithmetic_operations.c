/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:52:22 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/19 18:36:20 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

t_tuple	multiply_matrix_by_tuple(t_matrix a, t_tuple *b)
{
	int		i;
	t_tuple	ret;
	t_tuple	row_a;

	i = 0;
	row_a = (t_tuple){a.table[i][0], a.table[i][1], a.table[i][2],
		a.table[i][3]};
	ret.x = dot(&row_a, b);
	i = 1;
	row_a = (t_tuple){a.table[i][0], a.table[i][1], a.table[i][2],
		a.table[i][3]};
	ret.y = dot(&row_a, b);
	i = 2;
	row_a = (t_tuple){a.table[i][0], a.table[i][1], a.table[i][2],
		a.table[i][3]};
	ret.z = dot(&row_a, b);
	i = 3;
	row_a = (t_tuple){a.table[i][0], a.table[i][1], a.table[i][2],
		a.table[i][3]};
	ret.w = dot(&row_a, b);
	return (ret);
}

t_matrix	multiply_matrices(t_matrix a, t_matrix b)
{
	int			row;
	int			col;
	t_matrix	ret;
	t_tuple		row_a;
	t_tuple		col_b;

	if (a.side_size != b.side_size)
		return (ft_bzero(&ret, sizeof(t_matrix)), ret);
	ret.side_size = a.side_size;
	row = 0;
	while (row < a.side_size)
	{
		col = 0;
		while (col < a.side_size)
		{
			row_a = (t_tuple){a.table[row][0], a.table[row][1], a.table[row][2],
				a.table[row][3]};
			col_b = (t_tuple){b.table[0][col], b.table[1][col], b.table[2][col],
				b.table[3][col]};
			ret.table[row][col] = dot(&row_a, &col_b);
			col++;
		}
		row++;
	}
	return (ret);
}
