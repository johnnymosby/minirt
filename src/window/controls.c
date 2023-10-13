/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:00:25 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/13 14:58:41 by rbasyrov         ###   ########.fr       */
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
