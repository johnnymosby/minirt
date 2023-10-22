/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser__tuple.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:47:17 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/22 19:43:26 by aguilmea         ###   ########.fr       */
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

static int	check_value_vector(double coord[3])
{
	if (coord[0] < -1.0 || coord[0] > 1.0
		||coord[1] < -1.0 || coord[1] > 1.0
		||coord[2] < -1.0 || coord[2] > 1.0)
		return (ERR_VALUE_RANGE);
	printf("****%f %f, %f\n", coord[0], coord[1], coord[2]);
	if (sqrt(coord[0] * coord[0] + coord[1] * coord[1]
		 + coord[2] * coord[2]) != 1)
		return (ERR_NORM_VECTOR);
	return (0);
}

int	parse_orientation(char *file_string, int *index, t_element *element)
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
	element->orientation = vector(coord[0], coord[1], coord[2]);
	while (file_string[*index] == ' ')
		(*index)++;
	return (check_value_vector(coord));
}
