/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_shape.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:23:34 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/24 01:18:32 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "shapes.h"

void	rotate_shape(int keycode, t_controls *controls)
{
	t_scene		*scene;
	t_matrix	m_rotated;
	t_matrix	*m_old_transform;
	t_matrix	m_new_transform;

	if (controls->shape_in_control->shape_type == SPHERE)
		return ;
	scene = controls->scene;
	if (keycode == KEY_UP || keycode == KEY_DOWN)
		m_rotated = rotation_x(M_PI_4 / 4 * (1 - 2 * (keycode == KEY_UP)));
	else if (keycode == KEY_Q || keycode == KEY_E)
		m_rotated = rotation_z(M_PI_4 / 4 * (1 - 2 * (keycode == KEY_E)));
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		m_rotated = rotation_y(M_PI_4 / 4 * (1 - 2 * (keycode == KEY_RIGHT)));
	m_old_transform = &controls->shape_in_control->transform;
	m_new_transform = multiply_matrices(m_old_transform, &m_rotated);
	set_transform(controls->shape_in_control, &m_new_transform);
	rerender(scene);
}
