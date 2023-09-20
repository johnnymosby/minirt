/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:51:29 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/20 15:37:42 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# include "rays.h"

typedef struct s_sphere
{
	t_tuple	origin;
	double	radius;
}	t_sphere;

typedef enum e_shape_type
{
	SPHERE
}	t_shape_type;

typedef struct s_shape
{
	union {
		t_sphere	sphere;
	};
	t_shape_type	shape_type;
}	t_shape;

#endif