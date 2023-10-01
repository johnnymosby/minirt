/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser__point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:47:17 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/30 20:02:31 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	parse_coordinates(char *file_string, int *index, t_element *element)
{
	double	coord[3];

	if (parse_double (file_string, index, coord) == false)
		return (false);
	if (file_string[*index] != ',')
		return (false);
	(*index)++;
	if (parse_double (file_string, index, coord +1) == false)
		return (false);
	if (file_string[*index] != ',')
		return (false);
	(*index)++;
	if (parse_double (file_string, index, coord +2) == false)
		return (false);
	element->coordinates = point(coord[0], coord[1], coord[2]);
	if (file_string[*index] != ' ')
		return (false);
	return (true);
}

bool	parse_orientation(char *file_string, int *index, t_element *element)
{
	double	coord[3];

	if (parse_double (file_string, index, coord) == false)
		return (false);
	if (file_string[*index] != ',')
		return (false);
	(*index)++;
	if (parse_double (file_string, index, coord +1) == false)
		return (false);
	if (file_string[*index] != ',')
		return (false);
	(*index)++;
	if (parse_double (file_string, index, coord +2) == false)
		return (false);
	element->orientation = vector(coord[0], coord[1], coord[2]);
	if (file_string[*index] != ' ')
		return (false);
	while (file_string[*index] == ' ')
		(*index)++;
	return (true);
}
