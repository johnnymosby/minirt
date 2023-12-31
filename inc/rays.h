/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:49:06 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/11 11:59:28 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H

# include "matrices.h"

# define MAX_INTERSECTIONS 256
# define MAX_HITS 7

typedef struct s_hit	t_hit;
typedef struct s_shape	t_shape;

typedef struct s_hit
{
	double	t;
	t_shape	*obj;
	t_hit	*prev;
	t_hit	*left;
	t_hit	*right;
	bool	is_shadowed;
}	t_hit;

typedef struct s_btree
{
	t_hit	root[MAX_INTERSECTIONS];
	int		last;
}	t_btree;

typedef struct s_ray
{
	t_tuple		origin;
	t_tuple		direction;
}	t_ray;

/*
** ------------------------------- RAYS' FUNCTIONS ---------------------------
*/

t_ray	ray(t_tuple *origin, t_tuple *direction);
t_tuple	position(t_ray *r, double t);
t_hit	*hit(t_hit *xs, bool if_left_branch);
t_ray	transform(t_ray *r, t_matrix *m);

#endif