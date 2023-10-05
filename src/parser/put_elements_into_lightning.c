/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_elements_into_lightning.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:34:53 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/05 14:07:56 by aguilmea         ###   ########.fr       */
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
	w->lightning.light[index].position = element->coordinates;
	w->lightning.light[index].intensity = element->light_intensity;
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
