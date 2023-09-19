/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:14:39 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/19 18:47:00 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

Test(colors_creation, color)
{
	t_color a = color(-0.5, 0.4, 1.7);

	cr_assert(are_equal_doubles(a.red, -0.5));
	cr_assert(are_equal_doubles(a.green, 0.4));
	cr_assert(are_equal_doubles(a.blue, 1.7), "The color is not correct");
}

Test(colors_arithmetics, add_colors)
{
	t_color c1 = color(0.9, 0.6, 0.75);
	t_color c2 = color(0.7, 0.1, 0.25);
	t_color c3 = add_colors(&c1, &c2);
	t_color c4 = color(1.6, 0.7, 1.0);

	cr_assert(are_equal_colors(&c3, &c4), "The addition function is not correct");
}

Test(colors_arithmetics, substract_colors)
{
	t_color c1 = color(0.9, 0.6, 0.75);
	t_color c2 = color(0.7, 0.1, 0.25);
	t_color c3 = substract_colors(&c1, &c2);
	t_color c4 = color(0.2, 0.5, 0.5);

	cr_assert(are_equal_colors(&c3, &c4), "The subtraction function is not correct");
}

Test(colors_arithmetics, multiply_colors)
{
	t_color c1 = color(0.2, 0.3, 0.4);
	double scalar = 2.0;
	t_color c2 = multiply_color_by_scalar(&c1, scalar);
	t_color benchmark1 = color(0.4, 0.6, 0.8);

	cr_assert(are_equal_colors(&c2, &benchmark1), "The multiplication by scalar function is not correct");


	t_color c3 = color(1, 0.2, 0.4);
	t_color c4 = color(0.9, 1, 0.1);
	t_color c5 = multiply_colors(&c3, &c4);
	t_color c6 = color(0.9, 0.2, 0.04);

	cr_assert(are_equal_colors(&c5, &c6), "The multiplication function is not correct");
}


