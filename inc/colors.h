/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:08:30 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/08/08 00:29:35 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include "tuples.h"

typedef struct s_color
{
	double	red;
	double	green;
	double	blue;
}	t_color;

/*
** ------------------------------- CREATING COLOR ----------------------------
*/

t_color	color(double red, double green, double blue);

/*
** ------------------------------- LOGICAL OPERATIONS ------------------------
*/

bool	are_equal_colors(t_color a, t_color b);

/*
** ------------------------------- ARITHMETIC OPERATIONS ---------------------
*/

t_color	add_colors(t_color a, t_color b);
t_color	substract_colors(t_color a, t_color b);
t_color	multiply_color_by_scalar(t_color a, double sc);
t_color	multiply_colors(t_color a, t_color b);

#endif