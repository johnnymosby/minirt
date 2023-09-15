/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:45:02 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/15 17:18:45 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

t_matrix	translation(double x, double y, double z)
{
	const double	table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
	{1, 0, 0, x},
	{0, 1, 0, y},
	{0, 0, 1, z},
	{0, 0, 0, 1}
	};

	return (matrix(table, MAX_SIDE_SIZE));
}

t_matrix	scaling(double x, double y, double z)
{
	const double	table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
	{1, 0, 0, x},
	{0, 1, 0, y},
	{0, 0, 1, z},
	{0, 0, 0, 1}
	};

	return (matrix(table, MAX_SIDE_SIZE));
}

