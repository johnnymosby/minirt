/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:21:09 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/24 17:58:50 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	calculate_angles(t_tuple *direction, double *x, double *z)
{
	double	x_projection;
	double	z_projection;

	x_projection = sqrt((direction->z * direction->z)
			+ (direction->y * direction->y));
	z_projection = sqrt((direction->x * direction->x)
			+ (direction->y * direction->y));
	if ((direction->x * direction->y) >= 0)
		*z = acos(x_projection);
	else
		*z = acos(x_projection) - M_PI_2;
	if ((direction->z * direction->y) >= 0)
		*x = acos(z_projection);
	else
		*x = acos(z_projection) - M_PI_2;
}

t_matrix	calculate_rotation(t_tuple *direction)
{
	double		x_angle;
	double		z_angle;
	t_matrix	m_rotated_z;
	t_matrix	m_rotated_x;

	calculate_angles(direction, &x_angle, &z_angle);
	m_rotated_z = rotation_z(z_angle);
	m_rotated_x = rotation_x(x_angle);
	return (multiply_matrices(&m_rotated_x, &m_rotated_z));
}
