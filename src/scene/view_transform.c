/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:26:24 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/06 16:59:27 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

static t_tuple	calculate_forward(t_tuple *from, t_tuple *to)
{
	t_tuple	difference;

	difference = substract_tuples(to, from);
	return (normalize(&difference));
}

static t_matrix	orientation(t_tuple *left, t_tuple *true_up,
						t_tuple *forward)
{
	const double	table[MAX_SIDE_SIZE][MAX_SIDE_SIZE] = {
	{left->x, left->y, left->z, 0},
	{true_up->x, true_up->y, true_up->z, 0},
	{-forward->x, -forward->y, -forward->z, 0},
	{0, 0, 0, 1}
	};

	return (matrix(table, MAX_SIDE_SIZE));
}

static t_matrix	calculate_orientation(t_tuple *from, t_tuple *to, t_tuple *up)
{
	t_tuple	forward;
	t_tuple	upn;
	t_tuple	left;
	t_tuple	true_up;

	forward = calculate_forward(from, to);
	upn = normalize(up);
	left = cross(&forward, &upn);
	true_up = cross(&left, &forward);
	return (orientation(&left, &true_up, &forward));
}

t_matrix	view_transform(t_tuple *from, t_tuple *to, t_tuple *up)
{
	t_matrix	orientated_m;
	t_matrix	translated_m;

	orientated_m = calculate_orientation(from, to, up);
	translated_m = translation(-from->x, -from->y, -from->z);
	return (multiply_matrices(&orientated_m, &translated_m));
}
