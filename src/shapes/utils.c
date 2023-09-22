/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:00:17 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/22 19:03:50 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

void	set_transform(t_shape *shape, t_matrix *m)
{
	shape->transform = *m;
	shape->inverse = inverse(m);
}
