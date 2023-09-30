/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:09:14 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/30 20:08:56 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	parse_radius(char *file_string, int *index, t_element *element)
{
	if (parse_double(file_string, index, &(element->radius)) == false)
		return (false);
	element->radius *= 0.5;
	if (element->radius < 0)
		return (false);
	return (true);
}

bool	parse_sphere(char *file_string, int *index, t_element *element)
{
	element->element_type = ELMT_SPHERE;
	while (file_string[*index] == ' ')
		(*index)++;
	if (parse_coordinates(file_string, index, element) == false)
		return (false);
	while (file_string[*index] == ' ')
		(*index)++;
	if (parse_radius(file_string, index, element) == false)
		return (false);
	while (file_string[*index] == ' ')
		(*index)++;
	if (parse_color(file_string, index, &element->color) == false)
		return (false);
	return (true);
}

bool	parse_cylinder(char *file_string, int *index, t_element *element)
{
	element->element_type = ELMT_CYLINDER;
	while (file_string[*index] == ' ')
		(*index)++;
	if (parse_coordinates(file_string, index, element) == false)
		return (false);
	while (file_string[*index] == ' ')
		(*index)++;
	if (parse_orientation(file_string, index, element) == false)
		return (false);
	while (file_string[*index] == ' ')
		(*index)++;
	if (parse_radius(file_string, index, element) == false)
		return (false);
	while (file_string[*index] == ' ')
		(*index)++;
	if (parse_double(file_string, index, &element->cylinder_height) == false)
		return (false);
	while (file_string[*index] == ' ')
		(*index)++;
	if (parse_color(file_string, index, &element->color) == false)
		return (false);
	return (true);
}

bool	parse_plane(char *file_string, int *index, t_element *element)
{
	element->element_type = ELMT_PLANE;
	while (file_string[*index] == ' ')
		(*index)++;
	if (parse_coordinates(file_string, index, element) == false)
		return (false);
	while (file_string[*index] == ' ')
		(*index)++;
	if (parse_orientation(file_string, index, element) == false)
		return (false);
	while (file_string[*index] == ' ')
		(*index)++;
	if (parse_color(file_string, index, &element->color) == false)
		return (false);
	return (true);
}
