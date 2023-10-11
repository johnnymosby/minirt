/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elements_into_lightning.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:34:53 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/11 13:34:26 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	put_ambient_into_lightning(t_element *element, t_world *w)
{
	w->lightning.material = ft_calloc(1, sizeof(t_material));
	if (w->lightning.material == NULL)
		return (false);
	w->lightning.material->ambient = element->ambient_lightning_ratio;
	w->lightning.material->color = element->color;
	return (true);
}

static void	put_light_into_lightning(t_element *element, int index, t_world *w)
{
	/*t_light	l;
	t_tuple p;
	t_color	c;
	
	p = point(0, 0, 0);
	c = color(1, 1, 1);*/
	w->lights[index] = point_light(&element->light_intensity, &element->coordinates);
	//l = point_light(&c, &p);
	//w->lights[index] = temp;
	
	(void) w;
	(void) element;
	(void) index;
	//w->lights[index].position = element->coordinates;
	//w->lights[index].intensity = element->light_intensity;
	//w->lights[index].position = point(0, 0, 0);
	//w->lights[index].intensity = color(1,0,0);
}
/*		[BONUS]
static void	put_light_into_lightning(t_element *element, int index, t_world *w)
{
	w->lights[index].position = element->coordinates;
	w->lights[index].intensity = element->light_intensity;
	w->lights[index].intensity.red *= element->color.red;
	w->lights[index].intensity.green *= element->color.green;
	w->lights[index].intensity.blue *= element->color.blue;
}*/

bool	put_elements_into_lightning(t_element *element, int index, t_world *w)
{
	if (element->element_type == ELMT_AMBIENT \
		& put_ambient_into_lightning(element, w) == false)
			return (false);
	else if (element->element_type == ELMT_LIGHT)
		put_light_into_lightning(element, index, w);
	return (true);
}
