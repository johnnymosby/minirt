/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:51:02 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/13 15:18:47 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "window.h"

void	rotate_camera(int keycode, t_controls *controls)
{
	t_scene		*scene;
	t_matrix	m_rotated;

	scene = controls->scene;
	if (keycode == KEY_UP || keycode == KEY_DOWN)
		m_rotated = rotation_x(M_PI_4 / 4 * (1 - 2 * (keycode == KEY_UP)));
	else if (keycode == KEY_Q || keycode == KEY_E)
		m_rotated = rotation_z(M_PI_4 / 4 * (1 - 2 * (keycode == KEY_E)));
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		m_rotated = rotation_y(M_PI_4 / 4 * (1 - 2 * (keycode == KEY_RIGHT)));
	set_updated_transform_in_camera(controls, &m_rotated);
	rerender(scene);
}
