/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:25:56 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/14 15:23:37 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

t_matrix	create_matrix(const double matrix[MAX_SIDE_SIZE][MAX_SIDE_SIZE],
			int side_size)
{
	t_matrix	ret;

	ret.total_size = side_size;
	ft_memmove(ret.table, matrix, sizeof(double) * MAX_TOTAL_SIZE);
	return (ret);
}
