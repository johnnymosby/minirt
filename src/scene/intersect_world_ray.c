/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_world_ray.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:52:37 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/29 15:44:38 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_hit	**intersect_world(t_world *w, t_ray *ray)
{
	int		i;
	
	i = 0;
	while (i < w->nb_shapes)
	{
		(w->shape + i)->intersect(w->shape + i, ray, &w->xs + i);
		i++;
	}
	return (&w->xs);
}