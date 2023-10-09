/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:21:49 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/09 15:51:29 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

// void	initialise_variables()

t_hit	*intersection(double t, t_shape *shape)
{
	static t_btree	tree;
	t_hit			*hit;

	hit = tree.root + tree.last++ % MAX_INTERSECTIONS;
	hit->left = NULL;
	hit->right = NULL;
	hit->obj = shape;
	hit->t = t;
	return (hit);
}

void	intersect(t_shape *shape, t_ray *r, t_hit **hits)
{
	t_ray		transformed_ray;

	transformed_ray = transform(r, &shape->inverse);
	shape->intersect(shape, &transformed_ray, hits);
}

void	add_intersection(t_hit **hits, t_hit *intrs)
{
	t_hit	*prev;
	t_hit	*this;

	prev = NULL;
	this = *hits;
	if (!(this && this->t < intrs->t))
	{
		intrs->left = *hits;
		*hits = intrs;
		return ;
	}
	while (this && this->t < intrs->t)
	{
		prev = this;
		this = this->left;
	}
	intrs->prev = prev;
	prev->left = intrs;
	intrs->left = this;
}

int	count_intersections(t_hit *xs, bool if_left_branch)
{
	int	n;

	n = 0;
	if (if_left_branch == true)
	{
		while (xs)
		{
			n++;
			xs = xs->left;
		}
	}
	else
	{
		while (xs)
		{
			n++;
			xs = xs->right;
		}
	}
	return (n);
}
