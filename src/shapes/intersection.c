/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:21:49 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/21 18:12:07 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

t_hit	*intersection(double t, t_shape *shape)
{
	static t_btree	tree;
	t_hit			*hit;

	if (tree.last == MAX_INTERSECTIONS - 1)
		return (NULL);
	hit = tree.root + tree.last++;
	hit->left == NULL;
	hit->right == NULL;
	hit->obj = shape;
	hit->t = t;
	return (hit);
}

t_hit	intersect(t_shape *shape, t_ray *r, t_hit **hits)
{
	t_hit	*hit;

	hit = shape->intersect(shape, r, hits);
	return ();
}

t_hit	*add_intersection(t_hit *hit)
{

	
	hits->pool[hits->last % MAX_INTERSECTIONS] = *hit;
	hits->last++;
}
