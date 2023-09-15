/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:01:32 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/15 19:06:08 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

Test(rays_creation, create_ray)
{
	t_tuple origin = point(1, 2, 3);
	t_tuple direction = vector(4, 5, 6);
	t_ray r = ray(origin, direction);

	cr_assert(are_equal_tuples(r.origin, origin));
	cr_assert(are_equal_tuples(r.direction, direction));
}
