/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_world_ray.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:52:37 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/18 18:29:33 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_hit	*intersect_world(t_world *w, t_ray *ray)
{
	int		i;

	i = 0;
	w->xs = NULL;
	while (i < w->nb_shapes)
	{
		intersect(w->shape + i, ray, &w->xs);
		i++;
	}
	return (w->xs);
}
