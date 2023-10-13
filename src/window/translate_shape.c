/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_shape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:24:20 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/13 16:19:34 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "shapes.h"
#include "camera.h"

void	set_updated_transform_in_shape(t_controls *controls, t_matrix *m)
{
	t_matrix	*m_old_transform;
	t_matrix	m_new_transform;

	m_old_transform = &controls->shape_in_control->transform;
	m_new_transform = multiply_matrices(m, m_old_transform);
	set_transform(controls->shape_in_control, &m_new_transform);
}

/* static void	translate_cylinder(int keycode, t_controls *controls)
{
	t_cylinder	*cylinder;

	cylinder = &controls->shape_in_control->cylinder;
	if (keycode == KEY_W || keycode == KEY_S)
		cylinder->origin.z += 1 - 2 * (keycode == KEY_S);
	else if (keycode == KEY_A || keycode == KEY_D)
		cylinder->origin.x += 1 - 2 * (keycode == KEY_A);
	else if (keycode == KEY_SPACE || keycode == KEY_CTRL)
		cylinder->origin.y += 1 - 2 * (keycode == KEY_CTRL);
	rerender(controls->scene);
} */

void	translate_shape(int keycode, t_controls *controls)
{
	t_matrix	m_translated;
	t_scene		*scene;
	t_tuple		original_direction;
	t_tuple		transformed_direction;

/* 	if (controls->shape_in_control->shape_type == CYLINDER)
		return (translate_cylinder(keycode, controls)); */
	scene = controls->scene;
	if (keycode == KEY_W || keycode == KEY_S)
		original_direction = vector(0, 0, 1 - 2 * (keycode == KEY_W));
	else if (keycode == KEY_A || keycode == KEY_D)
		original_direction = vector(1 - 2 * (keycode == KEY_D), 0, 0);
	else if (keycode == KEY_SPACE || keycode == KEY_CTRL)
		original_direction = vector(0, 1 - 2 * (keycode == KEY_CTRL), 0);
	transformed_direction
		= multiply_matrix_by_tuple(&controls->scene->camera.original_transform,
			&original_direction);
	m_translated = translation(transformed_direction.x,
			transformed_direction.y, transformed_direction.z);
	set_updated_transform_in_shape(controls, &m_translated);
	rerender(scene);
}
