/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:09:14 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/22 17:59:34 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"


static bool	parse_origin(char *start, t_element *element)
{
	(void)start;
	(void)element;
	element->sphere.origin = point(0,0,20.6);
	return (true);
}
static bool	parse_radius(char *start, t_element *element)
{
	(void)start;
	(void)element;
	element->sphere.radius = 12.6 / 2;
	return (true);
}

bool	parse_sphere(char *start, t_element *element)
{
	element->element_type = SPHERE;
	while (*start == ' ')
		start++;
	if (parse_origin(start, element) == false)
		return (false);
	while (*start == ' ')
		start++;
	if (parse_radius(start, element) == false)
		return (false);
	while (*start == ' ')
		start++;
	if (parse_color(start, element) == false)
		return (false);
	return (true);	
}