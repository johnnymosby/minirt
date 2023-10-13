/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:41:27 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/13 19:25:06 by aguilmea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <fcntl.h> // open
# include <unistd.h> // read
# include <stdio.h> // NULL macro
# include "libft.h"

# include "colors.h"
# include "shapes.h"
# include "world.h"
# include "camera.h"

# define ERR_OPEN_FILE -1
# define ERR_NAME_FILE_WRONG -2
# define ERR_NB_MANDATORY_ELMTS -3
# define ERR_IDENTIFIER_ELEMENT_WRONG -4
# define ERR_MALLOC -5
# define ERR_VALUE_IS_NOT_A_DIGIT -6
# define ERR_MISSING_COMMA -7
# define ERR_MISSING_SPACE -8
# define ERR_VALUE_FOV_WRONG -9
# define ERR_VALUE_LIGHTNING_RATIO_WRONG -10
# define ERR_VALUE_COLOR_WRONG -11
# define ERR_VALUE_DIAMETER_NEGATIV -12
# define ERR_VALUE_HEIGHT_NEGATIV -13
# define ERR_VALUE_BRIGHTNESS_LIGHT -14
# define ERR_VALUE_NORM_VECTOR -14

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
int			parse_coordinates(char *file_string, \
					int *index, t_element *element);
int			parse_orientation(char *file_string, \
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

bool		parser(char *filename, t_world *w, t_camera *cam);

/*
** ------------------------------- PARSER PRINT_ERRORS-------------------------
*/

void		*print_error_parsing(char *file_string, int index, int err_code);

/*
** ------------------------------- GET ELEMENTS -------------------------------
*/

t_element	*get_elements(char *file_string, int *nb_elmts);

/*
** ------------------------------- PUT FILE INTO STRING------------------------
*/

char		*put_file_into_string(char *filename);

/*
** ------------------------------- PUT ELEMENTS INTRO FINAL STRUCT-------------
*/

void		put_elements_into_camera(t_element *element, t_camera *cam);
void		put_elements_into_lightning(t_element *element, \
					int index, t_world *w);
void		put_elements_into_shapes(t_element *element, int index, t_world *w);

#endif