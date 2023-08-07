/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_manipulation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 01:31:26 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/08/07 02:47:37 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

double	magnitude(t_tuple a)
{
	double	length;

	length = sqrt(a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w);
	return (length);
}

t_tuple	normalize(t_tuple a)
{
	double	length;

	length = magnitude(a);
	return (divide_tuple_by_scalar(a, length));
}

double	dot(t_tuple a, t_tuple b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}

t_tuple	cross(t_tuple a, t_tuple b)
{
	return (vector(
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x));
}
