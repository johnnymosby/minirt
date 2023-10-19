/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:00:17 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/19 11:48:41 by aguilmea         ###   ########.fr       */
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
	t_tuple		local_point;
	t_tuple		local_normal;
	t_tuple		world_normal;

	local_point = multiply_matrix_by_tuple(&shape->inverse, point);
	local_normal = shape->normal_at(shape, &local_point);
	world_normal = multiply_matrix_by_tuple(&shape->transform, &local_normal);
	world_normal.w = 0.0;
	return (normalize(&world_normal));
}
