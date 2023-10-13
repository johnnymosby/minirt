/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 19:43:18 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/13 13:23:57 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parse_fov(char *file_string, int *index, t_element *element)
{
	int	ret;

	ret = parse_double(file_string, index, &element->fov);
	if (ret != 0)
		return (ret);
	if (element->fov < 0 || element->fov > 180.0)
		return (VALUE_FOV_WRONG);
	return (0);
}

int	parse_camera(char *file_string, int *index, t_element *element)
{
	int	ret;

	element->element_type = ELMT_CAMERA;
	(*index) += 2;
	while (file_string[*index] == ' ')
		(*index)++;
	ret = parse_coordinates(file_string, index, element);
	if (ret != 0)
		return (ret);
	while (file_string[*index] == ' ')
		(*index)++;
	ret = parse_orientation(file_string, index, element);
	if (ret != 0)
		return (ret);
	while (file_string[*index] == ' ')
		(*index)++;
	ret = parse_fov(file_string, index, element);
	if (ret != 0)
		return (ret);
	while (file_string[*index] == ' ')
		(*index)++;
	return (0);
}
