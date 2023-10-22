/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elements_into_camera_lightning.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:30:52 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/22 19:18:04 by aguilmea         ###   ########.fr       */
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
	to = point(0, 0, 0);
	up = element->orientation;
	cam->transform = view_transform(&from, &to, &up);
	cam->inverse = inverse(&cam->transform);
	cam->original_transform = cam->transform;
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
