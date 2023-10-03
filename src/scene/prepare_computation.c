/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_computation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:24:21 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/03 17:57:26 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computations.h"

t_comp prepare_computations(t_hit *intersection, t_ray *ray)
{
    t_comp comps;

    ft_bzero(&comps, sizeof(t_comp));
    comps.t = intersection->t;
    comps.object = *intersection->obj;
    comps.point = position(ray, comps.t);
    comps.eyev = negate_tuple(&ray->direction);
    comps.normalv = normal_at_sphere(&comps.object, &comps.point);
    // normal_at will be refactored for all shapesin chapter 9
    if (dot(&comps.normalv, &comps.eyev) < 0.0)
    {
        comps.inside = true;
        comps.normalv = negate_tuple(&comps.normalv);
    }
    else
        comps.inside = false;
    return (comps);
}
