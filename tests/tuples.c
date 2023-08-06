/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:38:03 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/08/06 16:47:17 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

Test(tuples, is_point)
{
	t_tuple a = tuple(4.3, -4.2, 3.1, 1.0);

	cr_assert(a.x == 4.3);
	cr_assert(a.y == -4.2);
	cr_assert(a.z == 3.1);
	cr_assert(a.w == 1.0, "The tuple is not a point");
}

Test(tuples, is_vector)
{
	t_tuple a = tuple(4.3, -4.2, 3.1, 0.0);

	cr_assert(a.x == 4.3);
	cr_assert(a.y == -4.2);
	cr_assert(a.z == 3.1);
	cr_assert(a.w == 0.0, "The tuple is not a vector");
}
