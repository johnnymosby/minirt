/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser__tuple.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:47:17 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/23 10:59:34 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parse_coordinates(char *file_string, int *index, t_element *element)
{
	double	coord[3];
	int		ret;

	ret = parse_double (file_string, index, coord);
	if (ret != 0)
		return (ret);
	if (file_string[*index] != ',')
		return (ERR_MISSING_COMMA);
	(*index)++;
	ret = parse_double (file_string, index, coord +1);
	if (ret != 0)
		return (ret);
	if (file_string[*index] != ',')
		return (ERR_MISSING_COMMA);
	(*index)++;
	ret = parse_double (file_string, index, coord +2);
	if (ret != 0)
		return (ret);
	element->coordinates = point(coord[0], coord[1], coord[2]);
	while (file_string[*index] == ' ')
		(*index)++;
	return (0);
}

static int	check_value_vector(t_tuple *coord)
{
	if (coord->x < -1.0 || coord->x > 1.0
		||coord->y < -1.0 || coord->y > 1.0
		||coord->z < -1.0 || coord->z > 1.0)
		return (ERR_VALUE_RANGE);
	if (!are_equal_doubles(magnitude(coord), 1))
		return (ERR_NORM_VECTOR);
	return (0);
}

int	parse_orientation(char *file_string, int *index, t_element *element)
{
	t_tuple	coord;
	int		ret;

	coord = vector(0,0,0);
	ret = parse_double (file_string, index, &coord.x);
	if (ret != 0)
		return (ret);
	if (file_string[*index] != ',')
		return (ERR_MISSING_COMMA);
	(*index)++;
	ret = parse_double (file_string, index, &coord.y);
	if (ret != 0)
		return (ret);
	if (file_string[*index] != ',')
		return (ERR_MISSING_COMMA);
	(*index)++;
	ret = parse_double (file_string, index, &coord.z);
	if (ret != 0)
		return (ret);
	element->orientation = coord;
	while (file_string[*index] == ' ')
		(*index)++;
	return (check_value_vector(&element->orientation));
}
