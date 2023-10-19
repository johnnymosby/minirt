/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_full_files.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:14:28 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/19 11:30:32 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

Test(parser, full_files_subject)
{
	t_scene		scene;
	t_world		w;
	t_canvas	canvas;
	bool		ret;

	scene.canvas = &canvas;
	scene.world = &w;

	ret = parser("../testfiles/full_files/subject_only_one_sphere.rt", &scene);
	cr_assert(ret == 0);
	if (w.lightning.material)
		free(w.lightning.material);
	if (w.lights)
		free(w.lights);
	if (w.shape)
		free(w.shape);

	ret = parser("../testfiles/full_files/subject_only_one_cylinder.rt", &scene);
	cr_assert(ret == 0);
	if (w.lightning.material)
		free(w.lightning.material);
	if (w.lights)
		free(w.lights);
	if (w.shape)
		free(w.shape);

	ret = parser("../testfiles/full_files/subject_only_one_plane.rt", &scene);
	cr_assert(ret == 0);
	if (w.lightning.material)
		free(w.lightning.material);
	if (w.lights)
		free(w.lights);
	if (w.shape)
		free(w.shape);

	ret = parser("../testfiles/full_files/subject.rt", &scene);
	cr_assert(ret == 0);
	if (w.lightning.material)
		free(w.lightning.material);
	if (w.lights)
		free(w.lights);
	if (w.shape)
		free(w.shape);
}