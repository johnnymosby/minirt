/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_world_ray.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:52:37 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/27 10:49:57 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include "rays.h"
#include "shapes.h"

t_hit	**intersect_world(t_world *w, t_ray *ray)
{
	int		i;
	t_hit	**h;
	
	(void)ray;
	h = NULL;
	// initialise h to zero?
	i = 0;
	while (i < w->nb_shapes)
	{
		intersect(w->shape + i, ray, h);
		i++;
	}
	return (h);
}