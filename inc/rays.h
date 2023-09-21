/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:49:06 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/21 16:08:31 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H

# include "matrices.h"

# define MAX_INTERSECTIONS 256
# define MAX_HITS 16

typedef struct s_hit	t_hit;
typedef struct s_shape	t_shape;

typedef struct s_hit
{
	double	t[2];
	int		count;
	t_shape	*obj;
	t_hit	*next;
}	t_hit;

typedef struct s_intrs
{
	double	t;
	t_shape	*obj;
}	t_intrs;

//structure with memory pool for hits
typedef struct s_hpool
{
	t_hit	pool[MAX_HITS];
	int		last;
}	t_hpool;

//structure with memory pool for intersections
typedef struct s_ipool
{
	t_hit	pool[MAX_INTERSECTIONS];
	int		last;
}	t_ipool;

typedef struct s_ray
{
	t_tuple		origin;
	t_tuple		direction;
	t_hpool		*hits;
	t_ipool		*inters;
}	t_ray;

/*
** ------------------------------- RAYS' FUNCTIONS ---------------------------
*/

t_ray	ray(t_tuple *origin, t_tuple *direction);
t_tuple	position(t_ray *r, double t);

#endif