/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:33:21 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/23 14:47:16 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

t_tuple	reflect(t_tuple *in, t_tuple *normal)
{
	double	p_dot;
	t_tuple	multiplication;

	p_dot = dot(in, normal);
	multiplication = multiply_tuple_by_scalar(normal, 2 * p_dot);
	return (substract_tuples(in, &multiplication));
}
