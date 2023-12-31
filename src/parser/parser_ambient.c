/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_ambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:48:43 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/21 23:31:58 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	parse_lightning_ratio(char *file_string, int *index, \
	t_element *element)
{
	int	ret;

	while (file_string[*index] == ' ')
		(*index)++;
	ret = parse_double(file_string, index, & element->ambient_lightning_ratio);
	if (ret != 0)
		return (ret);
	if (element->ambient_lightning_ratio < 0 \
		|| element->ambient_lightning_ratio > 1.0)
		return (ERR_VALUE_RANGE);
	return (0);
}

int	parse_ambient(char *file_string, int *index, t_element *element)
{
	int	ret;

	element->element_type = ELMT_AMBIENT;
	(*index) += 2;
	while (file_string[*index] == ' ')
		(*index)++;
	ret = parse_lightning_ratio(file_string, index, element);
	if (ret != 0)
		return (print_error(file_string, *index, ret, ERR_LIGHTNING));
	while (file_string[*index] == ' ')
		(*index)++;
	ret = parse_color(file_string, index, &element->color);
	if (ret != 0)
		return (print_error(file_string, *index, ret, ERR_LIGHTNING));
	return (0);
}
