/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_camera.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:17:31 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/12 18:01:48 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "window.h"

static void	set_updated_transform_in_camera(t_controls *controls, t_matrix *m)
{
	t_matrix	*m_old_transform;
	t_matrix	m_new_transform;

	m_old_transform = &controls->scene->camera.transform;
	m_new_transform = multiply_matrices(m_old_transform, m);
	set_transform_in_camera(&controls->scene->camera, &m_new_transform);
}

void	translate_camera(int keycode, t_controls *controls)
{
	t_matrix	m_translated;
	t_scene		*scene;

	scene = controls->scene;
	if (keycode == KEY_W || keycode == KEY_S)
		m_translated = translation(0, 1 - 2 * (keycode == KEY_S), 0);
	else if (keycode == KEY_A || keycode == KEY_D)
		m_translated = translation(1 - 2 * (keycode == KEY_D), 0, 0);
	else if (keycode == KEY_SPACE || keycode == KEY_CTRL)
		m_translated = translation(0, 0, 1 - 2 * (keycode == KEY_CTRL));
	set_updated_transform_in_camera(controls, &m_translated);
	rerender(scene);
}
