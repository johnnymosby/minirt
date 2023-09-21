/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:21:49 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/21 15:29:28 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

t_intrs	intersection(double t, t_shape *shape)
{
	t_intrs	intrs;

	intrs.t = t;
	intrs.obj = shape;
	return (intrs);
}

t_hit	intersections(t_intrs *i1, t_intrs *i2)
{
	t_hit	hit;

	hit.t[0] = i
	intrs.t = t;
	intrs.obj = shape;
	return (intrs);
}

void	add_intersection(t_ipool *hits, t_hit *hit)
{
	hits->pool[hits->last % MAX_INTERSECTIONS] = *hit;
	hits->last++;
}
