/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 00:21:09 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/19 18:42:26 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

bool	are_equal_colors(t_color *a, t_color *b)
{
	if (are_equal_doubles(a->red, b->red) == false)
		return (false);
	else if (are_equal_doubles(a->green, b->green) == false)
		return (false);
	else if (are_equal_doubles(a->blue, b->blue) == false)
		return (false);
	else
		return (true);
}
