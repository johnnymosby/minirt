/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elements_into_camera_lightning.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:30:52 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/18 19:29:35 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	put_elements_into_camera(t_element *element, t_camera *cam)
{
	t_tuple		from;
	t_tuple		to;
	t_tuple		up;

	(void)element;
	*cam = camera(PCT_WIDTH, WIN_HEIGHT, M_PI / 3);
	from = point(0, 1, -5);
	to = point(0, 1, 0);
	up = vector(0, 1, 0);
	cam->transform = view_transform(&from, &to, &up);
	cam->inverse = inverse(&cam->transform);
	cam->original_transform = cam->transform;
}

/*
void	put_elements_into_camera(t_element *element, t_camera *cam)
{
	t_tuple		from;
	t_tuple		to;
	t_tuple		up;

	(void) element;
	*cam = camera(PCT_WIDTH, WIN_HEIGHT, element->fov);
	from = element->coordinates;
	to = point(0, 1, 0); // check with ruslan if okay
	up = element->orientation;
	cam->transform = view_transform(&from, &to, &up);
	cam->inverse = inverse(&cam->transform);
	cam->original_transform = cam->transform;
}*/
/*		[BONUS]
void	put_elements_into_lightning(t_element *element, int index, t_world *w)
{
	if (element->element_type == ELMT_AMBIENT)
	{	
	w->lights[index].position = element->coordinates;
	w->lights[index].intensity = element->light_intensity;
	w->lights[index].intensity.red *= element->color.red;
	w->lights[index].intensity.green *= element->color.green;
	w->lights[index].intensity.blue *= element->color.blue;
	}
	else if (element->element_type == ELMT_LIGHT)
			w->lights[index] = point_light(&element->light_intensity \
		, & element->coordinates);;
}*/

void	put_elements_into_lightning(t_element *element, int index, t_world *w)
{
	if (element->element_type == ELMT_AMBIENT)
	{
		w->lightning.material->ambient = element->ambient_lightning_ratio;
		w->lightning.material->color = element->color;
	}
	else if (element->element_type == ELMT_LIGHT)
		w->lights[index] = point_light(&element->light_intensity \
							, & element->coordinates);
}
