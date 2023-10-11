/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinders.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:00:48 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/11 17:52:10 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

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

void	intersect_cylinder(t_shape *shape, t_ray *r, t_hit **hits)
{
	t_disc_calc	d_calc;
	double		d_squared;
	double		t[2];
	t_hit		*intrs[2];

	(void)hits;
	if (discriminant(&shape->cylinder, r, &d_calc) == false)
		return ;
	if (d_calc.dscr < 0)
		return ;
	else if (d_calc.dscr >= 0)
	{
		d_squared = sqrt(d_calc.dscr);
		t[0] = (-d_calc.b - d_squared) / (2 * d_calc.a);
		t[1] = (-d_calc.b + d_squared) / (2 * d_calc.a);
		intrs[0] = intersection(t[0], shape);
		intrs[1] = intersection(t[1], shape);
		intrs[0]->left = intrs[1];
		intrs[1]->prev = intrs[0];
		add_intersection(hits, intrs[0]);
		add_intersection(hits, intrs[1]);
	}
}

t_shape	create_cylinder(void)
{
	t_shape	shape;

	set_shape_to_default(&shape);
	shape.intersect = intersect_cylinder;
	return (shape);
}
