/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:27:48 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/25 18:08:15 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	parse_origin(char *file_string, int *index, t_element *element) // same as in parse sphere
{
	if (parse_point(file_string, index, &(element->light_position)) == false)
		return (false);
	if (file_string[*index] != ' ')
		return (false);
	while (file_string[*index] == ' ')
		(*index)++;
	return (true);
}
static bool	parse_brightness(char *file_string, int *index, t_element *element)
{
	double	onecolor;
	
	if (parse_double(file_string, index, &onecolor) == false)
		return (false);
	if (onecolor < 0 || onecolor > 1.0)
		return (false);
	element->light_intensity = color(onecolor, onecolor, onecolor);
	return (true);
}

static bool	modify_brightness_with_color(char *file_string, int *index, t_element *element)
{
	t_color	modif;

	if (parse_color(file_string, index, &modif) == false)
		return (false);
	element->light_intensity.red *= modif.red;
	element->light_intensity.green *= modif.green;
	element->light_intensity.blue *= modif.blue;
	return (true);
}

bool	parse_light(char *file_string, int *index, t_element *element)
{
	element->element_type = ELMT_LIGHT;
	while (file_string[*index] == ' ')
		(*index)++;
	if (parse_origin(file_string, index, element) == false)
		return (false);
	while (file_string[*index] == ' ')
		(*index)++;
	if (parse_brightness(file_string, index, element) == false)
		return (false);
	while (file_string[*index] == ' ')
		(*index)++;
	if (modify_brightness_with_color(file_string, index, element) == false)
		return (false);
	return (true);
}
