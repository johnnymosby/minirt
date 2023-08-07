/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tuple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:40:47 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/08/07 02:48:11 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_tuple	tuple(double x, double y, double z, double w)
{
	return ((t_tuple){x, y, z, w});
}

t_tuple	point(double x, double y, double z)
{
	return (tuple(x, y, z, 1.0));
}

t_tuple	vector(double x, double y, double z)
{
	return (tuple(x, y, z, 0.0));
}
