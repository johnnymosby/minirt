/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_camera.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:17:31 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/22 13:35:41 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "window.h"

void	set_updated_transform_in_camera(t_controls *controls, t_matrix *m)
{
	t_matrix	*m_old_transform;
	t_matrix	m_new_transform;

	m_old_transform = &controls->scene->camera.transform;
	m_new_transform = multiply_matrices(m, m_old_transform);
	set_transform_in_camera(&controls->scene->camera, &m_new_transform);
}

void	translate_camera(int keycode, t_controls *controls)
{
	t_matrix	m_translated;
	t_scene		*scene;
	t_tuple		original_direction;
	t_tuple		transformed_direction;

	scene = controls->scene;
	if (keycode == KEY_W || keycode == KEY_S)
		original_direction = vector(0, 0, 1 - 2 * (keycode == KEY_W));
	else if (keycode == KEY_A || keycode == KEY_D)
		original_direction = vector(1 - 2 * (keycode == KEY_D), 0, 0);
	else if (keycode == KEY_SPACE || keycode == KEY_CTRL)
		original_direction = vector(0, 1 - 2 * (keycode == KEY_SPACE), 0);
	transformed_direction
		= multiply_matrix_by_tuple(&controls->scene->camera.original_transform,
			&original_direction);
	m_translated = translation(transformed_direction.x,
			transformed_direction.y, transformed_direction.z);
	set_updated_transform_in_camera(controls, &m_translated);
	rerender(scene);
}
