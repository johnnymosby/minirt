/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elements_into_lightning.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:34:53 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/06 15:07:22 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	put_ambient_into_lightning(t_element *element, t_world *w)
{
	w->lightning.material->ambient = element->ambient_lightning_ratio;
	w->lightning.material->color = element->color;
}

static void	put_light_into_lightning(t_element *element, int index, t_world *w)
{
	w->lights[index].position = element->coordinates;
	w->lights[index].intensity = element->light_intensity;
	//	[BONUS]
	//w->lightning.light[index].intensity.red *= element->color.red;
	//w->lightning.light[index].intensity.green *= element->color.green;
	//w->lightning.light[index].intensity.blue *= element->color.blue;
}

void	put_elements_into_lightning(t_element *element, int index, t_world *w)
{
	if (element->element_type == ELMT_AMBIENT)
		put_ambient_into_lightning(element, w);
	else if (element->element_type == ELMT_LIGHT)
		put_light_into_lightning(element, index, w);
}
