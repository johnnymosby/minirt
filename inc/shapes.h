/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:51:29 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/13 19:34:26 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# include "rays.h"
# include "light.h"

typedef enum e_shape_type
{
	SPHERE,
	CYLINDER
}	t_shape_type;

typedef struct s_sphere
{
	t_tuple	origin;
	double	radius;
	t_tuple	null_point;
}	t_sphere;

typedef struct s_cylinder
{
	t_tuple	origin;
	double	radius;
	float	max;
	float	min;
	bool	closed;
}	t_cylinder;

typedef struct s_cube
{
	t_tuple	origin;
	double	radius;
	float	max;
	float	min;
	bool	closed;
}	t_cube;

typedef struct s_disc_calc
{
	double	a;
	double	b;
	double	c;
	double	dscr;
}	t_disc_calc;

typedef void	(*t_intersect)(t_shape *, t_ray *, t_hit **);
typedef t_tuple	(*t_normal_at)(t_shape *, t_tuple *);

typedef struct s_material
{
	double	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
	t_color	color;
	t_color	original_color;
}	t_material;

typedef struct s_shape
{
	union {
		t_sphere	sphere;
		t_cylinder	cylinder;
	};
	t_shape_type	shape_type;
	t_intersect		intersect;
	t_normal_at		normal_at;
	t_matrix		transform;
	t_matrix		inverse;
	t_matrix		transpose;
	t_material		material;
	t_matrix		original_transform;
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
t_tuple	normal_at_sphere(t_shape *shape, t_tuple *point);

/*
** ------------------------------- CYLINDERS' FUNCTIONS ----------------------
*/

t_shape	create_cylinder(void);

/*
** ------------------------------- PLANES' FUNCTIONS --------------------------
*/

t_shape	create_plane(void);

/*
** ------------------------------- UTILS -------------------------------------
*/

void	set_transform(t_shape *shape, t_matrix *m);
void	set_shape_to_default(t_shape *shape);
t_tuple	normal_at(t_shape *shape, t_tuple *point);

/*
** ------------------------------- REFLECTION ---------------------------------
*/

t_tuple	reflect(t_tuple *v, t_tuple *n);

/*
** ------------------------------- MATERIAL -----------------------------------
*/
bool	are_equal_materials(t_material *mtrl1, t_material *mtrl2);
void	set_material_to_default(t_material *material);

#endif