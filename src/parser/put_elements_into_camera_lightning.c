/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elements_into_camera_lightning.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:30:52 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/20 18:58:54 by aguilmea         ###   ########.fr       */
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

void	put_elements_into_lightning(t_element *element, int index, t_world *w)
{
	if (element->element_type == ELMT_AMBIENT)
	{
		//it makes no difference 
		//what the ambient value is (ratio or color) - why?
		w->lightning.material->ambient = element->ambient_lightning_ratio;
		w->lightning.material->color = element->color;
	}
	else if (element->element_type == ELMT_LIGHT)
		w->lights[index]
			= point_light(&element->light_intensity, &element->coordinates);
}
