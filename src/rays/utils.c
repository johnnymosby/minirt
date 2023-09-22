/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:57:40 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/22 18:08:26 by rbasyrov         ###   ########.fr       */
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

t_hit	*hit(t_hit *xs, bool if_left_branch)
{
	if (if_left_branch)
	{
		while (xs && xs->t < 0)
			xs = xs->left;
	}
	else
	{
		while (xs && xs->t < 0)
			xs = xs->right;
	}
	return (xs);
}

t_ray	transform(t_ray *r, t_matrix *m)
{
	t_ray	transformed_ray;

	transformed_ray.origin = multiply_matrix_by_tuple(m, &r->origin);
	transformed_ray.direction = multiply_matrix_by_tuple(m, &r->direction);
	return (transformed_ray);
}
