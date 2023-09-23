/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:09:14 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/23 19:27:46 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	parse_origin(char *file_string, int *index, t_element *element)
{
	if (parse_point(file_string, index, &(element->sphere.origin)) == false)
		return (false);
	if (file_string[*index] != ' ')
		return (false);
	while (file_string[*index] == ' ')
		(*index)++;
	return (true);
}
static bool	parse_radius(char *file_string, int *index, t_element *element)
{
	(void)file_string;
	(void)element;
	(void)index;
	if (parse_double(file_string, index, &(element->sphere.radius)) == false)
		return (false);
	element->sphere.radius *= 0.5;
	return (true);
}

bool	parse_sphere(char *file_string, int *index, t_element *element)
{
	element->element_type = SPHERE1;
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
	if (parse_color(file_string, index, &(element->material.color)) == false)
		return (false);
	return (true);
}
