/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:00:25 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/13 16:10:07 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "window.h"

static void	reset_to_default(t_controls *controls)
{
	if (controls->shape_in_control != NULL)
	{
		controls->shape_in_control->material.color
			= controls->shape_in_control->material.original_color;
		controls->shape_in_control = NULL;
		controls->control_state = CAMERA;
	}
}

void	respond_to_left_click(t_controls *controls, int x, int y)
{
	t_shape	*shape;

	shape = find_clicked_shape(controls, x, y);
	if (shape != NULL && shape != controls->shape_in_control)
	{
		reset_to_default(controls);
		controls->shape_in_control = shape;
		controls->shape_in_control->material.original_color
			= controls->shape_in_control->material.color;
		controls->shape_in_control->material.color = color(1, 0, 0);
		controls->control_state = SHAPE;
	}
	else
	{
		reset_to_default(controls);
	}
	rerender(controls->scene);
}

void	respond_to_right_click(t_controls *controls)
{
	if (controls->shape_in_control != NULL)
	{
		reset_to_default(controls);
		rerender(controls->scene);
	}
	controls->control_state = CAMERA;
}

void	translate_light(int keycode, t_controls *controls)
{
	t_light	*light;

	reset_to_default(controls);
	controls->control_state = LIGHT;
	light = controls->scene->world->lights + 0;
	if (keycode == KEY_W || keycode == KEY_S)
		light->position.z += 1 - 2 * (keycode == KEY_S);
	else if (keycode == KEY_A || keycode == KEY_D)
		light->position.x += 1 - 2 * (keycode == KEY_A);
	else if (keycode == KEY_SPACE || keycode == KEY_CTRL)
		light->position.y += 1 - 2 * (keycode == KEY_CTRL);
	rerender(controls->scene);
}
