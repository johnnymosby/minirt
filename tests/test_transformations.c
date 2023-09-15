/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_transformations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:58:35 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/15 17:19:57 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

Test(mx_transformations_translation, multiply_by_translation_mx)
{
	t_tuple p = point(-3, 4, 5);
	t_matrix transform = translation(5, -3, 2);

	t_tuple product = multiply_matrix_by_tuple(transform, p);

	cr_assert(are_equal_tuples(product, point(2, 1, 7)));
}

Test(mx_transformations_translation, multiply_by_inverse_of_translation_mx)
{
	t_tuple p = point(-3, 4, 5);
	t_matrix transform = translation(5, -3, 2);
	t_matrix inv = inverse(transform);

	t_tuple product = multiply_matrix_by_tuple(inv, p);

	cr_assert(are_equal_tuples(product, point(-8, 7, 3)));
}

Test(mx_transformations_translation, multiply_by_translation_of_vec)
{
	t_tuple v = vector(-3, 4, 5);
	t_matrix transform = translation(5, -3, 2);

	t_tuple product = multiply_matrix_by_tuple(transform, v);

	cr_assert(are_equal_tuples(product, v));
}


Test(mx_transformations_scaling, scale_)
{
	t_tuple v = vector(-3, 4, 5);
	t_matrix transform = translation(5, -3, 2);

	t_tuple product = multiply_matrix_by_tuple(transform, v);

	cr_assert(are_equal_tuples(product, v));
}

