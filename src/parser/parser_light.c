/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:27:48 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/13 16:40:17 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	parse_brightness(char *file_string, int *index, t_element *element)
{
	double	onecolor;
	int		ret;

	ret = parse_double(file_string, index, &onecolor);
	if (ret != 0)
		return (ret);
	if (onecolor < 0 || onecolor > 1.0)
		return (ERR_VALUE_BRIGHTNESS_LIGHT);
	element->light_intensity = color(onecolor, onecolor, onecolor);
	return (0);
}

static int	modify_brightness_with_color(char *file_string, int *index, \
	t_element *element)
{
	t_color	modif;
	int		ret;

	ret = parse_color(file_string, index, &modif);
	if (ret != 0)
		return (ret);
	element->light_intensity.red *= modif.red;
	element->light_intensity.green *= modif.green;
	element->light_intensity.blue *= modif.blue;
	return (0);
}

int	parse_light(char *file_string, int *index, t_element *element)
{
	int	ret;

	element->element_type = ELMT_LIGHT;
	(*index) += 2;
	while (file_string[*index] == ' ')
		(*index)++;
	ret = parse_coordinates(file_string, index, element);
	if (ret != 0)
		return (ret);
	while (file_string[*index] == ' ')
		(*index)++;
	ret = parse_brightness(file_string, index, element);
	if (ret != 0)
		return (ret);
	while (file_string[*index] == ' ')
		(*index)++;
	ret = modify_brightness_with_color(file_string, index, element);
	if (ret != 0)
		return (ret);
	return (0);
}
