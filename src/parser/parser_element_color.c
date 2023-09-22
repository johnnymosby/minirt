/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_element_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:08:51 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/22 21:19:57 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	parse_color(char *start, int *index, t_element *element)
{
	(void)start;
	(void)element;
	(void)index;
	element->material.color = color(10/255, 0, 1);
	return (true);
}