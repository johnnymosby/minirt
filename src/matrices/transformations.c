/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:22:57 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/14 16:41:03 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

t_matrix	transpose_matrix(t_matrix m)
{
	t_matrix	ret;
	int			x;
	int			y;

	x = 0;
	ret.side_size = m.side_size;
	while (x < MAX_SIDE_SIZE)
	{
		y = 0;
		while (y < MAX_SIDE_SIZE)
		{
			ret.table[x][y] = m.table[y][x];
			y++;
		}
		x++;
	}
	return (ret);
}
