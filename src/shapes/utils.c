/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:00:17 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/13 19:35:55 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

void	set_transform(t_shape *shape, t_matrix *m)
{
	shape->transform = *m;
	shape->inverse = inverse(m);
	shape->transpose = transpose(&shape->inverse);
}

void	set_shape_to_default(t_shape *shape)
{
	shape->transform = identity_matrix();
	shape->inverse = identity_matrix();
	shape->transpose = identity_matrix();
	set_material_to_default(&shape->material);
}

t_tuple	normal_at(t_shape *shape, t_tuple *point)
{
	/*t_matrix	m1;
	t_matrix	m2;
	t_tuple		world_normal;
	t_tuple		local_point;
	t_tuple		local_normal;

	m1 = inverse(&shape->transform);
	local_point = multiply_matrix_by_tuple(&m1, point);
	local_normal = shape->normal_at(shape, &local_point);
	m2 = transpose(&m1);
	world_normal = multiply_matrix_by_tuple(&m2, &local_normal);
	world_normal.w = 0;
	return (normalize(&world_normal));*/
	return (shape->normal_at(shape, point));
}
