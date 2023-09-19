/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:22:41 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/19 18:08:49 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H

# include <stdbool.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include "libft.h"

# define EPSILON 0.001

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

/*
** ------------------------------- CREATING TUPLES ---------------------------
*/

t_tuple	tuple(double x, double y, double z, double w);
t_tuple	point(double x, double y, double z);
t_tuple	vector(double x, double y, double z);

/*
** ------------------------------- LOGICAL OPERATIONS ------------------------
*/

bool	are_equal_doubles(double a, double b);
bool	are_equal_tuples(t_tuple *a, t_tuple *b);

/*
** ------------------------------- ARITHMETIC OPERATIONS ---------------------
*/

t_tuple	add_tuples(t_tuple *a, t_tuple *b);
t_tuple	substract_tuples(t_tuple *a, t_tuple *b);
t_tuple	negate_tuple(t_tuple *a);
t_tuple	multiply_tuple_by_scalar(t_tuple *a, double sc);
t_tuple	divide_tuple_by_scalar(t_tuple *a, double sc);

/*
** ------------------------------- VECTORS' MANIPULATION ---------------------
*/

double	magnitude(t_tuple *a);
t_tuple	normalize(t_tuple *a);
double	dot(t_tuple *a, t_tuple *b);
t_tuple	cross(t_tuple *a, t_tuple *b);

#endif