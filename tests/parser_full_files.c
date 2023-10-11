/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_full_files.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:14:28 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/11 18:45:25 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

Test(parser, full_files_subject)
{
	t_world		w;
	t_camera	c;
	bool		ret;

	ret = parser("../testfiles/full_files/subject_only_one_sphere.rt", &w, &c);
	cr_assert(ret == true);
	if (w.lightning.material)
		free(w.lightning.material);
	if (w.lights)
		free(w.lights);
	if (w.shape)
		free(w.shape);

	ft_bzero(&w, sizeof(t_world));
	cr_assert(parser("../testfiles/full_files/subject_only_one_cylinder.rt", &w, &c) == true);
	if (w.lightning.material)
		free(w.lightning.material);
	if (w.lights)
		free(w.lights);
	if (w.shape)
		free(w.shape);

	ft_bzero(&w, sizeof(t_world));
	cr_assert(parser("../testfiles/full_files/subject_only_one_plane.rt", &w, &c) == true);
	if (w.lightning.material)
		free(w.lightning.material);
	if (w.lights)
		free(w.lights);
	if (w.shape)
		free(w.shape);

	ft_bzero(&w, sizeof(t_world));
	cr_assert(parser("../testfiles/full_files/subject.rt", &w, &c) == true);
	if (w.lightning.material)
		free(w.lightning.material);
	if (w.lights)
		free(w.lights);
	if (w.shape)
		free(w.shape);
}