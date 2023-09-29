/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lightning.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:48:43 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/29 22:32:01 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	parse_lightning_ratio(char *file_string, int *index, t_element *element)
{
	if (parse_double(file_string, index, \
		&element->ambient_lightning_ratio) == false)
		return (false);
	if (element->ambient_lightning_ratio < 0 \
		|| element->ambient_lightning_ratio > 1.0)
		return (false);
	return (true);
}

bool	parse_ambient(char *file_string, int *index, t_element *element)
{
	element->element_type = ELMT_AMBIENT;
	while (file_string[*index] == ' ')
		(*index)++;
	if (parse_lightning_ratio(file_string, index, element) == false)
		return (false);
	while (file_string[*index] == ' ')
		(*index)++;
	if (parse_color(file_string, index, &element->color) == false)
		return (false);
	return (true);
}
