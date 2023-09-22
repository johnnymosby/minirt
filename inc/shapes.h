/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:51:29 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/22 18:20:17 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# include "rays.h"

typedef enum e_shape_type
{
	SPHERE
}	t_shape_type;

typedef struct s_sphere
{
	t_tuple	origin;
	double	radius;
}	t_sphere;

typedef struct s_disc_calc
{
	double	a;
	double	b;
	double	c;
	double	dscr;
}	t_disc_calc;

typedef void	(*t_intersect)(t_shape *, t_ray *, t_hit **);

typedef struct s_shape
{
	union {
		t_sphere	sphere;
	};
	t_shape_type	shape_type;
	t_intersect		intersect;
	t_matrix		transform;
}	t_shape;

/*
** ------------------------------- INTERSECTION ------------------------------
*/

void	add_intersection(t_hit **hits, t_hit *intrs);
t_hit	*intersection(double t, t_shape *shape);
void	intersect(t_shape *shape, t_ray *r, t_hit **hits);
int		count_intersections(t_hit *xs, bool if_left_branch);

/*
** ------------------------------- SPHERES' FUNCTIONS ------------------------
*/

t_shape	create_sphere(void);
void	intersect_sphere(t_shape *sphere, t_ray *r, t_hit **hits);

#endif