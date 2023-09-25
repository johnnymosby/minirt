/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:09:14 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/25 18:02:35 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	parse_origin(char *file_string, int *index, t_element *element)
{
	if (parse_point(file_string, index, &(element->sphere_origin)) == false)
		return (false);
	if (file_string[*index] != ' ')
		return (false);
	while (file_string[*index] == ' ')
		(*index)++;
	return (true);
}
static bool	parse_radius(char *file_string, int *index, t_element *element)
{
	if (parse_double(file_string, index, &(element->sphere_radius)) == false)
		return (false);
	element->sphere_radius *= 0.5;
	if (element->sphere_radius < 0)
		return (false);
	return (true);
}

bool	parse_sphere(char *file_string, int *index, t_element *element)
{
	element->element_type = ELMT_SPHERE;
	while (file_string[*index] == ' ')
		(*index)++;
	if (parse_origin(file_string, index, element) == false)
		return (false);
	while (file_string[*index] == ' ')
		(*index)++;
	if (parse_radius(file_string, index, element) == false)
		return (false);
	while (file_string[*index] == ' ')
		(*index)++;
	if (parse_color(file_string, index, &(element->sphere_color)) == false)
		return (false);
	return (true);
}
