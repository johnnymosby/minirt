/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:14:28 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/22 22:41:49 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

Test(parser, open_file)
{
	cr_assert(open_file(NULL) == -1, "the filename is NULL" );
	cr_assert(open_file("" ) == -1, "the filename is empty");
	cr_assert(open_file("../testfiles/open_file/wrongsufix1" ) == -1, "wrong suffix 1");
	cr_assert(open_file("../testfiles/open_file/wrongsufix2.rtt" ) == -1, "wrong suffix 2");
	cr_assert(open_file("../testfiles/open_file/wrongsufix3.r" ) == -1, "wrong suffix 3");
	cr_assert(open_file("../testfiles/directory.rt") == -1, "the file is a directory");
	cr_assert(open_file("../testfiles/open_file/doesnotexist.rt") == -1, "the file does not exist");
	cr_assert(open_file("../testfiles/open_file/file_okay.rt") > 0,"the file has 6elements");
}
/*
Test(parser, get_number_elements)
{
	cr_assert(get_number_elements(NULL) == 0, "the filename is NULL" );
	cr_assert(get_number_elements("" ) == 0, "the filename is empty");
	cr_assert(get_number_elements("../testfiles/directory.rt") == 0, "the file is a directory");
	cr_assert(get_number_elements("../testfiles/get_number_elements/6elmts_basic_noNL_start_end.rt") == 6);
	cr_assert(get_number_elements("../testfiles/get_number_elements/6elmts_NL_start.rt") == 6);
	cr_assert(get_number_elements("../testfiles/get_number_elements/6elmts_NL_end.rt") == 6);
	cr_assert(get_number_elements("../testfiles/get_number_elements/6elmts_NL_between_elmts.rt") == 6);
}*/
static bool	are_equal_spheres(t_element *sp1, t_element *sp2)
{
	if (!are_equal_tuples(&(sp1->sphere.origin), &(sp2->sphere.origin)))
		return (false);
	if (sp1->sphere.radius != sp2->sphere.radius)
		return (false);
	if (!are_equal_colors(&(sp1->material.color), &(sp2->material.color)))
		return (false);
	return (true);
}
static bool	are_equal_shapes(t_element *sp1, t_element *sp2)
{
	if (sp1->element_type == SPHERE && sp2->element_type == SPHERE)
		return (are_equal_spheres(sp1, sp2));
	return (false);
}

Test(parser, parse_sphere_exemple_subject)
{
	t_element	sh_parser;
	t_element	sh_control;
	int			index;
	char		*str;
	
	ft_bzero(&sh_control, sizeof(t_element));
	sh_control.sphere.origin = point(0,0,20.6);
	sh_control.sphere.radius = 12.6 / 2;
	sh_control.element_type = SPHERE;
	sh_control.material.color = color(10.0/255,0,1);
	
	str = "sp 0.0,0.0,20.6 12.6 10,0,255";
	index = 3;
	ft_bzero(&sh_parser, sizeof(t_element));
	parse_sphere(str, &index, &sh_parser);
	cr_assert(are_equal_shapes(&sh_parser, &sh_control));
	cr_assert(index = ft_strlen(str));

	str = "sp            0.0,0.0,20.6 12.6 10,0,255";
	index = 3;
	ft_bzero(&sh_parser, sizeof(t_element));
	parse_sphere(str, &index, &sh_parser);
	cr_assert(are_equal_shapes(&sh_parser, &sh_control));
	cr_assert(index = ft_strlen(str));
	
	str = "sp 0.0,0.0,20.6       12.6 10,0,255";
	index = 3;
	ft_bzero(&sh_parser, sizeof(t_element));
	parse_sphere(str, &index, &sh_parser);
	cr_assert(are_equal_shapes(&sh_parser, &sh_control));
	cr_assert(index = ft_strlen(str));

	str = "sp 0.0,0.0,20.6 12.6      10,0,255";
	index = 3;
	ft_bzero(&sh_parser, sizeof(t_element));
	parse_sphere(str, &index, &sh_parser);
	cr_assert(are_equal_shapes(&sh_parser, &sh_control));
	cr_assert(index = ft_strlen(str));
	
	str = "sp 0.0,0.0,20.6 12.6 10,0,255        ";
	index = 3;
	ft_bzero(&sh_parser, sizeof(t_element));
	parse_sphere(str, &index, &sh_parser);
	cr_assert(are_equal_shapes(&sh_parser, &sh_control));
	cr_assert(index = ft_strlen(str));
}
