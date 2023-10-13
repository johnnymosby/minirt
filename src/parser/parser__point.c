/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser__point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:47:17 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/13 13:23:43 by aguilmea         ###   ########.fr       */
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
		return (MISSING_COMMA);
	(*index)++;
	ret = parse_double (file_string, index, coord +1);
	if (ret != 0)
		return (ret);
	if (file_string[*index] != ',')
		return (MISSING_COMMA);
	(*index)++;
	ret = parse_double (file_string, index, coord +2);
	if (ret != 0)
		return (ret);
	element->coordinates = point(coord[0], coord[1], coord[2]);
	while (file_string[*index] == ' ')
		(*index)++;
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
		return (MISSING_COMMA);
	(*index)++;
	ret = parse_double (file_string, index, coord +1);
	if (ret != 0)
		return (ret);
	if (file_string[*index] != ',')
		return (MISSING_COMMA);
	(*index)++;
	ret = parse_double (file_string, index, coord +2);
	if (ret != 0)
		return (ret);
	element->orientation = vector(coord[0], coord[1], coord[2]);
	while (file_string[*index] == ' ')
		(*index)++;
	return (0);
}
