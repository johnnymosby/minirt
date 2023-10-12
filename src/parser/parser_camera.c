/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 19:43:18 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/10 14:02:38 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	parse_fov(char *file_string, int *index, t_element *element)
{
	if (parse_double(file_string, index, &element->fov) == false)
		return (false);
	if (element->fov < 0 || element->fov > 180.0)
		return (false);
	return (true);
}

bool	parse_camera(char *file_string, int *index, t_element *element)
{
	element->element_type = ELMT_CAMERA;
	(*index) += 2;
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
	if (parse_fov(file_string, index, element) == false)
		return (false);
	return (true);
}
