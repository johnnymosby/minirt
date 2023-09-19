/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 19:03:59 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/19 17:58:38 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

bool	are_equal_doubles(double a, double b)
{
	return (fabs(a - b) < EPSILON);
}

bool	are_equal_tuples(t_tuple *a, t_tuple *b)
{
	if (are_equal_doubles(a->w, b->w) == false)
		return (false);
	else if (are_equal_doubles(a->x, b->x) == false)
		return (false);
	else if (are_equal_doubles(a->y, b->y) == false)
		return (false);
	else if (are_equal_doubles(a->z, b->z) == false)
		return (false);
	else
		return (true);
}
