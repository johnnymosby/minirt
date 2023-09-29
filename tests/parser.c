/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:14:28 by aguilmea          #+#    #+#             */
/*   Updated: 2023/09/29 22:50:37 by aguilmea         ###   ########.fr       */
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

static bool	are_equal_lightning(t_element *l1, t_element *l2)
{
	if (!are_equal_doubles(l1->ambient_lightning_ratio, \
		l2->ambient_lightning_ratio))
		return (false);
	if (!are_equal_colors(&l1->color, &l2->color))
		return (false);
	return (true);
}

static bool	are_equal_lights(t_element *l1, t_element *l2)
{
	if (!are_equal_tuples(&l1->coordinates, &l2->coordinates))
		return (false);
	if (!are_equal_colors(&l1->light_intensity, &l2->light_intensity))
		return (false);
	return (true);
}

static bool	are_equal_spheres(t_element *sp1, t_element *sp2)
{
	if (!are_equal_tuples(&sp1->coordinates, &sp2->coordinates))
		return (false);
	if (sp1->radius != sp2->radius)
		return (false);
	if (!are_equal_colors(&sp1->color, &sp2->color))
		return (false);
	return (true);
}
static bool	are_equal_shapes(t_element *elmt1, t_element *elmt2)
{
	if (elmt1->element_type == ELMT_SPHERE && elmt2->element_type == ELMT_SPHERE)
		return (are_equal_spheres(elmt1, elmt2));
	if (elmt1->element_type == ELMT_LIGHT && elmt2->element_type == ELMT_LIGHT)
		return (are_equal_lights(elmt1, elmt2));
	if (elmt1->element_type == ELMT_AMBIENT && elmt2->element_type == ELMT_AMBIENT)
		return (are_equal_lightning(elmt1, elmt2));	
	return (false);
}

Test(parser, parse_sphere_exemple_subject)
{
	t_element	sh_parser;
	t_element	sh_control;
	int			index;
	char		*str;
	
	ft_bzero(&sh_control, sizeof(t_element));
	sh_control.coordinates = point(0,0,20.6);
	sh_control.radius = 12.6 / 2;
	sh_control.element_type = ELMT_SPHERE;
	sh_control.color = color(10.0/255,0,1);
	
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

Test(parser, parse_light_exemple_subject)
{
	t_element	sh_parser;
	t_element	sh_control;
	int			index;
	char		*str;
		
	ft_bzero(&sh_control, sizeof(t_element));
	sh_control.element_type = ELMT_LIGHT;
	sh_control.coordinates = point(-40.0,50.0,0.0);
	sh_control.light_intensity = color(0.6, 0.6, 0.6);
	
	
	str = "L -40.0,50.0,0.0 0.6 255,255,255";
	index = 2;
	ft_bzero(&sh_parser, sizeof(t_element));
	parse_light(str, &index, &sh_parser);
	cr_assert(are_equal_shapes(&sh_parser, &sh_control));
	cr_assert(index = ft_strlen(str));

	str = "L            -40.0,50.0,0.0 0.6 255,255,255";
	index = 2;
	ft_bzero(&sh_parser, sizeof(t_element));
	parse_light(str, &index, &sh_parser);
	cr_assert(are_equal_shapes(&sh_parser, &sh_control));
	cr_assert(index = ft_strlen(str));

	str = "L -40.0,50.0,0.0             0.6 255,255,255";
	index = 2;
	ft_bzero(&sh_parser, sizeof(t_element));
	parse_light(str, &index, &sh_parser);
	cr_assert(are_equal_shapes(&sh_parser, &sh_control));
	cr_assert(index = ft_strlen(str));

	str = "L -40.0,50.0,0.0 0.6           255,255,255";
	index = 2;
	ft_bzero(&sh_parser, sizeof(t_element));
	parse_light(str, &index, &sh_parser);
	cr_assert(are_equal_shapes(&sh_parser, &sh_control));
	cr_assert(index = ft_strlen(str));
	
	str = "L -40.0,50.0,0.0 0.6 255,255,255           ";
	index = 2;
	ft_bzero(&sh_parser, sizeof(t_element));
	parse_light(str, &index, &sh_parser);
	cr_assert(are_equal_shapes(&sh_parser, &sh_control));
	cr_assert(index = ft_strlen(str));
}

Test(parser, parse_ambient_exemple_subject)
{
	t_element	sh_parser;
	t_element	sh_control;
	int			index;
	char		*str;
		
	ft_bzero(&sh_control, sizeof(t_element));
	sh_control.element_type = ELMT_AMBIENT;
	sh_control.ambient_lightning_ratio = 0.2;
	sh_control.color = color (1,1,1);
	
	str = "A 0.2 255,255,255";
	index = 2;
	ft_bzero(&sh_parser, sizeof(t_element));
	parse_ambient(str, &index, &sh_parser);
	cr_assert(are_equal_shapes(&sh_parser, &sh_control));
	cr_assert(index = ft_strlen(str));

	str = "A             0.2 255,255,255";
	index = 2;
	ft_bzero(&sh_parser, sizeof(t_element));
	parse_ambient(str, &index, &sh_parser);
	cr_assert(are_equal_shapes(&sh_parser, &sh_control));
	cr_assert(index = ft_strlen(str));
	
	str = "A 0.2                  255,255,255";
	index = 2;
	ft_bzero(&sh_parser, sizeof(t_element));
	parse_ambient(str, &index, &sh_parser);
	cr_assert(are_equal_shapes(&sh_parser, &sh_control));
	cr_assert(index = ft_strlen(str));
	
	str = "A 0.2 255,255,255          ";
	index = 2;
	ft_bzero(&sh_parser, sizeof(t_element));
	parse_ambient(str, &index, &sh_parser);
	cr_assert(are_equal_shapes(&sh_parser, &sh_control));
	cr_assert(index = ft_strlen(str));
}
/*
Test(parser, parse_camera_exemple_subject)
{
	t_element	cam_parser;
	t_element	cam_control;
	int			index;
	char		*str;
		
	ft_bzero(&cam_control, sizeof(t_element));
	cam_control.element_type = ELMT_CAMERA;
	cam_control.coordinates = point(-50.0, 0.0, 20.0);
	cam_control.camera_orientation = vector(0.0, 0.0, 1.0);
	cam_control.fov_in_rad = 70;
	
	str = "C -50.0,0,20 0,0,1 70";
	index = 2;
	ft_bzero(&cam_parser, sizeof(t_element));
	parse_camera(str, &index, &cam_parser);
	cr_assert(are_equal_shapes(&cam_parser, &cam_control));
	cr_assert(index = ft_strlen(str));
}*/