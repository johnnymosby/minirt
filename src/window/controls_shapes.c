/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_shapes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:26:30 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/12 16:58:04 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "window.h"

t_shape	*find_clicked_shape(t_controls *controls, int x, int y)
{
	t_ray		r;
	t_camera	*c;
	t_hit		*hit;

	c = &controls->scene->camera;
	r = ray_for_pixel(c, x, y);
	hit = intersect_world(controls->scene->world, &r);
	while (hit && hit->t < 0)
		hit = hit->left;
	if (hit)
		return (hit->obj);
	else
		return (NULL);
}

void	change_shape_size(int keycode, t_controls *controls)
{
	t_matrix	m_scaled;
	t_matrix	*m_old_transform;
	t_matrix	m_new_transform;
	t_scene		*scene;

	scene = controls->scene;
	if (keycode == KEY_ZOOM_IN && scene->camera.field_of_view > -2.85)
	{
		m_scaled = scaling(1.1, 1.1, 1.1);
		m_old_transform = &controls->shape_in_control->transform;
		m_new_transform = multiply_matrices(m_old_transform, &m_scaled);
		set_transform(controls->shape_in_control, &m_new_transform);
		rerender(scene);
	}
	else if (keycode == KEY_ZOOM_OUT
		&& scene->camera.field_of_view < 2.85)
	{
		m_scaled = scaling(0.9, 0.9, 0.9);
		m_old_transform = &controls->shape_in_control->transform;
		m_new_transform = multiply_matrices(m_old_transform, &m_scaled);
		set_transform(controls->shape_in_control, &m_new_transform);
		rerender(scene);
	}
}
