/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:00:17 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/10/12 17:40:14 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

void	set_transform(t_shape *shape, t_matrix *m)
{
	shape->transform = *m;
	shape->inverse = inverse(m);
	shape->transpose = transpose(&shape->inverse);
}

void	set_shape_to_default(t_shape *shape)
{
	shape->transform = identity_matrix();
	shape->inverse = identity_matrix();
	shape->transpose = identity_matrix();
	set_material_to_default(&shape->material);
}
