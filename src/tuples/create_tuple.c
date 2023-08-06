/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tuple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:40:47 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/08/06 22:26:01 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_tuple	tuple(double x, double y, double z, double w)
{
	if (are_equal_doubles(w, 1.0) == false
		&& are_equal_doubles(w, 0.0) == false)
	{
		ft_putstr_fd("w is set not to 0.0 or 1.0", STDERR_FILENO);
		return ((t_tuple){0, 0, 0, 0});
	}
	return ((t_tuple){x, y, z, w});
}

t_tuple	point(double x, double y, double z)
{
	return ((t_tuple){x, y, z, 1.0});
}

t_tuple	vector(double x, double y, double z)
{
	return ((t_tuple){x, y, z, 0.0});
}
