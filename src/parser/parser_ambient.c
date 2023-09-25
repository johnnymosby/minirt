/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_ambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:48:43 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/25 09:51:40 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	parse_origin(char *file_string, int *index, t_element *element) // same as in parse sphere
{
	if (parse_point(file_string, index, &(element->light.position)) == false)
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
	element->lightning.light->intensity = color(onecolor, onecolor, onecolor);
	return (true);
}

bool	parse_ambient(char *file_string, int *index, t_element *element)
{
	element->element_type = ELMT_LIGHTNING;
	while (file_string[*index] == ' ')
		(*index)++;

	if (parse_brightness(file_string, index, element) == false)
		return (false);
	while (file_string[*index] == ' ')
		(*index)++;
	if (parse_origin(file_string, index, element) == false)
		return (false);
	while (file_string[*index] == ' ')
		(*index)++;
		
	if (parse_color(file_string, index, &element->material.color) == false)
		return (false);
	return (true);
}
