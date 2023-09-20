/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:57:40 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/20 16:09:04 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rays.h"

t_ray	ray(t_tuple *origin, t_tuple *direction)
{
	t_ray	created_ray;

	created_ray.origin = *origin;
	created_ray.direction = *direction;
	return (created_ray);
}

t_tuple	position(t_ray *r, double t)
{
	t_tuple	product;

	product = multiply_tuple_by_scalar(&r->direction, t);
	return (add_tuples(&r->origin, &product));
}
