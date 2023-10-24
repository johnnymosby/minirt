/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinders.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:00:48 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/24 16:19:02 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

static void	swap_double(double *a, double *b)
{
	double	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static bool	discriminant(t_cylinder *cylinder, t_ray *r, t_disc_calc *d_calc)
{
	(void)cylinder;
	d_calc->a = pow(r->direction.x, 2) + pow(r->direction.z, 2);
	if (are_equal_doubles(d_calc->a, 0) == true)
		return (false);
	d_calc->b = 2 * r->origin.x * r->direction.x
		+ 2 * r->origin.z * r->direction.z;
	d_calc->c = pow(r->origin.x, 2) + pow(r->origin.z, 2) - 1;
	d_calc->dscr = pow(d_calc->b, 2) - 4 * d_calc->a * d_calc->c;
	return (true);
}

static bool	check_cap(t_ray *r, double t)
{
	double	x;
	double	z;

	x = r->origin.x + t * r->direction.x;
	z = r->origin.z + t * r->direction.z;
	return ((pow(x, 2) + pow(z, 2)) <= 1.0);
}

void	intersect_caps(t_hit **hits, t_shape *shape, t_ray *r)
{
	double	t;

	if (shape->cylinder.closed == false
		|| are_equal_doubles(r->direction.y, 0) == true)
		return ;
	t = (shape->cylinder.min - r->origin.y) / r->direction.y;
	if (check_cap(r, t))
		add_intersection(hits, intersection(t, shape));
	t = (shape->cylinder.max - r->origin.y) / r->direction.y;
	if (check_cap(r, t))
		add_intersection(hits, intersection(t, shape));
}

void	intersect_cylinder(t_shape *shape, t_ray *r, t_hit **hits)
{
	t_disc_calc	d_calc;
	double		d_squared;
	double		t[2];
	double		y[2];

	intersect_caps(hits, shape, r);
	if (discriminant(&shape->cylinder, r, &d_calc) == false)
		return ;
	if (d_calc.dscr < 0)
		return ;
	d_squared = sqrt(d_calc.dscr);
	t[0] = (-d_calc.b - d_squared) / (2 * d_calc.a);
	t[1] = (-d_calc.b + d_squared) / (2 * d_calc.a);
	if (t[0] > t[1])
		swap_double(t + 0, t + 1);
	y[0] = r->origin.y + t[0] * r->direction.y;
	y[1] = r->origin.y + t[1] * r->direction.y;
	if (shape->cylinder.min < y[0] && y[0] < shape->cylinder.max)
		add_intersection(hits, intersection(t[0], shape));
	if (shape->cylinder.min < y[1] && y[1] < shape->cylinder.max)
		add_intersection(hits, intersection(t[1], shape));
}
