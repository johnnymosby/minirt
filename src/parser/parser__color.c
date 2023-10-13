/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser__color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:08:51 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/13 13:13:12 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	parse_primary(char *file_string, int *index, double *rgb)
{
	*rgb = 0;
	if (!ft_isdigit(file_string[*index]))
		return (false);
	while (*rgb < 256 && ft_isdigit(file_string[*index]))
	{
		*rgb = *rgb * 10 + file_string[*index] - '0';
		(*index)++;
	}
	*rgb /= 255;
	return (true);
}

int	parse_color(char *file_string, int *index, t_color *color)
{
	if (parse_primary (file_string, index, &(color->red)) == false)
		return (VALUE_IS_NOT_A_DIGIT);
	if (file_string[*index] != ',')
		return (MISSING_COMMA);
	(*index)++;
	if (parse_primary (file_string, index, &(color->green)) == false)
		return (VALUE_IS_NOT_A_DIGIT);
	if (file_string[*index] != ',')
		return (MISSING_COMMA);
	(*index)++;
	if (parse_primary (file_string, index, &(color->blue)) == false)
		return (VALUE_IS_NOT_A_DIGIT);
	while (file_string[*index] == ' ')
		(*index)++;
	return (0);
}
