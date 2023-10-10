/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_full_files.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:14:28 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/10 17:00:20 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

Test(parser, full_files)
{
	t_world		w[1];
	t_camera	c[1];

	cr_assert(parser("../testfiles/full_files/subject_only_one_sphere.rt", w, c) == true);
	cr_assert(parser("../testfiles/full_files/subject_only_one_cylinder.rt", w, c) == true);
	cr_assert(parser("../testfiles/full_files/subject_only_one_plane.rt", w, c) == true);
	//cr_assert(parser("../testfiles/full_files/subject.rt", w, c) == true);
	//cr_assert(parser("filename", w, c) == true);

}