/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elements_into_camera_lightning.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:30:52 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/23 19:57:11 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	set_updated_transform(t_camera *camera, t_matrix *m)
{
	t_matrix	*m_old_transform;
	t_matrix	m_new_transform;

	m_old_transform = &camera->transform;
	m_new_transform = multiply_matrices(m, m_old_transform);
	set_transform_in_camera(camera, &m_new_transform);
}

static t_tuple	find_up(t_tuple *direction)
{
	t_tuple		y_axis_up;
	t_tuple		camera_right;
	t_tuple		up;

	y_axis_up = vector(0, 1, 0);
	camera_right = cross(direction, &y_axis_up);
	if (are_equal_doubles(camera_right.x, 0)
		&& are_equal_doubles(camera_right.y, 0)
		&& are_equal_doubles(camera_right.z, 0))
		camera_right = vector(1, 0, 0);
	up = cross(&camera_right, direction);
	return (up);
}

void	put_elements_into_camera(t_element *element, t_camera *cam)
{
	t_tuple		from;
	t_tuple		to;
	t_tuple		up;
	t_matrix	tr;

	*cam = camera(PCT_WIDTH, WIN_HEIGHT, element->fov);
	from = element->coordinates;
	to = add_tuples(&element->coordinates, &element->orientation);
	up = vector(0, 1, 0);
	up = find_up(&element->orientation);
	tr = view_transform(&from, &to, &up);
	set_updated_transform(cam, &tr);
}

void	put_elements_into_ambient(t_element *element, t_world *w)
{
	int	i;

	i = 0;
	while (i < w->nb_shapes)
	{
		w->shape[i].material.ambient = element->ambient_lightning_ratio;
		i++;
	}
	i = 0;
	while (i < w->nb_lights)
	{
		w->lights[i].intensity = multiply_colors(&w->lights[i].intensity, &element->color);
		i++;
	}
}

void	put_elements_into_light(t_element *element, int index, t_world *w)
{
	w->lights[index]
		= point_light(&element->light_intensity, &element->coordinates);
}
