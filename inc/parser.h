/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguilmea <aguilmea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:41:27 by aguilmea          #+#    #+#             */
/*   Updated: 2023/10/13 12:36:09 by aguilmea         ###   ########.fr       */
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

# define VALUE_IS_NOT_A_DIGIT -1
# define MISSING_COMMA -2
# define MISSING_SPACE -3
# define VALUE_FOV_WRONG -4
# define VALUE_LIGHTNING_RATIO_WRONG -5
# define VALUE_COLOR_WRONG -6
# define VALUE_RADIUS_WRONG -7
# define ERR_MALLOC -8
# define NUMBER_MANDATORY_ELEMENTS_WRONG -9
# define IDENTIFIER_ELEMENT_WRONG -11
# define ERROR_OPEN_FILE -10
# define NAME_FILE_WRONG -11

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

typedef struct s_element		// has to be modified when t_shape and t_material are final:
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
** ------------------------------- PARSER ------------------------------------
*/

t_element	*get_elements(char *file_string, int *nb_elmts);
char 		*put_file_into_string(char *filename);
int			open_file(char *filename);
int		 	parse_double(char *file_string, int *index, double *result);
int			parse_color(char *file_string, int *index, t_color *color);
int			parse_coordinates(char *file_string, int *index, t_element *element);
int			parse_orientation(char *file_string, int *index, t_element *element);
int			parse_ambient(char *file_string, int *index, t_element *element);
int			parse_camera(char *file_string, int *index, t_element *element);
int			parse_light(char *file_string, int *index, t_element *element);
int			parse_sphere(char *file_string, int *index, t_element *element);
int			parse_plane(char *file_string, int *index, t_element *element);
int			parse_cylinder(char *file_string, int *index, t_element *element);
void		put_elements_into_camera(t_element *element, t_camera *cam);
void		put_elements_into_lightning(t_element *element, int index, t_world *w);
void		put_elements_into_shapes(t_element *element, int index, t_world *w);
void		*print_error_parsing(int err_code);
bool		parser(char *filename, t_world *w, t_camera *cam);

#endif