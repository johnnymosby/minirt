/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:51:29 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/21 15:17:40 by rbasyrov         ###   ########.fr       */
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

typedef struct s_shape
{
	union {
		t_sphere	sphere;
	};
	t_shape_type	shape_type;
}	t_shape;

/*
** ------------------------------- SPHERES' FUNCTIONS ------------------------
*/

t_shape	create_sphere(void);
t_hit	intersect_sphere(t_shape *sphere, t_ray *r);
t_intrs	intersection(double t, t_shape *shape);

#endif