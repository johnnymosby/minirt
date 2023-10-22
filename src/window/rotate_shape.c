/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_shape.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:23:34 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/22 13:34:35 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "shapes.h"

void	rotate_shape(int keycode, t_controls *controls)
{
	t_scene		*scene;
	t_matrix	m_rotated;

	if (controls->shape_in_control->shape_type == SPHERE)
		return ;
	scene = controls->scene;
	if (keycode == KEY_UP || keycode == KEY_DOWN)
		m_rotated = rotation_x(M_PI_4 / 4 * (1 - 2 * (keycode == KEY_UP)));
	else if (keycode == KEY_Q || keycode == KEY_E)
		m_rotated = rotation_z(M_PI_4 / 4 * (1 - 2 * (keycode == KEY_E)));
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		m_rotated = rotation_y(M_PI_4 / 4 * (1 - 2 * (keycode == KEY_RIGHT)));
	set_updated_transform_in_shape(controls, &m_rotated);
	rerender(scene);
}
