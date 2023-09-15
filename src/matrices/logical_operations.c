/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:11:54 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/15 15:42:01 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

bool	are_equal_matrices(t_matrix a, t_matrix b)
{
	int	row;
	int	col;

	if (a.side_size != b.side_size)
		return (false);
	row = 0;
	while (row < a.side_size)
	{
		col = 0;
		while (col < a.side_size)
		{
			if (are_equal_doubles(a.table[row][col], b.table[row][col])
				== false)
				return (false);
			col++;
		}
		row++;
	}
	return (true);
}
