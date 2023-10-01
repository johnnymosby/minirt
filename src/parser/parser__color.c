/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser__color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:08:51 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/30 19:53:47 by aguilmea         ###   ########.fr       */
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

bool	parse_color(char *file_string, int *index, t_color *color)
{
	if (parse_primary (file_string, index, &(color->red)) == false)
		return (false);
	if (file_string[*index] != ',')
		return (false);
	(*index)++;
	if (parse_primary (file_string, index, &(color->green)) == false)
		return (false);
	if (file_string[*index] != ',')
		return (false);
	(*index)++;
	if (parse_primary (file_string, index, &(color->blue)) == false)
		return (false);
	return (true);
}
