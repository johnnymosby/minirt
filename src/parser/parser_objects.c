/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:09:14 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/24 17:59:52 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	parse_radius(char *file_string, int *index, t_element *element)
{
	int	ret;

	ret = parse_double(file_string, index, &(element->radius));
	if (ret != 0)
		return (ret);
	element->radius *= 0.5;
	if (element->radius <= 0 && element->element_type == ELMT_SPHERE)
		return (ERR_VALUE_RANGE);
	if (element->radius <= 0 && element->element_type == ELMT_CYLINDER)
		return (ERR_VALUE_RANGE);
	return (0);
}

int	parse_sphere(char *file_string, int *index, t_element *element)
{
	int	ret;

	element->element_type = ELMT_SPHERE;
	(*index) += 3;
	while (file_string[*index] == ' ')
		(*index)++;
	ret = parse_coordinates(file_string, index, element);
	if (ret != 0)
		return (print_error(file_string, *index, ret, ERR_SPHERE));
	while (file_string[*index] == ' ')
		(*index)++;
	ret = parse_radius(file_string, index, element);
	if (ret != 0)
		return (print_error(file_string, *index, ret, ERR_SPHERE));
	while (file_string[*index] == ' ')
		(*index)++;
	ret = parse_color(file_string, index, &element->color);
	if (ret != 0)
		return (print_error(file_string, *index, ret, ERR_SPHERE));
	return (0);
}

int	parse_cylinder_end(char *file_string, int *index, t_element *element)
{
	int	ret;

	ret = parse_radius(file_string, index, element);
	if (ret != 0)
		return (print_error(file_string, *index, ret, ERR_CYLINDER));
	while (file_string[*index] == ' ')
		(*index)++;
	ret = parse_double(file_string, index, &element->cylinder_height);
	if (ret != 0)
		return (print_error(file_string, *index, ret, ERR_CYLINDER));
	if (element->cylinder_height <= 0)
		return (print_error(file_string, *index,
				ERR_VALUE_RANGE, ERR_CYLINDER));
	while (file_string[*index] == ' ')
		(*index)++;
	ret = parse_color(file_string, index, &element->color);
	if (ret != 0)
		return (print_error(file_string, *index, ret, ERR_CYLINDER));
	return (0);
}

int	parse_cylinder(char *file_string, int *index, t_element *element)
{
	int	ret;

	element->element_type = ELMT_CYLINDER;
	(*index) += 3;
	while (file_string[*index] == ' ')
		(*index)++;
	ret = parse_coordinates(file_string, index, element);
	if (ret != 0)
		return (print_error(file_string, *index, ret, ERR_CYLINDER));
	while (file_string[*index] == ' ')
		(*index)++;
	ret = parse_orientation(file_string, index, element);
	if (ret != 0)
		return (print_error(file_string, *index, ret, ERR_CYLINDER));
	while (file_string[*index] == ' ')
		(*index)++;
	return (parse_cylinder_end(file_string, index, element));
}

int	parse_plane(char *file_string, int *index, t_element *element)
{
	int	ret;

	element->element_type = ELMT_PLANE;
	(*index) += 3;
	while (file_string[*index] == ' ')
		(*index)++;
	ret = parse_coordinates(file_string, index, element);
	if (ret != 0)
		return (print_error(file_string, *index, ret, ERR_PLANE));
	while (file_string[*index] == ' ')
		(*index)++;
	ret = parse_orientation(file_string, index, element);
	if (ret != 0)
		return (print_error(file_string, *index, ret, ERR_PLANE));
	while (file_string[*index] == ' ')
		(*index)++;
	ret = parse_color(file_string, index, &element->color);
	if (ret != 0)
		return (print_error(file_string, *index, ret, ERR_PLANE));
	return (0);
}
