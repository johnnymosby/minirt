/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elements_into_camera_lightning.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:30:52 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/23 11:38:22 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	put_elements_into_camera(t_element *element, t_camera *cam)
{
	t_tuple		from;
	t_tuple		to;
	t_tuple		up;

	*cam = camera(PCT_WIDTH, WIN_HEIGHT, element->fov);
	from = element->coordinates;
//	t_tuple inv;
//	inv = vector(-element->orientation.x, -element->orientation.y, -element->orientation.z);
//	to = add_tuples(&element->coordinates, &inv);
	to = add_tuples(&element->coordinates, &element->orientation);
	up = vector(0,1,0);
	cam->transform = view_transform(&from, &to, &up);
	cam->inverse = inverse(&cam->transform);
	cam->original_transform = cam->transform;
//	cam->inverse = view_transform(&from, &to, &up);
//	cam->original_transform = view_transform(&from, &to, &up);
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
