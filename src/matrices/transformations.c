/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:45:02 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/19 19:42:06 by aguilmea         ###   ########.fr       */
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
	{x, 0, 0, 0},
	{0, y, 0, 0},
	{0, 0, z, 0},
	{0, 0, 0, 1}
	};

	return (matrix(table, MAX_SIDE_SIZE));
}

t_matrix	shearing(t_shearing *x, t_shearing *y, t_shearing *z)
{
	const double	table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
	{1, x->l, x->r, 0},
	{y->l, 1, y->r, 0},
	{z->l, z->r, 1, 0},
	{0, 0, 0, 1}
	};

	return (matrix(table, MAX_SIDE_SIZE));
}
