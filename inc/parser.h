/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:41:27 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/22 13:50:00 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

# include "colors.h"
# include "shapes.h"
# include "world.h"
# include "camera.h"
# include "errors.h"

typedef enum e_shape_type	t_shape_type;

typedef enum e_element_type
{
	ELMT_CAMERA	,
	ELMT_AMBIENT,
	ELMT_LIGHT,
	ELMT_SPHERE,
	ELMT_PLANE,
	ELMT_CYLINDER,
}	t_element_type;

typedef struct s_element
{
	t_element_type	element_type;
	t_tuple			coordinates;
	t_tuple			orientation;
	t_color			color;
	double			radius;
	double			ambient_lightning_ratio;
	t_color			light_intensity;
	double			cylinder_height;
	double			fov;
}	t_element;

/*
** ------------------------------- PARSER__ -----------------------------------
*/

int			parse_color(char *file_string, int *index, t_color *color);
int			parse_double(char *file_string, int *index, double *result);
int			parse_coordinates(char *file_string,
				int *index, t_element *element);
int			parse_orientation(char *file_string,
				int *index, t_element *element);

/*
** ------------------------------- PARSER_ ------------------------------------
*/

int			parse_ambient(char *file_string, int *index, t_element *element);
int			parse_camera(char *file_string, int *index, t_element *element);
int			parse_light(char *file_string, int *index, t_element *element);
int			parse_sphere(char *file_string, int *index, t_element *element);
int			parse_plane(char *file_string, int *index, t_element *element);
int			parse_cylinder(char *file_string, int *index, t_element *element);

/*
** ------------------------------- PARSER -------------------------------------
*/
t_element	*count_elements(char *file_string, int *nb);
int			parser(char *filename, t_scene *scene);

/*
** ------------------------------- GET ELEMENTS -------------------------------
*/

int			get_elements(char *file_string, int *nb_elmts, t_element *elmts);

/*
** ------------------------------- PUT FILE INTO STRING------------------------
*/

int			open_file(char *filename);
char		*put_file_into_string(char *filename, int *ret);

/*
** ------------------------------- PUT ELEMENTS INTRO FINAL STRUCT-------------
*/

void		put_elements_into_camera(t_element *element, t_camera *cam);
void		put_elements_into_lightning(t_element *element,
				int index, t_world *w);
void		put_elements_into_shapes(t_element *element, int index, t_world *w);

#endif