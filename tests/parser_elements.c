/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:14:28 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/06 18:17:31 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

Test(parser, get_number_elements)
{
	int		nb;
	char	*str;
	
	str = "";
	cr_assert(get_elements(str, &nb) == NULL, "string is empty" );
	
	nb = 99;
	str = "A 0.2 255,255,255\nC -50,0,20 0,0,0 70\nL -40,0,30 0.7 255,255,255\npl 0,0,0 0,1.0,0 255,0,225\nsp 0,0,20 20 255,0,0\ncy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255";
	cr_assert(get_elements(str, &nb) != NULL, "6 elements basic");
	cr_assert(nb == 6);	

	nb = 99;
	str = "\nA 0.2 255,255,255\nC -50,0,20 0,0,0 70\nL -40,0,30 0.7 255,255,255\npl 0,0,0 0,1.0,0 255,0,225\nsp 0,0,20 20 255,0,0\ncy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255";
	cr_assert(get_elements(str, &nb) != NULL, "6 elements NL_start");
	cr_assert(nb == 6);	
	nb = 99;
	str = "\n\n\nA 0.2 255,255,255\nC -50,0,20 0,0,0 70\nL -40,0,30 0.7 255,255,255\npl 0,0,0 0,1.0,0 255,0,225\nsp 0,0,20 20 255,0,0\ncy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255";
	cr_assert(get_elements(str, &nb) != NULL, "6 elements 2xNL_start");
	cr_assert(nb == 6);	

	nb = 99;
	str = "A 0.2 255,255,255\nC -50,0,20 0,0,0 70\nL -40,0,30 0.7 255,255,255\npl 0,0,0 0,1.0,0 255,0,225\nsp 0,0,20 20 255,0,0\ncy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255\n";
	cr_assert(get_elements(str, &nb) != NULL, "6 elements NL_end");
	cr_assert(nb == 6);	
	nb = 99;
	str = "A 0.2 255,255,255\nC -50,0,20 0,0,0 70\nL -40,0,30 0.7 255,255,255\npl 0,0,0 0,1.0,0 255,0,225\nsp 0,0,20 20 255,0,0\ncy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255\n\n";
	cr_assert(get_elements(str, &nb) != NULL, "6 elements 2xNL_end");
	cr_assert(nb == 6);	

	nb = 99;
	str = "A 0.2 255,255,255\n\n\nC -50,0,20 0,0,0 70\nL -40,0,30 0.7 255,255,255\n\npl 0,0,0 0,1.0,0 255,0,225\nsp 0,0,20 20 255,0,0\ncy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255";
	cr_assert(get_elements(str, &nb) != NULL, "6 elements NL_between_lines");
	cr_assert(nb == 6);
}

static bool	are_equal_elt_camera(t_element *c1, t_element *c2)
{
	if (!are_equal_tuples(&c1->coordinates, &c2->coordinates))
		return (false);
	if (!are_equal_tuples(&c1->orientation, &c2->orientation))
		return (false);
	if (!are_equal_doubles(c1->fov, c2->fov))
		return (false);
	return (true);
}

static bool	are_equal_elt_lightnings(t_element *l1, t_element *l2)
{
	if (!are_equal_doubles(l1->ambient_lightning_ratio, \
		l2->ambient_lightning_ratio))
		return (false);
	if (!are_equal_colors(&l1->color, &l2->color))
		return (false);
	return (true);
}

static bool	are_equal_elt_lights(t_element *l1, t_element *l2)
{
	if (!are_equal_tuples(&l1->coordinates, &l2->coordinates))
		return (false);
	if (!are_equal_colors(&l1->color, &l2->color))
		return (false);
	return (true);
}

static bool	are_equal_elt_spheres(t_element *sp1, t_element *sp2)
{
	if (!are_equal_tuples(&sp1->coordinates, &sp2->coordinates))
		return (false);
	if (!are_equal_doubles(sp1->radius, sp2->radius))
		return (false);
	if (!are_equal_colors(&sp1->color, &sp2->color))
		return (false);
	return (true);
}
static bool	are_equal_elements(t_element *elmt1, t_element *elmt2)
{
	if (elmt1->element_type == ELMT_SPHERE && elmt2->element_type == ELMT_SPHERE)
		return (are_equal_elt_spheres(elmt1, elmt2));
	if (elmt1->element_type == ELMT_CAMERA && elmt2->element_type == ELMT_CAMERA)
		return (are_equal_elt_camera(elmt1, elmt2));
	if (elmt1->element_type == ELMT_LIGHT && elmt2->element_type == ELMT_LIGHT)
		return (are_equal_elt_lights(elmt1, elmt2));
	if (elmt1->element_type == ELMT_AMBIENT && elmt2->element_type == ELMT_AMBIENT)
		return (are_equal_elt_lightnings(elmt1, elmt2));	
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
	index = 0;
	ft_bzero(&sh_parser, sizeof(t_element));
	parse_sphere(str, &index, &sh_parser);
	cr_assert(are_equal_elements(&sh_parser, &sh_control));
	cr_assert(index = ft_strlen(str));

	str = "sp            0.0,0.0,20.6 12.6 10,0,255";
	index = 0;
	ft_bzero(&sh_parser, sizeof(t_element));
	parse_sphere(str, &index, &sh_parser);
	cr_assert(are_equal_elements(&sh_parser, &sh_control));
	cr_assert(index = ft_strlen(str));
	
	str = "sp 0.0,0.0,20.6       12.6 10,0,255";
	index = 0;
	ft_bzero(&sh_parser, sizeof(t_element));
	parse_sphere(str, &index, &sh_parser);
	cr_assert(are_equal_elements(&sh_parser, &sh_control));
	cr_assert(index = ft_strlen(str));

	str = "sp 0.0,0.0,20.6 12.6      10,0,255";
	index = 0;
	ft_bzero(&sh_parser, sizeof(t_element));
	parse_sphere(str, &index, &sh_parser);
	cr_assert(are_equal_elements(&sh_parser, &sh_control));
	cr_assert(index = ft_strlen(str));
	
	str = "sp 0.0,0.0,20.6 12.6 10,0,255        ";
	index = 0;
	ft_bzero(&sh_parser, sizeof(t_element));
	parse_sphere(str, &index, &sh_parser);
	cr_assert(are_equal_elements(&sh_parser, &sh_control));
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
	index = 0;
	ft_bzero(&sh_parser, sizeof(t_element));
	parse_light(str, &index, &sh_parser);
	cr_assert(are_equal_elements(&sh_parser, &sh_control));
	cr_assert(index = ft_strlen(str));

	str = "L            -40.0,50.0,0.0 0.6 255,255,255";
	index = 0;
	ft_bzero(&sh_parser, sizeof(t_element));
	parse_light(str, &index, &sh_parser);
	cr_assert(are_equal_elements(&sh_parser, &sh_control));
	cr_assert(index = ft_strlen(str));

	str = "L -40.0,50.0,0.0             0.6 255,255,255";
	index = 0;
	ft_bzero(&sh_parser, sizeof(t_element));
	parse_light(str, &index, &sh_parser);
	cr_assert(are_equal_elements(&sh_parser, &sh_control));
	cr_assert(index = ft_strlen(str));

	str = "L -40.0,50.0,0.0 0.6           255,255,255";
	index = 0;
	ft_bzero(&sh_parser, sizeof(t_element));
	parse_light(str, &index, &sh_parser);
	cr_assert(are_equal_elements(&sh_parser, &sh_control));
	cr_assert(index = ft_strlen(str));
	
	str = "L -40.0,50.0,0.0 0.6 255,255,255           ";
	index = 0;
	ft_bzero(&sh_parser, sizeof(t_element));
	parse_light(str, &index, &sh_parser);
	cr_assert(are_equal_elements(&sh_parser, &sh_control));
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
	index = 0;
	ft_bzero(&sh_parser, sizeof(t_element));
	parse_ambient(str, &index, &sh_parser);
	cr_assert(are_equal_elements(&sh_parser, &sh_control));
	cr_assert(index = ft_strlen(str));

	str = "A             0.2 255,255,255";
	index = 0;
	ft_bzero(&sh_parser, sizeof(t_element));
	parse_ambient(str, &index, &sh_parser);
	cr_assert(are_equal_elements(&sh_parser, &sh_control));
	cr_assert(index = ft_strlen(str));
	
	str = "A 0.2                  255,255,255";
	index = 0;
	ft_bzero(&sh_parser, sizeof(t_element));
	parse_ambient(str, &index, &sh_parser);
	cr_assert(are_equal_elements(&sh_parser, &sh_control));
	cr_assert(index = ft_strlen(str));
	
	str = "A 0.2 255,255,255          ";
	index = 0;
	ft_bzero(&sh_parser, sizeof(t_element));
	parse_ambient(str, &index, &sh_parser);
	cr_assert(are_equal_elements(&sh_parser, &sh_control));
	cr_assert(index = ft_strlen(str));
}

Test(parser, parse_camera_exemple_subject)
{
	t_element	cam_parser;
	t_element	cam_control;
	int			index;
	char		*str;
		
	ft_bzero(&cam_control, sizeof(t_element));
	cam_control.element_type = ELMT_CAMERA;
	cam_control.coordinates = point(-50.0, 0.0, 20.0);
	cam_control.orientation = vector(0.0, 0.0, 1.0);
	cam_control.fov = 70;
	
	str = "C -50.0,0,20 0,0,1 70";
	index = 0;
	ft_bzero(&cam_parser, sizeof(t_element));
	parse_camera(str, &index, &cam_parser);
	cr_assert(are_equal_elements(&cam_parser, &cam_control));
	cr_assert(index = ft_strlen(str));

	str = "C           -50.0,0,20 0,0,1 70";
	index = 0;
	ft_bzero(&cam_parser, sizeof(t_element));
	parse_camera(str, &index, &cam_parser);
	cr_assert(are_equal_elements(&cam_parser, &cam_control));
	cr_assert(index = ft_strlen(str));

	str = "C -50.0,0,20          0,0,1 70";
	index = 0;
	ft_bzero(&cam_parser, sizeof(t_element));
	parse_camera(str, &index, &cam_parser);
	cr_assert(are_equal_elements(&cam_parser, &cam_control));
	cr_assert(index = ft_strlen(str));

	str = "C -50.0,0,20 0,0,1            70";
	index = 0;
	ft_bzero(&cam_parser, sizeof(t_element));
	parse_camera(str, &index, &cam_parser);
	cr_assert(are_equal_elements(&cam_parser, &cam_control));
	cr_assert(index = ft_strlen(str));

	str = "C -50.0,0,20 0,0,1 70             ";
	index = 0;
	ft_bzero(&cam_parser, sizeof(t_element));
	parse_camera(str, &index, &cam_parser);
	cr_assert(are_equal_elements(&cam_parser, &cam_control));
	cr_assert(index = ft_strlen(str));
}