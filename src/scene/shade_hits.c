/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_hits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:14:35 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/03 19:34:02 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computations.h"

t_color shade_hit(t_world *world, t_comp *comps)
{
    t_lightning l;

    ft_bzero(&l, sizeof(t_lightning));
    l.material = &comps->object.material;
    l.light = world->lightning.light;
    l.point = &comps->point;
    l.eyev = &comps->eyev;
    l.normalv = &comps->normalv;
    return (lightning(&l));
}

t_color color_at(t_world *w, t_ray *r)
{
    t_color col;
    (void)  w;
    (void)  r;
    col = color(1, 1, 1);
    return (col);
}