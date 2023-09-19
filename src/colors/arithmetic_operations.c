/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:38:33 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/19 18:44:32 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

t_color	add_colors(t_color *a, t_color *b)
{
	return ((t_color){a->red + b->red,
		a->green + b->green,
		a->blue + b->blue});
}

t_color	substract_colors(t_color *a, t_color *b)
{
	return ((t_color){a->red - b->red,
		a->green - b->green,
		a->blue - b->blue});
}

t_color	multiply_color_by_scalar(t_color *a, double sc)
{
	return ((t_color){a->red * sc,
		a->green * sc,
		a->blue * sc});
}

t_color	multiply_colors(t_color *a, t_color *b)
{
	return ((t_color){a->red * b->red,
		a->green * b->green,
		a->blue * b->blue});
}
