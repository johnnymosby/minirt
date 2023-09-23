/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:47:17 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/22 21:14:40 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool parse_point(char *file_string, int *index, t_tuple *pt)
{
	double	coord[3];
	//*pt = point(0, 0, 20.6);
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
	*pt = point(coord[0], coord[1], coord[2]);
	return (true);
}

