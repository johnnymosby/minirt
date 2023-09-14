/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   properties.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:06:48 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/14 20:30:45 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

double	determinant(t_matrix m)
{
	if (m.side_size == 2)
	{
		return (m.table[0][0] * m.table[1][1] - m.table[0][1] * m.table[1][0]);
	}
	return (0);
}

double	minor(t_matrix m, int row, int col)
{
	return (determinant(submatrix(m, row, col)));
}
