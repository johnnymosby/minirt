/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade_hits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:14:35 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/06 14:42:02 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computations.h"

t_color	shade_hit(t_world *world, t_comp *comps)
{
	t_lightning	l;

	ft_bzero(&l, sizeof(t_lightning));
	l.material = &comps->object.material;
	l.light = world->lights;
	l.point = &comps->point;
	l.eyev = &comps->eyev;
	l.normalv = &comps->normalv;
	return (lightning(&l));
}

t_color	color_at(t_world *w, t_ray *r)
{
	t_color	col;
	t_hit	*h;
	t_comp	comps;

	printf("test 1\n");
	intersect_world(w, r);
	printf("test 2\n");
	h = hit(w->xs, true);
	printf("test 3\n");
	printf("%p\n", h);
	printf("test 4\n");
	if (h == NULL)
	{
		printf("test 5a\n");
		col = color(0.0, 0.0, 0.0);
		printf("test 5a\n");
	}
	else
	{
		printf("test 5a\n");
		comps = prepare_computations(h, r);
		col = shade_hit(w, &comps);
	}
	printf("test 6\n");
	return (col);
}
