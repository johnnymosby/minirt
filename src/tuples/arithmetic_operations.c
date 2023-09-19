/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 22:49:16 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/19 17:58:12 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_tuple	add_tuples(t_tuple *a, t_tuple *b)
{
	t_tuple	c;

	c.x = a->x + b->x;
	c.y = a->y + b->y;
	c.z = a->z + b->z;
	c.w = a->w + b->w;
	if (are_equal_doubles(c.w, 0.0) == false
		&& are_equal_doubles(c.w, 1.0) == false)
	{
		ft_putstr_fd("Wrong tuples. The sum is set to a vector\n",
			STDOUT_FILENO);
		c.w = 1.0;
	}
	return (c);
}

t_tuple	substract_tuples(t_tuple *a, t_tuple *b)
{
	t_tuple	c;

	c.x = a->x - b->x;
	c.y = a->y - b->y;
	c.z = a->z - b->z;
	c.w = a->w - b->w;
	if (are_equal_doubles(c.w, 0.0) == false
		&& are_equal_doubles(c.w, 1.0) == false)
	{
		ft_putstr_fd("Wrong tuples. The substraction is set to a vector\n",
			STDOUT_FILENO);
		c.w = 1.0;
	}
	return (c);
}

t_tuple	negate_tuple(t_tuple *a)
{
	return ((t_tuple){-a->x, -a->y, -a->z, -a->w});
}

t_tuple	multiply_tuple_by_scalar(t_tuple *a, double sc)
{
	return ((t_tuple){a->x * sc, a->y * sc, a->z * sc, a->w * sc});
}

t_tuple	divide_tuple_by_scalar(t_tuple *a, double sc)
{
	return ((t_tuple){a->x / sc, a->y / sc, a->z / sc, a->w / sc});
}
