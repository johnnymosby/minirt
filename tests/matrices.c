/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:19:33 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/09/13 15:23:52 by rbasyrov         ###   ########.fr       */
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
