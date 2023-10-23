/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser__color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:08:51 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/23 11:47:27 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	parse_primary(char *file_string, int *index, double *rgb)
{
	*rgb = 0;
	if (!ft_isdigit(file_string[*index]))
		return (ERR_VALUE_IS_NOT_A_DIGIT);
	while (*rgb < 256 && ft_isdigit(file_string[*index]))
	{
		*rgb = *rgb * 10 + file_string[*index] - '0';
		(*index)++;
	}
	if (*rgb > 255)
		return (ERR_VALUE_RANGE);
	*rgb /= 255;
	return (0);
}

int	parse_color(char *file_string, int *index, t_color *color)
{
	int	ret;

	ret = parse_primary (file_string, index, &(color->red));
	if (ret != 0)
		return (ret);
	if (file_string[*index] != ',')
		return (ERR_MISSING_COMMA);
	(*index)++;
	ret = parse_primary (file_string, index, &(color->green));
	if (ret != 0)
		return (ret);
	if (file_string[*index] != ',')
		return (ERR_MISSING_COMMA);
	(*index)++;
	ret = parse_primary (file_string, index, &(color->blue));
	if (ret != 0)
		return (ret);
	if (file_string[*index] != '\n' && file_string[*index] != '\0')
		return (ERR_MISSING_NL);
	while (file_string[*index] == '\n')
		(*index)++;
	return (0);
}
