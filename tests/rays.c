/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 19:01:32 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/23 18:30:34 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

Test(rays_creation, create_ray)
{
	t_tuple origin = point(1, 2, 3);
	t_tuple direction = vector(4, 5, 6);
	t_ray r = ray(&origin, &direction);

	cr_assert(are_equal_tuples(&r.origin, &origin));
	cr_assert(are_equal_tuples(&r.direction, &direction));
}

Test(rays_creation, position)
{
	t_tuple origin = point(2, 3, 4);
	t_tuple direction = vector(1, 0, 0);
	t_ray r = ray(&origin, &direction);

	t_tuple pos_0 = position(&r, 0);
	t_tuple pos_1 = position(&r, 1);
	t_tuple pos_2 = position(&r, -1);
	t_tuple pos_3 = position(&r, 2.5);

	t_tuple p_answer_0 = point(2, 3, 4);
	t_tuple p_answer_1 = point(3, 3, 4);
	t_tuple p_answer_2 = point(1, 3, 4);
	t_tuple p_answer_3 = point(4.5, 3, 4);

	cr_assert(are_equal_tuples(&pos_0, &p_answer_0));
	cr_assert(are_equal_tuples(&pos_1, &p_answer_1));
	cr_assert(are_equal_tuples(&pos_2, &p_answer_2));
	cr_assert(are_equal_tuples(&pos_3, &p_answer_3));
}
