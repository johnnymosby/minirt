/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_camera.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:25:31 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/12 16:26:11 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "window.h"

void	change_camera_zoom(int keycode, t_scene *scene)
{
	if (keycode == KEY_ZOOM_IN && scene->camera.field_of_view > -2.85)
	{
		scene->camera.field_of_view /= 1.1;
		rerender(scene);
	}
	else if (keycode == KEY_ZOOM_OUT
		&& scene->camera.field_of_view < 2.85)
	{
		scene->camera.field_of_view *= 1.1;
		rerender(scene);
	}
}
