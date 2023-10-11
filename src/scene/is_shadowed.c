/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_shadowed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:47:17 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/11 12:42:36 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computations.h"

bool	is_shadowed(t_world *world, t_tuple *point)
{
	t_tuple	v;
	t_tuple	direction;
	t_ray	r;
	t_hit	*intersections;
	t_hit	*h;

	v = substract_tuples(&world->lights[0].position, point);
	direction = normalize(&v);
	r = ray(point, &direction);
	intersections = intersect_world(world, &r);
	h = hit(intersections, true);
	if ((h != NULL) && (h->t < magnitude(&v)))
		return (true);
	else
		return (false);
}
