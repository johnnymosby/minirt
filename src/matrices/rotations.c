/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:56:45 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/15 18:11:51 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

t_matrix	rotation_x(double r)
{
	const double	table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
	{1, 0, 0, 0},
	{0, cos(r), -sin(r), 0},
	{0, sin(r), cos(r), 0},
	{0, 0, 0, 1}
	};

	return (matrix(table, MAX_SIDE_SIZE));
}

t_matrix	rotation_y(double r)
{
	const double	table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
	{cos(r), 0, sin(r), 0},
	{0, 1, 0, 0},
	{-sin(r), 0, cos(r), 0},
	{0, 0, 0, 1}
	};

	return (matrix(table, MAX_SIDE_SIZE));
}

t_matrix	rotation_z(double r)
{
	const double	table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
	{cos(r), -sin(r), 0, 0},
	{sin(r), cos(r), 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}
	};

	return (matrix(table, MAX_SIDE_SIZE));
}
