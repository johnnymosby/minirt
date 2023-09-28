/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_world_ray.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:52:37 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/28 19:00:15 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_hit	**intersect_world(t_world *w, t_ray *ray)
{
	int		i;
	
	(void)ray;
	i = 0;
	while (i < w->nb_shapes)
	{
		(w->shape + i)->intersect(w->shape + i, ray, &w->xs);
		i++;
	}
	return (&w->xs);
}